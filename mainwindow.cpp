#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this -> setWindowTitle ("Grade Calculator");

    ui->comboBox->insertItem(0, "Pic 10B. Intermediate Programming.");
    ui->comboBox->insertItem(0, "Pic 10C. Advanced Programming.");

    ui->label->setText("Course:");

    ui->label_2->setText("Hw 8");
    ui->label_3->setText("Hw 1");
    ui->label_4->setText("Hw 2");
    ui->label_5->setText("Hw 3");
    ui->label_6->setText("Hw 4");
    ui->label_7->setText("Hw 5");
    ui->label_8->setText("Hw 6");
    ui->label_9->setText("Hw 7");
    ui->label_10->setText("Midterm 1");
    ui->label_11->setText("Midterm 2");
    ui->label_12->setText("Final Exam");
    ui->label_13->setText("Schema A");
    ui->label_14->setText("Schema B");
    ui->label_15->setText("Final Score: " );
    ui->label_16 ->setVisible(false);

    ui->spinBox->setRange(0,100);
    ui->spinBox_2->setRange(0,100);
    ui->spinBox_3->setRange(0,100);
    ui->spinBox_4->setRange(0,100);
    ui->spinBox_5->setRange(0,100);
    ui->spinBox_6->setRange(0,100);
    ui->spinBox_7->setRange(0,100);
    ui->spinBox_8->setRange(0,100);
    ui->spinBox_9->setRange(0,100);
    ui->spinBox_10->setRange(0,100);
    ui->spinBox_11->setRange(0,100);

    ui->horizontalSlider->setRange(0,100);
    ui->horizontalSlider_2->setRange(0,100);
    ui->horizontalSlider_3->setRange(0,100);
    ui->horizontalSlider_4->setRange(0,100);
    ui->horizontalSlider_5->setRange(0,100);
    ui->horizontalSlider_6->setRange(0,100);
    ui->horizontalSlider_7->setRange(0,100);
    ui->horizontalSlider_8->setRange(0,100);
    ui->horizontalSlider_9->setRange(0,100);
    ui->horizontalSlider_10->setRange(0,100);
    ui->horizontalSlider_11->setRange(0,100);

    ui->radioButton->setText(" ");
    ui->radioButton_2->setText(" ");

    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(switchClass()));
    connect(ui->comboBox,SIGNAL(currentIndexChanged(QString)),this,SLOT(Calculation()));

    connect(ui->spinBox,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_2,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_3,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_4,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_5,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_6,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_7,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_8,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_9,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_10,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->spinBox_11,SIGNAL(valueChanged(int)),this,SLOT(Calculation()));
    connect(ui->radioButton,SIGNAL(toggled(bool)),this,SLOT(Calculation()));
    connect(ui->radioButton_2,SIGNAL(toggled(bool)),this,SLOT(Calculation()));

    connect(ui->horizontalSlider,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_2,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_3,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_4,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_5,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_6,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_7,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_8,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_9,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_10,SIGNAL(valueChanged(int)),this,SLOT(slider()));
    connect(ui->horizontalSlider_11,SIGNAL(valueChanged(int)),this,SLOT(slider()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::switchClass(){
    if(ui->comboBox->currentIndex()){
        ui->label_11->setText("Midterm 2");
    }
     else{
        ui->label_11->setText("Final Project");

    }
}

void MainWindow::Calculation(){
    if(ui->comboBox->currentIndex() == 1){
        int assignments[8] = {ui->spinBox->value(),ui->spinBox_2->value(), ui->spinBox_3->value(),ui->spinBox_4->value(),
                             ui->spinBox_5->value(),ui->spinBox_6->value(), ui->spinBox_7->value(),ui->spinBox_8->value()};

        double lowestHomework = assignments[0];
        double homeworkTotal = 0;
        for(int i = 0; i < 8; ++i){
            if(assignments[i] < lowestHomework)
                lowestHomework = assignments[i];
        }
        for(int i = 0; i < 8; ++i){
            homeworkTotal += assignments[i];
        }
        homeworkTotal -= lowestHomework;
        homeworkTotal /= 7;

        double m1 = ui->spinBox_9->value();
        double m2 = ui->spinBox_10->value();
        double final = ui->spinBox_11->value();
        double overall_A = .25*homeworkTotal + .2*m1 + .2*m2 + .35*final;
        double overall_B = 0;
        if(m1 > m2)
            overall_B = .25*homeworkTotal + .3*m1 + .45*final;
        else
            overall_B = .25*homeworkTotal + .3*m2 + .45*final;

        if(ui->radioButton->isChecked()){
            ui->label_16->setNum(overall_A);
            ui->label_16->setVisible(true);
        }
        else if(ui->radioButton_2->isChecked()){
            ui->label_16->setNum(overall_B);
            ui->label_16->setVisible(true);
        }
        else
            ui->label_16->setVisible(false);
    }
    else{
        int assignments[8] = {ui->spinBox->value(),ui->spinBox_2->value(), ui->spinBox_3->value(),ui->spinBox_4->value(),
                             ui->spinBox_5->value(),ui->spinBox_6->value(), ui->spinBox_7->value(),ui->spinBox_8->value()};

        double lowestHomework = assignments[0];
        double homeworkTotal = 0;
        for(int i = 0; i < 8; ++i){
            if(assignments[i] < lowestHomework)
                lowestHomework = assignments[i];
        }
        for(int i = 0; i < 8; ++i){
            homeworkTotal += assignments[i];
        }
        homeworkTotal -= lowestHomework;
        homeworkTotal /= 7;

        double m1 = ui->spinBox_9->value();
        double m2 = ui->spinBox_10->value();
        double final = ui->spinBox_11->value();
        double overall_A = .15*homeworkTotal + .25*m1 + .35*m2 + .3*final;
        double overall_B = .15*homeworkTotal + .5*final + .35*m2;

        if(ui->radioButton->isChecked()){
            ui->label_16->setNum(overall_A);
            ui->label_16->setVisible(true);
        }
        else if(ui->radioButton_2->isChecked()){
            ui->label_16->setNum(overall_B);
            ui->label_16->setVisible(true);
        }
        else
            ui->label_16->setVisible(false);
    }
}

void MainWindow::slider(){
    ui->spinBox->setValue(ui->horizontalSlider->value());
    ui->spinBox_2->setValue(ui->horizontalSlider_2->value());
    ui->spinBox_3->setValue(ui->horizontalSlider_3->value());
    ui->spinBox_4->setValue(ui->horizontalSlider_4->value());
    ui->spinBox_5->setValue(ui->horizontalSlider_5->value());
    ui->spinBox_6->setValue(ui->horizontalSlider_6->value());
    ui->spinBox_7->setValue(ui->horizontalSlider_7->value());
    ui->spinBox_8->setValue(ui->horizontalSlider_8->value());
    ui->spinBox_9->setValue(ui->horizontalSlider_9->value());
    ui->spinBox_10->setValue(ui->horizontalSlider_10->value());
    ui->spinBox_11->setValue(ui->horizontalSlider_11->value());
}
