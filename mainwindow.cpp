#include "mainwindow.h"
#include "ui_mainwindow.h"
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
 ui->setupUi(this);
 ui->lineEditElements->setText(QString::number(list.getnumberElements()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    try{
        bool ok;
        ui->lineEditValor->text().toInt(&ok);
        if(ui->lineEditValor->text().toStdString().find('.')!=std::string::npos||ui->lineEditValor->text().isEmpty()||!ok) throw QString("input a must be an integer");
        ui->comboBox->addItem(QString::number(list.getnumberElements()));
        list.insertFirst(ui->lineEditValor->text().toInt());

        ui->textEditExit->setText(list.accessAllColored(color));
        ui->lineEditValor->setFocus();
        ui->lineEditValor->clear();
        ui->lineEditElements->setText(QString::number(list.getnumberElements()));
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}


void MainWindow::on_pushButtonAcessarInicio_clicked()
{
    try{

        ui->lineEditValor->setText(QString::number(list.accessFirst()));
        ui->lineEditValor->setFocus();
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}


void MainWindow::on_pushButtonAcessarFinal_clicked()
{
    try{


        ui->lineEditValor->setText(QString::number(list.accessLast()));
        ui->lineEditValor->setFocus();
     } catch (QString &erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}



void MainWindow::on_pushButtonInsertLast_clicked()
{
    try{
        bool ok;
        ui->lineEditValor->text().toInt(&ok);
        if(ui->lineEditValor->text().isEmpty()||!ok) throw QString("input a must be an integer");
        ui->comboBox->addItem(QString::number(list.getnumberElements()));
        list.insertLast(ui->lineEditValor->text().toInt());

        ui->textEditExit->setText(list.accessAllColored(color));
        ui->lineEditValor->setFocus();
        ui->lineEditValor->clear();
        ui->lineEditElements->setText(QString::number(list.getnumberElements()));
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }

}

void MainWindow::on_pushButtonRetirarFinal_clicked()
{
    try{
         ui->comboBox->removeItem(list.getnumberElements());
        if(list.getnumberElements()==1){
            QString exit="| |";
            ui->textEditExit->setText(exit);
            ui->lineEditValor->setText(QString::number(list.removeLast()));
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }else{
            ui->lineEditValor->setText(QString::number(list.removeLast()));
            ui->textEditExit->setText(list.accessAllColored(color));
            ui->lineEditValor->setFocus();
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}

void MainWindow::on_pushButtonRetirarInicio_clicked()
{
    try{
         ui->comboBox->removeItem(list.getnumberElements());
        if(list.getnumberElements()==1){
            QString exit="| |";
            ui->textEditExit->setText(exit);
            ui->lineEditValor->setText(QString::number(list.removeFirst()));
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }else{
            ui->lineEditValor->setText(QString::number(list.removeFirst()));
            ui->textEditExit->setText(list.accessAllColored(color));
            ui->lineEditValor->setFocus();
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}

void MainWindow::on_pushButtonAcessarPosicao_clicked()
{
    try {
        ui->lineEditValor->setText(QString::number(list.accessPosition(ui->comboBox->currentIndex())));
        ui->lineEditValor->setFocus();
    } catch (QString erro) {
        QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
    }
}


void MainWindow::on_pushButtonRetirarPosicao_clicked()
{
    try{
        if(list.getnumberElements()==1){
            QString exit="| |";
            ui->textEditExit->setText(exit);
            ui->lineEditValor->setText(QString::number(list.removePosition(ui->comboBox->currentIndex())));
            ui->comboBox->removeItem(list.getnumberElements()+1);
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }else{
            ui->lineEditValor->setText(QString::number(list.removePosition(ui->comboBox->currentIndex())));
            ui->textEditExit->setText(list.accessAllColored(color));
            ui->comboBox->removeItem(list.getnumberElements()+1);
            ui->lineEditValor->setFocus();
            ui->lineEditElements->setText(QString::number(list.getnumberElements()));
        }
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }
}


void MainWindow::on_pushButtonInsertPosicao_clicked()
{
    try{
        bool ok;
        ui->lineEditValor->text().toInt(&ok);
        if(ui->lineEditValor->text().isEmpty()||!ok) throw QString("input a must be an integer");
        ui->comboBox->addItem(QString::number(list.getnumberElements()));
        list.insertPosition(ui->lineEditValor->text().toInt(),ui->comboBox->currentIndex());


        ui->textEditExit->setText(list.accessAllColored(color));
        ui->lineEditValor->setFocus();
        ui->lineEditValor->clear();
        ui->lineEditElements->setText(QString::number(list.getnumberElements()));
     } catch (QString erro) {
         QMessageBox::warning(this,"ERRO DO SISTEMA",erro);
     }

}

