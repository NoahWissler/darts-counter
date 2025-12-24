#ifndef DARTS_COUNTER_H
#define DARTS_COUNTER_H
#include "mainwindow.h"
#include <cstdint>
#include <vector>
class player{
public:
    int score{501};
    std::vector<uint8_t> darts;

    double calcLegAvg();
};

void dartsCounter();

void dartevaluator(char factor, player &player, int &darts);


#endif // DARTS_COUNTER_H
