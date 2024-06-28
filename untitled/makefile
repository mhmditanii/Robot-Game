# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g

# Source files
SRCS = robots_c/MainRobot.cpp robots_c/ShootingRobot.cpp \
       robots_c/SeeingRobot.cpp robots_c/MovingRobot.cpp robots_c/SteppingRobot.cpp \
       sub_robots_c/BlueThunder.cpp sub_robots_c/Terminator.cpp sub_robots_c/Robocop.cpp \
       Data_structures/svector.cpp Data_structures/svector_robot_ptr.cpp \
       Data_structures/Queue.cpp Data_structures/linked_list.cpp \
       upgraded_robots_c/MadBot.cpp upgraded_robots_c/RoboTank.cpp \
       upgraded_robots_c/TerminatorRoboCop.cpp utilities/filehandler.cpp test.cpp BattleGround.cpp



# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = GameExe

# Default target
all: $(EXEC)

# Linking
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilation
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean
clean:
	rm -f $(OBJS) $(EXEC)

# Phony targets
.PHONY: all clean
