cmake_minimum_required(VERSION 3.28)
project(untitled)

set(CMAKE_CXX_STANDARD 17)

add_executable(untitled
        BattleGround.cpp
        BattleGround.h
        robots_c/MainRobot.cpp
        robots_h/MainRobot.h
        Data_structures/svector.cpp
        Data_structures/svector.h
        robots_c/MovingRobot.cpp
        robots_h/MovingRobot.h
        robots_c/ShootingRobot.cpp
        robots_h/ShootingRobot.h
        robots_c/SeeingRobot.cpp
        robots_h/SeeingRobot.h
        robots_c/SteppingRobot.cpp
        robots_h/SteppingRobot.h
        sub_robots_c/Robocop.cpp
        sub_robots_h/Robocop.h
        sub_robots_c/Terminator.cpp
        sub_robots_h/Terminator.h
        sub_robots_c/BlueThunder.cpp
        sub_robots_h/BlueThunder.h
        upgraded_robots_c/TerminatorRoboCop.cpp
        upgraded_robots_h/TerminatorRoboCop.h
        upgraded_robots_c/MadBot.cpp
        upgraded_robots_h/MadBot.h
        upgraded_robots_c/RoboTank.cpp
        upgraded_robots_h/RoboTank.h
        upgraded_robots_c/UltimateRobot.cpp
        upgraded_robots_h/UltimateRobot.h
        test.cpp
        Handlers/Robots_unifier.h
        Data_structures/svector_robot_ptr.cpp
        Data_structures/svector_robot_ptr.h
        Data_structures/linked_list.cpp
        Data_structures/linked_list.h
        Data_structures/Queue.cpp
        Data_structures/Queue.h
)
