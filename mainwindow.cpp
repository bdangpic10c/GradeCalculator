#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->comboBox->insertItem(0, "Pic 10B");
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

}

MainWindow::~MainWindow()
{
    delete ui;
}
