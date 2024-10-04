#ifndef LEGENDTHERMO
#define LEGENDTHERMO

#include <iostream>
#include <string>


class LegendThermo {
private:
    int currentTemp;
public:
    LegendThermo();
    void adjustTemperature(int temp);
    int readTemperature();
};

#endif 
