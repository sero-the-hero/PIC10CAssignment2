#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QApplication>
#include<QBoxLayout>
#include<QSpinBox>
#include<QSlider>

double Score  = 0;
std::string course = "pic";

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // connecting homework 1 spinbox/slider
    QObject::connect(ui->hw1SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw1Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw1Slider, SIGNAL( valueChanged(int) ),
                     ui->hw1SpinBox, SLOT( setValue(int) ) );


    // connecting homework 2 spinbox/slider
    QObject::connect(ui->hw2SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw2Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw2Slider, SIGNAL( valueChanged(int) ),
                     ui->hw2SpinBox, SLOT( setValue(int) ) );

    // connecting homework 3 spinbox/slider
    QObject::connect(ui->hw3SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw3Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw3Slider, SIGNAL( valueChanged(int) ),
                     ui->hw3SpinBox, SLOT( setValue(int) ) );

    // connecting homework 4 spinbox/slider
    QObject::connect(ui->hw4SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw4Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw4Slider, SIGNAL( valueChanged(int) ),
                     ui->hw4SpinBox, SLOT( setValue(int) ) );

    // connecting homework 5 spinbox/slider
    QObject::connect(ui->hw5SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw5Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw5Slider, SIGNAL( valueChanged(int) ),
                     ui->hw5SpinBox, SLOT( setValue(int) ) );

    // connecting homework 6 spinbox/slider
    QObject::connect(ui->hw6SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw6Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw6Slider, SIGNAL( valueChanged(int) ),
                     ui->hw6SpinBox, SLOT( setValue(int) ) );

    // connecting homework 6 spinbox/slider
    QObject::connect(ui->hw7SpinBox, SIGNAL( valueChanged(int) ),
                         ui->hw7Slider, SLOT( setValue(int) ) );
    QObject::connect(ui->hw7Slider, SIGNAL( valueChanged(int) ),
                     ui->hw7SpinBox, SLOT( setValue(int) ) );

    // connecting midterm
    QObject::connect(ui->mtSpinBox, SIGNAL( valueChanged(int) ),
                         ui->mtSlider, SLOT( setValue(int) ) );
    QObject::connect(ui->mtSlider, SIGNAL( valueChanged(int) ),
                     ui->mtSpinBox, SLOT( setValue(int) ) );

    // connecting paper
    QObject::connect(ui->paperSpinBox, SIGNAL( valueChanged(int) ),
                         ui->paperSlider, SLOT( setValue(int) ) );
    QObject::connect(ui->paperSlider, SIGNAL( valueChanged(int) ),
                     ui->paperSpinBox, SLOT( setValue(int) ) );

    // connecting Final spinbox/slider
    QObject::connect(ui->finalSpinBox, SIGNAL( valueChanged(int) ),
                         ui->finalSlider, SLOT( setValue(int) ) );
    QObject::connect(ui->finalSlider, SIGNAL( valueChanged(int) ),
                     ui->finalSpinBox, SLOT( setValue(int) ) );

    // connecting calculation button
    QObject::connect(ui->calcButton, SIGNAL(released()), this,
            SLOT(calcPressed()));

    // connecting PIC10C button
    QObject::connect(ui->picButton, SIGNAL(released()), this,
            SLOT(picPressed()));

    // connecting CsB button
    QObject::connect(ui->csbButton, SIGNAL(released()), this,
            SLOT(csbPressed()));

    // connecting PhySci125 button
    QObject::connect(ui->phyButton, SIGNAL(released()), this,
            SLOT(phyPressed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::calcPressed(){
    if (course == "pic" && ui->schemaA->isChecked()){
        double hwtot = 0;
        double hwarray[7]; // place homework scores in an array
        hwarray[0] = ui->hw1Slider->value();
        hwarray[1] = ui->hw2Slider->value();
        hwarray[2] = ui->hw3Slider->value();
        hwarray[3] = ui->hw4Slider->value();
        hwarray[4] = ui->hw5Slider->value();
        hwarray[5] = ui->hw6Slider->value();
        hwarray[6] = ui->hw7Slider->value();

        dropLow(hwarray);
        for (int i = 0; i < 7; i++){
            hwtot += hwarray[i];
        }

   Score = ((hwtot/24) + (ui->mtSlider->value()/5) + (ui->paperSlider->value()/5)+ (ui->finalSlider->value()/2.86));
   ui->Display->setText(QString::number(Score));

    }

    else if (course == "pic" && ui->schemaB->isChecked()){
        double hwtot = 0;
        double highMT = 0;
        double hwarray[7]; // place homework scores in an array
        hwarray[0] = ui->hw1Slider->value();
        hwarray[1] = ui->hw2Slider->value();
        hwarray[2] = ui->hw3Slider->value();
        hwarray[3] = ui->hw4Slider->value();
        hwarray[4] = ui->hw5Slider->value();
        hwarray[5] = ui->hw6Slider->value();
        hwarray[6] = ui->hw7Slider->value();

        dropLow(hwarray);

        for (int i = 0; i < 7; i++){
            hwtot += hwarray[i];
        }
        if (ui->mtSlider->value() > ui->paperSlider->value()){
            highMT = ui->mtSlider->value();
        }
        else if (ui->mtSlider->value() < ui->paperSlider->value()){
            highMT = ui->paperSlider->value();
        }
        else{
            highMT = ui->paperSlider->value();
        }

   Score = ((hwtot/24) + (highMT/3.333333) + (ui->finalSlider->value()/2.2727272727));
   ui->Display->setText(QString::number(Score));
           }

    else if (course == "csb"){
 Score = (((ui->hw1Slider->value() + ui->hw2Slider->value() + ui->hw3Slider->value() + ui->hw4Slider->value() + ui->hw5Slider->value() + ui->hw6Slider->value() + ui->hw7Slider->value())/70) + (ui->paperSlider->value()/2) + (ui->finalSlider->value())/2.85714286);
   ui->Display->setText(QString::number(Score));
    }

    else if (course == "phy"){
  Score = (((ui->hw1Slider->value() + ui->hw2Slider->value() + ui->hw3Slider->value() + ui->hw4Slider->value() + ui->hw5Slider->value() + ui->hw6Slider->value() + ui->hw7Slider->value())/35) + (ui->mtSlider->value()/4) + (ui->paperSlider->value()/4) + (ui->finalSlider->value())/3.33);
  ui->Display->setText(QString::number(Score));
    }
}

void MainWindow::picPressed(){
    course = "pic";
    ui->mtLabel->setText("Midterm");
    ui->paperLabel->setText("Midterm 2");
}

void MainWindow::csbPressed(){
    course = "csb";
    ui->mtLabel->setText("N/A");
    ui->paperLabel->setText("Paper");
}

void MainWindow::phyPressed(){ // sets course and applicable classes to
    course = "phy";
    ui->mtLabel->setText("Midterm");
    ui->paperLabel->setText("Paper");
}

void MainWindow::dropLow(double *hw){
       int lowpos = 0;
       double low = hw[0];
       for(int i=0; i<7; i++) {
          if(low > hw[i]) {
             low = hw[i];
             lowpos = i;
          }
       }
      hw[lowpos] = 0;
}

