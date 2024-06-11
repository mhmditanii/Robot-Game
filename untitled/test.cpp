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
        BattleGround* bg = new BattleGround(6,6,20);
        bg->robotInit(20,"ahmad",2,2);
        bg->robotInit(50,"ahmad",1,2);
        bg->robotInit(50,"ahmad",0,0);
        bg->robotInit(50,"ahmad",2,0);
        bg->robotInit(50,"ahmad",0,2);
        bg->startSimulator();

        cout << "END ********************" << endl;
        bg->print();

        return 0;
}
