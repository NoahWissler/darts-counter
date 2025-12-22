#include "darts-counter.h"
#include <vector>
#include <cstdint>
struct player{
    int score {501};
    std::vector<uint8_t> darts;
    double legAvg {};

    double calcLegAvg(player p){
        double legAvg {};
        for(uint8_t i : p.darts){
            legAvg = legAvg + i;
        }
        legAvg = (legAvg/p.darts.size())*3;
        return legAvg;
    }
};

void dartsCounter(){}
