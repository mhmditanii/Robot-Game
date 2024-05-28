//
// Created by mhmd on 5/18/24.
//

#ifndef BLUETHUNDER_H
#define BLUETHUNDER_H
#include "../robots_h/ShootingRobot.h"


class BlueThunder : public ShootingRobot{
private:
public:
    BlueThunder(int id,string name, size_t row, size_t column);
    ~BlueThunder() override;
    bool shoot() override;
    bool executeTurn() override;;
};



#endif //BLUETHUNDER_H
