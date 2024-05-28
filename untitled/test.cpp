//
// Created by mhmd on 5/19/24.
//
#include<iostream>
#include<memory>
#include"Data_structures/svector.h"
//#include "sub_robots_h/BlueThunder.h"
// #include "sub_robots_h/Robocop.h"
#include "sub_robots_h/BlueThunder.h"
//#include "sub_robots_h/Terminator.h"
int main() {
    svector<MainRobot*> r(3,3,nullptr);
    shared_ptr<BlueThunder> x = make_shared<BlueThunder>(1,"Ahmad",2,2);
    shared_ptr<MainRobot> s = x;
    r.setData(2,2,s.get());
    r.print();
    return 0;
}