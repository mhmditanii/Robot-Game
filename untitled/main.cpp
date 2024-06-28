//
// Created by mhmd on 6/28/24.
//
//
// Created by mhmd on 5/19/24.
//
#include<iostream>
#include<memory>
#include"BattleGround.h"
#include"Data_structures/svector.h"
#include"Data_structures/svector_robot_ptr.h"
#include"utilities/filehandler.h"
#include<unordered_map>
using namespace std;

const unordered_map<string, int> nameTypeToId = {
        {"bluethunder", 10},
        {"robocop", 20},
        {"terminator", 30},
        {"madbot", 40},
        {"robotank", 50},
        {"terminatorrobocop", 60}
};

int parceType(string &x) {
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        auto it = nameTypeToId.find(x);

        if (it != nameTypeToId.end()) {
                return it->second;
        } else {
                assert(false && "FAULTY id passed to parcType main");
                return -1; //for compiler reasons
        }
}

BattleGround* readFileAndInitData() {
        BattleGround* ptr;
        try {
                filehandler rd("details.txt");
                ptr = new BattleGround(rd.Mrow,rd.Ncol,rd.steps);
                int size = rd.robotsNumber;
                int id;
                optional<pair<size_t,size_t>> loc;
                string name;

                for(int i = 0 ; i < size ; i++) {
                        id = parceType(rd.typeNames[i]);
                        loc = rd.locations[i];
                        name = rd.names[i];
                        cout << name << "  " << id << endl;
                        //If location is not random the following init is used(loc is not nullopt)
                        if(loc != nullopt) {
                                ptr->robotInit(id,name,loc->first,loc->second,true);
                        }
                        else {
                                //Generate random position and then init
                                loc = ptr->getRandomPosition();
                                ptr->robotInit(id,name,loc->first,loc->second,false);
                        }
                }
        } catch (const exception& e) {
                std::cerr << e.what() << "\n";
        }
        if(ptr==nullptr) {
                cerr << "Coudln't initialize battleground";
        }
        return ptr;
}


int main() {

        BattleGround* gameBG = readFileAndInitData();

        //Start the game

        gameBG->gameHandler();

        return 0;
}