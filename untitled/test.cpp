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

#include "upgraded_robots_h/UltimateRobot.h"
using namespace std;




int main() {

        BattleGround* gameBG = new BattleGround(20,20,1000);

        // Initialize robots with ID 50
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

// Initialize robots with ID 60
gameBG->robotInit(60, "Paul", 10, 10, true);
gameBG->robotInit(60, "Quincy", 11, 11, true);
gameBG->robotInit(60, "Rob", 12, 12, true);
gameBG->robotInit(60, "Sophie", 13, 13, true);
gameBG->robotInit(60, "Tom", 14, 14, true);
gameBG->robotInit(60, "Uma", 15, 15, true);
gameBG->robotInit(60, "Vera", 16, 16, true);
gameBG->robotInit(60, "Will", 17, 17, true);
gameBG->robotInit(60, "Xenia", 18, 18, true);
gameBG->robotInit(60, "Yves", 19, 19, true);
gameBG->robotInit(60, "Zara", 10, 9, true);
gameBG->robotInit(60, "Aaron", 11, 8, true);
gameBG->robotInit(60, "Bella", 12, 7, true);
gameBG->robotInit(60, "Carlos", 13, 6, true);
gameBG->robotInit(60, "Derek", 14, 5, true);
gameBG->robotInit(60, "Elena", 15, 4, true);
gameBG->robotInit(60, "Finn", 16, 3, true);
gameBG->robotInit(60, "Gina", 17, 2, true);
gameBG->robotInit(60, "Hank", 18, 1, true);
gameBG->robotInit(60, "Iris", 19, 0, true);
gameBG->robotInit(60, "Jade", 10, 1, true);
gameBG->robotInit(60, "Kyle", 11, 2, true);
gameBG->robotInit(60, "Lana", 12, 3, true);
gameBG->robotInit(60, "Max", 13, 4, true);
gameBG->robotInit(60, "Nina", 14, 6, true);
gameBG->robotInit(60, "Omar", 15, 7, true);
gameBG->robotInit(60, "Piper", 16, 8, true);
gameBG->robotInit(60, "Quinn", 17, 9, true);
gameBG->robotInit(60, "Ruth", 18, 0, true);
gameBG->robotInit(60, "Sam", 19, 3, true);
gameBG->robotInit(60, "Tina", 10, 4, true);
gameBG->robotInit(60, "Ulysses", 11, 5, true);
gameBG->robotInit(60, "Violet", 12, 6, true);
gameBG->robotInit(60, "Wes", 13, 7, true);
gameBG->robotInit(60, "Xander", 14, 8, true);
gameBG->robotInit(60, "Yvette", 15, 9, true);
gameBG->robotInit(60, "Zack", 16, 0, true);





        gameBG->gameHandler();

        return 0;
}