#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT // declares 'mainwindow' as qt object

public:
    MainWindow(QWidget *parent = nullptr); // widget has no parent
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
void calcPressed();
void csbPressed();
void picPressed();
void phyPressed();
void dropLow(double[]);

};
#endif // MAINWINDOW_H
