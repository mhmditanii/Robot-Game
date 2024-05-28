//
// Created by mhmd on 5/19/24.
//
#include<iostream>
#include<memory>
//#include"Data_structures/svector.h"
//#include "sub_robots_h/BlueThunder.h"
//#include "sub_robots_h/Robocop.h"
#include "sub_robots_h/BlueThunder.h"
#include "sub_robots_h/Robocop.h"
#include "sub_robots_h/Terminator.h"
int main() {
    shared_ptr<Robocop> x = make_shared<Robocop>(1,"Ahmad",2,2);
    shared_ptr<MainRobot> s = x;
    x = nullptr;
    s->executeTurn();
    return 0;
}