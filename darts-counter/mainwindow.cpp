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
    dartevaluator(factor, players[currPlayer]);
    factor = 'S';
    ui->threw25->setEnabled(true);
    ++darts;
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }

}

void MainWindow::on_threw1_clicked()
{
    players[currPlayer].darts.push_back(1);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw2_clicked()
{
    players[currPlayer].darts.push_back(2);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw3_clicked()
{
    players[currPlayer].darts.push_back(3);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw4_clicked()
{
    players[currPlayer].darts.push_back(4);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw5_clicked()
{
    players[currPlayer].darts.push_back(5);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw6_clicked()
{
    players[currPlayer].darts.push_back(6);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw7_clicked()
{
    players[currPlayer].darts.push_back(7);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw8_clicked()
{
    players[currPlayer].darts.push_back(8);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw9_clicked()
{
    players[currPlayer].darts.push_back(9);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw10_clicked()
{
    players[currPlayer].darts.push_back(10);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw11_clicked()
{
    players[currPlayer].darts.push_back(11);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw12_clicked()
{
    players[currPlayer].darts.push_back(12);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw13_clicked()
{
    players[currPlayer].darts.push_back(13);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw14_clicked()
{
    players[currPlayer].darts.push_back(14);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw15_clicked()
{
    players[currPlayer].darts.push_back(15);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw16_clicked()
{
    players[currPlayer].darts.push_back(16);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw17_clicked()
{
    players[currPlayer].darts.push_back(17);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw18_clicked()
{
    players[currPlayer].darts.push_back(18);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw19_clicked()
{
    players[currPlayer].darts.push_back(19);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}


void MainWindow::on_threw20_clicked()
{
    players[currPlayer].darts.push_back(20);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}

void MainWindow::on_threw25_clicked()
{
    players[currPlayer].darts.push_back(25);
    dartevaluator(factor, players[currPlayer]);
    ++darts;
    factor = 'S';
    ui->threw25->setEnabled(true);
    if(darts > 2){
        if(currPlayer == 0){
            currPlayer = 1;
            darts = 0;
        }else{
            currPlayer = 0;
            darts = 0;
        }
    }


}



