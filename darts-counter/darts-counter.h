#ifndef DARTS_COUNTER_H
#define DARTS_COUNTER_H
#include "mainwindow.h"
#include <cstdint>
#include <qlabel.h>
#include <vector>
extern MainWindow *g_mainWindow;
class player{
public:
    std::string name {};
    int score{};
    std::vector<uint8_t> darts;
    int setsWon {0};
    int legsWon {0};
    QList<QLabel*> labels;

    double calcLegAvg();
};

void dartevaluator(int &nrLegsPerSet, int &nrSets, int &lowestCheckoutNr, char &checkoutType, char &factor, player &player, int &darts);


#endif // DARTS_COUNTER_H
