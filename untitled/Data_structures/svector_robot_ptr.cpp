//
// Created by mhmd on 5/29/24.
//

#include "svector_robot_ptr.h"



template<typename T>
svector<T*>::svector(size_t const rows, size_t const columns, T* init)
    : rows(rows), columns(columns) {
    data = new T*[rows * columns];
    for (size_t i = 0; i < rows * columns; i++) {
        data[i] = init;
    }
}

template<typename T>
svector<T*>::~svector() {
    delete[] data;
}
template<typename T>
T* svector<T *>::getData(size_t const row, size_t const column) const {
    return data[row * columns + column];
}

template<typename T>
void svector<T *>::setData(size_t const row, size_t const column, T* const value){
    //if(!isInBounds(row,column)){assert(0 && "OUT OF BOUND SET VECTOR");}
    data[row * columns + column] = value;
}

template<typename T>
void svector<T*>::print() {
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if(data[i * columns + j] == nullptr)cout << "0";
            else cout << "1";
        }
        cout << endl;
    }
}

template<typename T>
bool svector<T *>::isInBounds(size_t row, size_t column) const {
        return row < rows && column < columns;
}


//**************************************************************************************
//             ********** MAIN ROBOTG CLASS SVECTOR ***********
//**************************************************************************************

svector<shared_ptr<MainRobot>>::svector(size_t const row, size_t const column) : BGrows(row), BGcolumns(column) {
    activeList = new LinkedList();
    waitQueue = new Queue();
    robots = std::shared_ptr<std::shared_ptr<MainRobot>[]>(new std::shared_ptr<MainRobot>[BGrows * BGcolumns]);
    for (size_t i = 0; i < BGrows * BGcolumns; i++) {
        robots[static_cast<int>(i)] = nullptr;
    }
}
svector<shared_ptr<MainRobot>>::~svector() {
    delete activeList;
    delete waitQueue;
}


//                 ***********SETTERS AND GETTERS****************

size_t svector<shared_ptr<MainRobot>>::getRows() const {
    return BGrows;
}

size_t svector<shared_ptr<MainRobot>>::getColumns() const {
    return BGcolumns;
}

shared_ptr<MainRobot> svector<shared_ptr<MainRobot>>::getRobot(size_t const row, size_t const column) const {
    if(!isInBounds(row,column)) assert(false && "ACCESSING OUT OF BOUDNS IN SVECTOR_robot_ptr getRobot() : ");
    const int temp = static_cast<int>(row * BGcolumns + column);
    return robots[temp];
}
void svector<shared_ptr<MainRobot>>::setRobot(size_t const row, size_t const column, shared_ptr<MainRobot> robot) {
    //Add to matrix
    const int temp = static_cast<int>(row * BGcolumns + column);
    robots[temp] = robot;
}

void svector<shared_ptr<MainRobot>>::setRobotToList(shared_ptr<MainRobot> robot) const{
    activeList->insertAtEnd(robot);
}



//                  *********** TESTING/CHECKING FUNCTIONS **************

void svector<shared_ptr<MainRobot>>::deleteData(size_t const row, size_t const column) {
    //Deletes from LinkedList before freeing the robot
    const int temp = static_cast<int>(row * BGcolumns + column);
    activeList->deleteValue(robots[temp]);
    robots[temp] = nullptr;
}

void svector<shared_ptr<MainRobot>>::deleteForMove(size_t const row, size_t const column) {
    //Deletes from LinkedList before freeing the robot
    const int temp = static_cast<int>(row * BGcolumns + column);
    robots[temp] = nullptr;
}

void svector<shared_ptr<MainRobot> >::enqueueData(size_t const row, size_t const column) const {
    const int temp = static_cast<int>(row * BGcolumns + column);
    waitQueue->enqueue(robots[temp]);
    activeList->deleteValue(robots[temp]);
    //Removing the robot from matrix after adding to queue
    robots[temp] = nullptr;
}

shared_ptr<MainRobot> svector<shared_ptr<MainRobot> >::dequeueData() const {
    //Checked in the Queue class
    return this->waitQueue->dequeue();
}


bool svector<shared_ptr<MainRobot>>::isInBounds(size_t const row, size_t const column) const {
    return row < BGrows && column < BGcolumns;
}

void svector<shared_ptr<MainRobot>>::moveData
(size_t const curRow, size_t const curCol, size_t const destRow, size_t const destCol) {
    const int temp = static_cast<int>(curRow * BGcolumns + curCol);
    cout << robots[temp]->getName() << " IS MOVING FROM (" << curRow
    << "," << curCol << ") TO (" << destRow << "," << destCol << ")" << endl;
    this->setRobot(destRow,destCol,this->getRobot(curRow,curCol));
    robots[temp]->updateLoc(make_pair(destRow,destCol));
    this->deleteForMove(curRow,curCol);

    if(getRobot(curRow,curCol) != nullptr || getRobot(destRow,destCol) == nullptr) {
        assert(false && "moveData in svector has an issue either with deleting the old loc or moving to new loc");
    }
}

pair<size_t, size_t> svector<shared_ptr<MainRobot> >::genRandPos() const {
    // Create a random number generator
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<size_t> rowDist(0, BGrows - 1);
    uniform_int_distribution<size_t> colDist(0, BGcolumns - 1);

    // Keep generating random positions until an empty one is found
    size_t row, col;
    do {
        row = rowDist(gen);
        col = colDist(gen);
    } while (this->getRobot(row,col) != nullptr);

    return make_pair(row, col);
}

bool svector<shared_ptr<MainRobot>>::endGame() const {
    //endGame = true -> game should end
    return (activeList->getSize() == 1 && waitQueue->isEmpty());
}

void svector<shared_ptr<MainRobot>>::print() const {
    for (size_t i = 0; i < BGrows; ++i) {
        for (size_t j = 0; j < BGcolumns; ++j) {
            if(this->getRobot(i,j) == nullptr) {
                cout << "0" << " : ";
            }
            else {
                cout << "1" << " : ";
            }
        }
        cout << endl;
    }
}