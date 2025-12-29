#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "darts-counter.h"
MainWindow *g_mainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Darts Counter");
    this->setWindowIcon(QIcon(":/icons/darts.png"));
    g_mainWindow = this;
    ui->player2FirstDart->setText("/");
    ui->player2SecondDart->setText("/");
    ui->player2ThirdDart->setText("/");
}

MainWindow::~MainWindow()
{
    delete ui;
}

char factor = 'S';
int currPlayer {0};
int otherShownPlayer{1};
int nextPlayer {1};
int previousPlayer {};
int darts {};
std::vector<player> players;
int nrPlayers {};
int nrLegsPerSet {};
int nrSets {};
bool singleOut;
char checkoutType;
int lowestCheckoutNr;

void MainWindow::initializeMatch(){
    std::string checkoutTypeString;
    checkoutTypeString = ui->selectCheckoutType->currentText().toStdString();
    if(checkoutTypeString == "Single Out"){
        singleOut = true;
        lowestCheckoutNr = 1;
    }else if(checkoutTypeString == "Double Out"){
        lowestCheckoutNr = 2;
        checkoutType = 'D';
    }else{
        lowestCheckoutNr = 3;
        checkoutType = 'T';
    }
    if(ui->selectPlayerScore->currentText().toInt() < lowestCheckoutNr){
        ui->selectPlayerScore->setCurrentText(QString::number(lowestCheckoutNr));
    }
    initializePlayerProfiles();
    previousPlayer = nrPlayers-1;
}

void MainWindow::newLegReset(){
    for(int i {}; i < nrPlayers; ++i){
        if(players[currPlayer].legsWon == nrLegsPerSet){
            players[i].legsWon = 0;
        }
        players[i].score = ui->selectPlayerScore->currentText().toInt();
        players[i].darts.clear();
}
}





void MainWindow::initializePlayerProfiles(){
nrPlayers = ui->selectNrPlayers->currentText().toInt();
players.resize(nrPlayers);
nrLegsPerSet = ui->legs->currentText().toInt();
nrSets = ui->sets->currentText().toInt();

for(int i {}; i < nrPlayers; ++i){
    players[i].name = "Player " + std::to_string((i+1));
    players[i].score = ui->selectPlayerScore->currentText().toInt();
    if((i+1)%2 != 0){
        players[i].labels = {ui->player1Name, ui->player1Score, ui->player1Avg, ui->player1FirstDart, ui->player1SecondDart, ui->player1ThirdDart};
    }else{
        players[i].labels = {ui->player2Name, ui->player2Score, ui->player2Avg, ui->player2FirstDart, ui->player2SecondDart, ui->player2ThirdDart};
    }

}
}

void MainWindow::updateLabels()
{
    //Lowk nothing to do with labels but deactivates return if first player darts is empty so we get no SIGSEGV by people spamming return and this function is handy for this cuz
    //its executed every fucking millisecond
    if(players[0].darts.empty()){
        ui->return_2->setEnabled(false);
    }else if(players[currPlayer].setsWon != nrSets){
        ui->return_2->setEnabled(true);
    }
    if(players[currPlayer].legsWon == nrLegsPerSet){
        ++players[currPlayer].setsWon;
        players[currPlayer].legsWon = 0;
    }

    players[currPlayer].labels[0]->setText(QString::fromStdString(players[currPlayer].name));

    if(players[currPlayer].score != 0){
    players[currPlayer].labels[1]->setText(QString::number(players[currPlayer].score));
    }else if(players[currPlayer].setsWon == nrSets){
    players[currPlayer].labels[1]->setStyleSheet("QLabel {color: #D3AF37;} ");
    players[currPlayer].labels[1]->setText("Winner");
        QList<QPushButton*> buttons = findChildren<QPushButton*>();
        for (int i = 0; i < buttons.size(); ++i) {
            buttons[i]->setEnabled(false);
        }
    }
    if(!players[currPlayer].darts.empty()){
    players[currPlayer].labels[2]->setText(QString::number(players[currPlayer].calcLegAvg()));
    }else{
    players[currPlayer].labels[2]->setText("No Average Yet");
    }


    if(otherShownPlayer > -1){
    players[otherShownPlayer].labels[0]->setText(QString::fromStdString(players[otherShownPlayer].name));
    if(players[otherShownPlayer].score != 0){
        players[otherShownPlayer].labels[1]->setText(QString::number(players[otherShownPlayer].score));
    }
    if(!players[otherShownPlayer].darts.empty()){
        players[otherShownPlayer].labels[2]->setText(QString::number(players[otherShownPlayer].calcLegAvg()));
    }else{
        players[otherShownPlayer].labels[2]->setText("No Average Yet");
    }
    }else{
        ui->player2Name->setText("/");
        ui->player2Score->setText("/");
        ui->player2Avg->setText("/");
    }
        switch(darts){

        case 0:
            if(!players[otherShownPlayer].darts.empty() && otherShownPlayer > -1){
            players[otherShownPlayer].labels[3]->setText(QString::number(players[otherShownPlayer].darts[players[otherShownPlayer].darts.size()-3]));
            players[otherShownPlayer].labels[4]->setText(QString::number(players[otherShownPlayer].darts[players[otherShownPlayer].darts.size()-2]));
            players[otherShownPlayer].labels[5]->setText(QString::number(players[otherShownPlayer].darts[players[otherShownPlayer].darts.size()-1]));
            }else{
                ui->player2FirstDart->setText("/");
                ui->player2SecondDart->setText("/");
                ui->player2ThirdDart->setText("/");
            }
            players[currPlayer].labels[3]->setText("/");
            players[currPlayer].labels[4]->setText("/");
            players[currPlayer].labels[5]->setText("/");
            break;
        case 1:
            players[currPlayer].labels[3]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-1]));
            players[currPlayer].labels[4]->setText("/");
            players[currPlayer].labels[5]->setText("/");
            break;
        case 2:
            players[currPlayer].labels[3]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-2]));
            players[currPlayer].labels[4]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-1]));
            players[currPlayer].labels[5]->setText("/");
            break;
        case 3:
            players[currPlayer].labels[3]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-3]));
            players[currPlayer].labels[4]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-2]));
            players[currPlayer].labels[5]->setText(QString::number(players[currPlayer].darts[players[currPlayer].darts.size()-1]));
            break;
        }
    }

