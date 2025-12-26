#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QPushButton>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:

    void changeCurrPlayer();

    void setUiNewThrow();

    void updateLabels();

    void on_double_2_clicked();

    void on_triple_clicked();

    void on_threw0_clicked();

    void on_threw1_clicked();

    void on_threw2_clicked();

    void on_threw3_clicked();

    void on_threw4_clicked();

    void on_threw5_clicked();

    void on_threw6_clicked();

    void on_threw7_clicked();

    void on_threw8_clicked();

    void on_threw9_clicked();

    void on_threw10_clicked();

    void on_threw11_clicked();

    void on_threw12_clicked();

    void on_threw13_clicked();

    void on_threw14_clicked();

    void on_threw15_clicked();

    void on_threw16_clicked();

    void on_threw17_clicked();

    void on_threw18_clicked();

    void on_threw19_clicked();

    void on_threw20_clicked();

    void on_threw25_clicked();


public:
    Ui::MainWindow *ui;
private slots:
    void on_return_2_clicked();
};
#endif // MAINWINDOW_H
