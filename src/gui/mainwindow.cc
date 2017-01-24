#include "mainwindow.h"
#include "emulator.h"
//#include "../emul/metadata.h"
#include "../emul/memory_unit.h"
#include "ui_mainwindow.h"
#include <stdio.h>
#include <string.h>
#include <iostream>

MainWindow::MainWindow(Proc* cpu, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->cpu = cpu;
    ui->setupUi(this);
    this->createUI(QStringList() << trUtf8("R0") << trUtf8("R0") << trUtf8("R1") << trUtf8("R2") << trUtf8("R3") << trUtf8("R4") << trUtf8("R5") << trUtf8("R6") << trUtf8("R7"));
    this->disasmTable(QStringList() << trUtf8("BP") << trUtf8("Address") << trUtf8("Disasm"));
    this->setStatword(QStringList() << trUtf8("N") << trUtf8("N") << trUtf8("Z") << trUtf8("O") << trUtf8("C"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setCPU(Proc *cpu)
{
    this->cpu = cpu;
}

void MainWindow::createUI(const QStringList &headers)
{
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget->setColumnCount(2); // Указываем число колонок
    ui->tableWidget->setRowCount(9);
    for(int i = 1; i < 9; i++) {
        char reg[6];
        sprintf(reg, "%x", (uint16_t)cpu->memory->registers[i-1]);
        QTableWidgetItem *itmV = new QTableWidgetItem(reg);
        ui->tableWidget->setItem(i, 1 ,itmV);
    }
    QString val = "Value Value Value Value";
    QStringList header1 = val.split(" ");
    ui->tableWidget->setShowGrid(true); // Включаем сетку
    // Разрешаем выделение только одного элемента
    ui->tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
    // Разрешаем выделение построчно
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    // Устанавливаем заголовки колонок
    ui->tableWidget->setHorizontalHeaderLabels(header1);
    ui->tableWidget->setVerticalHeaderLabels(headers);
    // Растягиваем последнюю колонку на всё доступное пространство
    ui->tableWidget->horizontalHeader()->setStretchLastSection(true);
    // Скрываем колонку под номером 0
    ui->tableWidget->hideColumn(0);
    ui->tableWidget->hideRow(0);
}

void MainWindow::disasmTable(const QStringList &headers)
{
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_2->setColumnCount(3); // Указываем число колонок
    ui->tableWidget_2->setRowCount(13);
    ui->tableWidget_2->setHorizontalHeaderLabels(headers);
    ui->tableWidget_2->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_2->hideColumn(0);
}

void MainWindow::setStatword(const QStringList &headers)
{
    ui->tableWidget_3->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableWidget_3->setColumnCount(5); // Указываем число колонок
    ui->tableWidget_3->setRowCount(1);
    ui->tableWidget_3->setHorizontalHeaderLabels(headers);
    ui->tableWidget_3->horizontalHeader()->setStretchLastSection(true);
    ui->tableWidget_3->verticalHeader()->setStretchLastSection(true);
    ui->tableWidget_3->hideColumn(0);
    //QTableWidgetItem *itmV = new QTableWidgetItem("0");
    int8_t word[4];
    for (int i = 0; i < 4; i++) {
        word[i] = (cpu->memory->statword >> (3-i))&0x01;
        char w[4];
        sprintf(w, "%d", (int8_t)word[i]);
        QTableWidgetItem *itmV = new QTableWidgetItem(w);
        ui->tableWidget_3->setItem(0, i+1 ,itmV);
        ui->tableWidget_3->setColumnWidth(i, 40);
    }

}

void MainWindow::paintEvent(QPaintEvent *){
    QPainter p;
    p.begin(this);
    
    int8_t *color = new int8_t[4096];
    for (int i = 0; i < 4096; i++)
        color[i] = 0;
    	
    cpu->memory->read_line(cpu->meta->vram_map, cpu->meta->vram_len, color);


    for (int i=0; i<=64; i++)
            for (int j=0; j<= 64; j++){
            	//p.setPen(QPen(QColor(rand()%16777000)));
                p.setPen(QPen(QColor(color[i*64 + j])));
                p.drawPoint(2*i + 515,2*j + 180); // 360-430 ms
                p.drawPoint(2*i + 515,2*j+1 + 180);
                p.drawPoint(2*i+1 + 515,2*j + 180);
                p.drawPoint(2*i+1 + 515,2*j+1 + 180);
            }
}

void MainWindow::on_pushButton_clicked()
{
    ui->label->setText("Registers");

}

void MainWindow::on_pushButton_3_clicked()
{
    cpu->step();
}
