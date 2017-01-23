#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../emul/proc.h"

#include <QMainWindow>
#include <QTableWidget>
#include <QString>


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    Proc *cpu;
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void setCPU(Proc *cpu);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;

private:
    //Метод для настройки интерфейса
    void createUI(const QStringList &headers);
};

#endif // MAINWINDOW_H
