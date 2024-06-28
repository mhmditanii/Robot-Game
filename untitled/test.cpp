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




int main() {

        BattleGround* gameBG = new BattleGround(20,20,1000);

        gameBG->robotInit(50, "Alice", 0, 0, true);
        gameBG->robotInit(50, "Bob", 1, 1, true);
        gameBG->robotInit(50, "Charlie", 2, 2, true);
        gameBG->robotInit(50, "Diana", 3, 3, true);
        gameBG->robotInit(50, "Eve", 4, 4, true);
        gameBG->robotInit(50, "Frank", 5, 5, true);
        gameBG->robotInit(50, "Grace", 6, 6, true);
        gameBG->robotInit(50, "Hannah", 7, 7, true);
        gameBG->robotInit(50, "Ian", 8, 8, true);
        gameBG->robotInit(50, "Julia", 9, 9, true);
        gameBG->robotInit(50, "Kevin", 0, 9, true);
        gameBG->robotInit(50, "Lily", 1, 8, true);
        gameBG->robotInit(50, "Michael", 2, 7, true);
        gameBG->robotInit(50, "Nora", 3, 6, true);
        gameBG->robotInit(50, "Olivia", 4, 5, true);
        gameBG->robotInit(50, "Peter", 5, 4, true);
        gameBG->robotInit(50, "Quinn", 6, 3, true);
        gameBG->robotInit(50, "Rachel", 7, 2, true);
        gameBG->robotInit(50, "Samuel", 8, 1, true);
        gameBG->robotInit(50, "Tina", 9, 0, true);
        gameBG->robotInit(50, "Victor", 0, 1, true);
        gameBG->robotInit(50, "Wendy", 1, 2, true);
        gameBG->robotInit(50, "Xander", 2, 3, true);
        gameBG->robotInit(50, "Yara", 3, 4, true);
        gameBG->robotInit(50, "Zane", 4, 6, true);
        gameBG->robotInit(50, "Amy", 5, 7, true);
        gameBG->robotInit(50, "Ben", 6, 8, true);
        gameBG->robotInit(50, "Cathy", 7, 9, true);
        gameBG->robotInit(50, "David", 8, 0, true);
        gameBG->robotInit(50, "Emma", 9, 3, true);
        gameBG->robotInit(50, "Felix", 0, 4, true);
        gameBG->robotInit(50, "Gabriella", 1, 5, true);
        gameBG->robotInit(50, "Henry", 2, 6, true);
        gameBG->robotInit(50, "Ivy", 3, 7, true);
        gameBG->robotInit(50, "Jack", 4, 8, true);
        gameBG->robotInit(50, "Katie", 5, 9, true);
        gameBG->robotInit(50, "Leo", 6, 0, true);
        gameBG->robotInit(50, "Mia", 7, 1, true);
        gameBG->robotInit(50, "Noah", 8, 2, true);
        gameBG->robotInit(50, "Olive", 9, 4, true);




        gameBG->gameHandler();

        return 0;
}