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
        bg->robotInit(30,"samir",2,2);
        bg->robotInit(30,"ahmad",4,4);
        bg->robotInit(30,"mahmoud",5,3);
        bg->robotInit(30,"yaser",0,0);
        // bg->robotInit(60,"ahmad",2,0);
        // bg->robotInit(10,"ahmad",1,5);
        // bg->robotInit(20,"ahmad",3,3);
        // bg->robotInit(40,"ahmad",4,4);
        // bg->robotInit(30,"ahmad",5,0);
        // bg->robotInit(60,"ahmad",2,5);
        // bg->robotInit(10,"ahmad",4,1);
        // cout << "STarting the simulator" << endl;
        bg->gameHandler();

        cout << endl << "END ********************" << endl;
        bg->print();

        return 0;
}