void MainWindow::changeCurrPlayer(){
    if(darts > 2 && (players[currPlayer].setsWon != nrSets)){
        previousPlayer = currPlayer;
        currPlayer = nextPlayer;
        if(currPlayer != nrPlayers-1){
            nextPlayer = currPlayer+1;
        }else{
            nextPlayer = 0;
        }
        if(currPlayer%2 != 0){
            otherShownPlayer = currPlayer-1;
        }else if(nrPlayers%2 == 0){
            otherShownPlayer = currPlayer+1;
        }else{
            otherShownPlayer = -1;
        }
        darts = 0;
        updateLabels();
    }
}

void MainWindow::setUiNewThrow(){
    factor = 'S';
    if(singleOut){
        checkoutType = factor;
    }
    if(players[currPlayer].setsWon != nrSets){
    ui->threw0->setEnabled(true);
    ui->threw25->setEnabled(true);
    }else{
        ui->threw0->setEnabled(false);
        ui->threw25->setEnabled(false);
        ui->return_2->setEnabled(false);
    }
    ui->double_2->setChecked(false);
    ui->triple->setChecked(false);
    updateLabels();


}

void MainWindow::on_return_2_clicked()
{
    setUiNewThrow();

    if(darts == 0){
            players[previousPlayer].score = players[previousPlayer].score + players[previousPlayer].darts[players[previousPlayer].darts.size()-1];
            players[previousPlayer].darts.pop_back();
        if(currPlayer == 0){
            currPlayer = nrPlayers-1;
            darts = 2;
            updateLabels();
        }else{
            --currPlayer;
            --nextPlayer;
            --previousPlayer;
            darts = 2;
            updateLabels();
        }
    }else{
        --darts;
        updateLabels();
    }
    players[currPlayer].score = players[currPlayer].score + players[currPlayer].darts[players[currPlayer].darts.size()-1];
    players[currPlayer].darts.pop_back();
    updateLabels();
}

void MainWindow::on_double_2_clicked()
{
    if(ui->double_2->isChecked()){
    factor = 'D';
        if(singleOut){
        checkoutType = factor;
        }
    ui->threw25->setEnabled(true);
    ui->threw0->setEnabled(false);
    ui->triple->setChecked(false);
    }else{
        setUiNewThrow();
    }
}

void MainWindow::on_triple_clicked()
{
    if(ui->triple->isChecked()){
    factor = 'T';
        if(singleOut){
        checkoutType = factor;
        }
    ui->threw25->setEnabled(false);
    ui->threw0->setEnabled(false);
    ui->double_2->setChecked(false);
    }else{
        setUiNewThrow();
    }
}

void MainWindow::on_threw0_clicked()
{
    players[currPlayer].darts.push_back(0);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw1_clicked()
{
    players[currPlayer].darts.push_back(1);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw2_clicked()
{
    players[currPlayer].darts.push_back(2);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw3_clicked()
{
    players[currPlayer].darts.push_back(3);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw4_clicked()
{
    players[currPlayer].darts.push_back(4);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw5_clicked()
{
    players[currPlayer].darts.push_back(5);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw6_clicked()
{
    players[currPlayer].darts.push_back(6);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw7_clicked()
{
    players[currPlayer].darts.push_back(7);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw8_clicked()
{
    players[currPlayer].darts.push_back(8);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw9_clicked()
{
    players[currPlayer].darts.push_back(9);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw10_clicked()
{
    players[currPlayer].darts.push_back(10);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw11_clicked()
{
    players[currPlayer].darts.push_back(11);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw12_clicked()
{
    players[currPlayer].darts.push_back(12);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw13_clicked()
{
    players[currPlayer].darts.push_back(13);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw14_clicked()
{
    players[currPlayer].darts.push_back(14);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw15_clicked()
{
    players[currPlayer].darts.push_back(15);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw16_clicked()
{
    players[currPlayer].darts.push_back(16);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw17_clicked()
{
    players[currPlayer].darts.push_back(17);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw18_clicked()
{
    players[currPlayer].darts.push_back(18);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw19_clicked()
{
    players[currPlayer].darts.push_back(19);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}


void MainWindow::on_threw20_clicked()
{
    players[currPlayer].darts.push_back(20);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}

void MainWindow::on_threw25_clicked()
{
    players[currPlayer].darts.push_back(25);
    ++darts;
    dartevaluator(nrLegsPerSet, nrSets, lowestCheckoutNr, checkoutType, factor, players[currPlayer], darts);
    setUiNewThrow();
    changeCurrPlayer();
}






void MainWindow::on_start_clicked()
{
    initializeMatch();
    updateLabels();
    ui->pages->setCurrentIndex(1);
}

