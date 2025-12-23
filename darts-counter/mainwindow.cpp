#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "darts-counter.h"
MainWindow *g_mainWindow = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    g_mainWindow = this;
    updateLabels();
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
int darts {};
std::vector<player> players(2);


void MainWindow::updateLabels()
{
    ui->player1Score->setText(QString::number(players[0].score));
    ui->player2Score->setText(QString::number(players[1].score));
    ui->player1Avg->setText(QString::number(players[0].calcLegAvg()));
    ui->player2Avg->setText(QString::number(players[1].calcLegAvg()));
    if(currPlayer == 0){
        switch(darts){

        case 0:
            ui->player1FirstDart->setText("/");
            ui->player1SecondDart->setText("/");
            ui->player1ThirdDart->setText("/");
            break;
        case 1:
            ui->player1FirstDart->setText(QString::number(players[0].darts[players[0].darts.size()-1]));
            break;
        case 2:
            ui->player1SecondDart->setText(QString::number(players[0].darts[players[0].darts.size()-1]));
            break;
        case 3:
            ui->player1ThirdDart->setText(QString::number(players[0].darts[players[0].darts.size()-1]));
            break;
        }
    }else{
        switch(darts){

        case 0:
            ui->player2FirstDart->setText("/");
            ui->player2SecondDart->setText("/");
            ui->player2ThirdDart->setText("/");
            break;
        case 1:
            ui->player2FirstDart->setText(QString::number(players[1].darts[players[1].darts.size()-1]));
            break;
        case 2:
            ui->player2SecondDart->setText(QString::number(players[1].darts[players[1].darts.size()-1]));
            break;
        case 3:
            ui->player2ThirdDart->setText(QString::number(players[1].darts[players[1].darts.size()-1]));
            break;
        }
    }

}

void MainWindow::on_double_2_clicked()
{
    factor = 'D';

}

void MainWindow::on_triple_clicked()
{
    factor = 'T';
    ui->threw25->setEnabled(false);
}

void MainWindow::on_threw0_clicked()
{
    players[currPlayer].darts.push_back(0);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }

}

void MainWindow::on_threw1_clicked()
{
    players[currPlayer].darts.push_back(1);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw2_clicked()
{
    players[currPlayer].darts.push_back(2);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw3_clicked()
{
    players[currPlayer].darts.push_back(3);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw4_clicked()
{
    players[currPlayer].darts.push_back(4);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw5_clicked()
{
    players[currPlayer].darts.push_back(5);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw6_clicked()
{
    players[currPlayer].darts.push_back(6);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw7_clicked()
{
    players[currPlayer].darts.push_back(7);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw8_clicked()
{
    players[currPlayer].darts.push_back(8);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw9_clicked()
{
    players[currPlayer].darts.push_back(9);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw10_clicked()
{
    players[currPlayer].darts.push_back(10);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw11_clicked()
{
    players[currPlayer].darts.push_back(11);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw12_clicked()
{
    players[currPlayer].darts.push_back(12);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw13_clicked()
{
    players[currPlayer].darts.push_back(13);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw14_clicked()
{
    players[currPlayer].darts.push_back(14);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw15_clicked()
{
    players[currPlayer].darts.push_back(15);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw16_clicked()
{
    players[currPlayer].darts.push_back(16);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw17_clicked()
{
    players[currPlayer].darts.push_back(17);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw18_clicked()
{
    players[currPlayer].darts.push_back(18);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw19_clicked()
{
    players[currPlayer].darts.push_back(19);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}


void MainWindow::on_threw20_clicked()
{
    players[currPlayer].darts.push_back(20);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}

void MainWindow::on_threw25_clicked()
{
    players[currPlayer].darts.push_back(25);
    ++darts;
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
            updateLabels();
        }else{
            currPlayer = 0;
            darts = 0;
            updateLabels();
        }
    }


}



