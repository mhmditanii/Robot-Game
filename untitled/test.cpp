//
// Created by mhmd on 5/19/24.
//
#include<iostream>
#include<memory>
// #include"robots_h/MovingRobot.h"
// #include"robots_h/SteppingRobot.h"
// #include"robots_h/SeeingRobot.h"

#include"sub_robots_h/Robocop.h"
#include"sub_robots_h/BlueThunder.h"
#include"sub_robots_h/Terminator.h"


#include"BattleGround.h"
#include"Data_structures/svector.h"
#include"Data_structures/svector_robot_ptr.h"


int main() {
        BattleGround* r = new BattleGround(4,4,100);
        // shared_ptr<ShootingRobot> temp = make_shared<BlueThunder>(10,"ahmad",3,3);
        r->robotInit(10,"ahmad",2,0);
        r->robotInit(10,"player 2",1,0);
        shared_ptr<MainRobot> temp = r->getRobot(2,0);
        cout << "TRYING THE ATTACK " << endl;
        temp->executeTurn();
        cout<<"END OF ATTACK" << endl;

        cout << "DELETING ROBOT" << endl;
        r->robotDelete(1,0);
        cout << "DELETED THE ROBOT" << endl;
        return 0;
}