#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include<QIntValidator>
#include <QMainWindow>
#include<QMessageBox>
#include<llse.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_pushButton_clicked();

    void on_pushButtonAcessarInicio_clicked();

    void on_pushButtonRetirarInicio_clicked();

    void on_pushButtonInsertLast_clicked();

    void on_pushButtonAcessarFinal_clicked();

    void on_pushButtonRetirarFinal_clicked();

    void on_pushButtonAcessarPosicao_clicked();

    void on_pushButtonRetirarPosicao_clicked();

    void on_pushButtonInsertPosicao_clicked();

private:
    Ui::MainWindow *ui;
    adf::LLSE list;
    QString color="red";
};
#endif // MAINWINDOW_H
