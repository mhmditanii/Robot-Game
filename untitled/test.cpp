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
        r->robotInit(20,"ahmad",1,1);
        r->robotInit(20,"player 2",1,0);
        r->print();
        cout << endl << endl;
        cout <<"MOVE 1" << endl;
        r->robotExecute(1,1);
        r->print();

        cout << endl << endl <<"MOVE 2" << endl;
        r->robotExecute(1,0);
        r->print();




        return 0;
}