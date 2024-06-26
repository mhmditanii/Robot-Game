//
// Created by mhmd on 5/19/24.
//
#include<iostream>
#include<memory>
#include"BattleGround.h"
#include"Data_structures/svector.h"
#include"Data_structures/svector_robot_ptr.h"
using namespace std;


int main() {

        BattleGround* bg = new BattleGround(9,9,1000);
        bg->robotInit(30,"samir",1,1);

        shared_ptr<Terminator> x;

        TerminatorRoboCop y = std::move(*x);















        // //bg->robotInit(10,"ahmad",4,4);
        // shared_ptr<Terminator> x = dynamic_pointer_cast<Terminator>(bg->getRobot(1,1));
        // // shared_ptr<BlueThunder> blueThunderPtr = dynamic_pointer_cast<BlueThunder>(x);
        // //
        // // MadBot y = std::move(*blueThunderPtr);
        // auto y = std::move(x);
        // bg->robotKill(1,1);
        // x.reset();
        // cout << y->getName() << endl;
        // //y = nullptr;
        // //cout << y->getName();
        //
        // //y->updateLoc(make_pair(2,2));
        // //bg->robotKill(0,0);
        // //x = nullptr;
        //
        //
        // cout << endl << "END ********************" << endl;
        // bg->print();

        return 0;
}