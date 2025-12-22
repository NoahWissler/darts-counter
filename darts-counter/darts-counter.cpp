#include "darts-counter.h"
#include <vector>
#include <cstdint>
#include <cmath>
class player{
public:
    int score {501};
    std::vector<uint8_t> darts;
    double legAvg {};

    double calcLegAvg(){
        if(darts.empty()){
            return 0.00;
        }

        double legAvg {};
        for(uint8_t d : darts){
            legAvg += d;
        }
        legAvg = (legAvg/darts.size())*3;
        return (std::round(legAvg * 100) / 100);
    }
};

void dartsCounter(){}
