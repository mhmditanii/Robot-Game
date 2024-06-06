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
        BattleGround* r = new BattleGround(5,5,100);
        // shared_ptr<ShootingRobot> temp = make_shared<BlueThunder>(10,"ahmad",3,3);
        r->robotInit(20,"ahmad",1,1);
        r->robotInit(20,"player 3",1,0);
        r->robotInit(20,"player 4",2,1);
        r->robotInit(20,"player 5",3,1);
        r->robotInit(20,"player 6",3,3);
        r->robotInit(20,"player 7",3,2);
        r->robotInit(20,"player 8",3,4);
        r->robotInit(20,"player 9",4,4);
        r->robotInit(20,"player 10",2,4);
        r->print();
        cout << endl << endl;
        cout <<"MOVE 1" << endl;
        r->robotExecute(1,1);
        r->robotExecute(1,1);
        r->robotExecute(1,1);
        r->robotExecute(1,1);

        r->print();

        // cout << endl <<"MOVE" << endl;
        // r->robotExecute(1,0);
        // r->print();
        //
        // cout << endl <<"MOVE" << endl;
        // r->robotExecute(2,1);
        // r->print();
        //
        // cout << endl <<"MOVE" << endl;
        // r->robotExecute(3,1);
        // r->print();
        //
        // cout << endl <<"MOVE" << endl;
        // r->robotExecute(3,3);
        // r->print();




        return 0;
}