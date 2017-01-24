#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../emul/proc.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QString>
#include <QPainter>
#include <QBitmap>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Proc *cpu;
    explicit MainWindow(Proc*, QWidget *parent = 0);
    ~MainWindow();
    void setCPU(Proc *cpu);

private slots:
    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::MainWindow *ui;

private:
    //Метод для настройки интерфейса
    void createUI(const QStringList &headers);
    // Дизассембла с чекбоксами
    void disasmTable(const QStringList &headers);
    void setStatword(const QStringList &headers);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // MAINWINDOW_H
