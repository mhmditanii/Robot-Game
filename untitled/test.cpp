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
        BattleGround* r = new BattleGround(3,3,100);
        // shared_ptr<ShootingRobot> temp = make_shared<BlueThunder>(10,"ahmad",3,3);
        r->robotInit(20,"ahmad",0,0);
         r->robotInit(20,"ahmad",1,0);
         r->robotInit(20,"ahmad",2,2);
        r->robotInit(20,"ahmad",2,1);
        r->print();
        // r->robotExecute(1,1);
        // r->robotExecute(1,1);
        // r->robotExecute(1,1);

        r->robotEnqueue(0,0);
        cout << endl << endl;
        r->print();
        r->robotDequeue();
        cout << endl << endl;
        r->print();




        return 0;
}