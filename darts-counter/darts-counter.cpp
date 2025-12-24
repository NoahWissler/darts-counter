#include "darts-counter.h"
#include <cmath>
extern MainWindow *g_mainWindow;
    double player::calcLegAvg(){
        double legAvg {0};
        for(uint8_t d : darts){
            legAvg += d;
        }
        legAvg = (legAvg/darts.size())*3;
        return (std::round(legAvg * 100) / 100);

        return 0.00;
    }

void dartevaluator(char factor, player &player, int &darts){
    int dartvalue {};
    switch(factor){
    case 'S':
        dartvalue = player.darts[player.darts.size()-1];
        break;
    case 'D':
        dartvalue = player.darts[player.darts.size()-1]*2;
        player.darts[player.darts.size()-1] = dartvalue;
        break;
    case 'T':
        dartvalue = player.darts[player.darts.size()-1]*3;
        player.darts[player.darts.size()-1] = dartvalue;
        break;
    }
    if(player.score - dartvalue > 0){
        player.score -=dartvalue;
    }else if(player.score - dartvalue == 0 && factor == 'D'){
        player.score -=dartvalue;
    }else{
        player.darts[player.darts.size()-1] = 0;
        g_mainWindow->updateLabels();
        if(darts == 1){
            ++darts;
            player.darts.push_back(0);
            g_mainWindow->updateLabels();
            ++darts;
            player.darts.push_back(0);
        }
        else if(darts == 2){
            player.score = player.score + player.darts[player.darts.size()-2];
            player.darts[player.darts.size()-2] = 0;
            g_mainWindow->updateLabels();
            --darts;
            g_mainWindow->updateLabels();
            ++darts;
            g_mainWindow->updateLabels();
            ++darts;
            player.darts.push_back(0);


        }
        else if(darts == 3){
            player.score = player.score + player.darts[player.darts.size()-3];
            player.darts[player.darts.size()-3] = 0;
            --darts;
            --darts;
            g_mainWindow->updateLabels();
            ++darts;
            ++darts;
            player.score = player.score + player.darts[player.darts.size()-2];
            player.darts[player.darts.size()-2] = 0;
            --darts;
            g_mainWindow->updateLabels();
            ++darts;
        }
        }
    g_mainWindow->updateLabels();
    }

void dartsCounter(){}
