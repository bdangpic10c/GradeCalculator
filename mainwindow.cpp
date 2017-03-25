#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
    ui->label_12->setText("Midterm 3");
    ui->label_13->setText("Schema A");
    ui->label_14->setText("Schema B");
    ui->label_15->setText("Final Score: " );


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

    ui->radioButton->setText(" ");
    ui->radioButton_2->setText(" ");
}

MainWindow::~MainWindow()
{
    delete ui;
}
