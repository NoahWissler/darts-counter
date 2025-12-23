#include "darts-counter.h"
#include <cmath>

    double player::calcLegAvg(){
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

void dartevaluator(char factor, player &player){
    int dartvalue {};
    switch(factor){
    case 'S':
        dartvalue = player.darts[player.darts.size()-1];
        break;
    case 'D':
        dartvalue = player.darts[player.darts.size()-1]*2;
        break;
    case 'T':
        dartvalue = player.darts[player.darts.size()-1]*3;
        break;
    }
    if(player.score - dartvalue > 0){
        player.score -=dartvalue;
    }else if(player.score - dartvalue == 0 && factor == 'D'){
        player.score -=dartvalue;
    }else{
            player.darts[player.darts.size()-1] = 0;
        }

    }

void dartsCounter(){}
