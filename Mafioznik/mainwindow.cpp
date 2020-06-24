#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QLineEdit"
#include "mafia.h"
#include "QMessageBox"
static Mafia M1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    setWindowTitle("Mafioznik v1.0");

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString players = ui->players->text();
    if(players==nullptr){
         QMessageBox::about(this,"Padazhi", "Snachala vvedi imena igrokov!       ");
    }else{
    if(players.at(players.length()-1) != " "){
    players.append(" ");
    }

    QVector<QString> playersarr;
    int n = 0;
     QString temp;
     //zapisyvaem iz stringa v vector
    for(int i =0; i< players.length(); i++){

        if(players.at(i)==" "){
            if(temp != nullptr){
                playersarr.append(temp);
                temp.clear();
                n++;
            }
        }else{
        temp.append(players.at(i));
        }
    }
    M1.MinusaAllMir();
    //dobavliaem mirnyh
    int nedost = playersarr.length()-M1.size();
    for(int i =0 ; i< nedost ;i++){
        M1.AddMir();
    }

    if(playersarr.length() >= M1.size()){
    //vyvod roley
    QVector<int> perechen;
    ui -> listView ->clear();
    for(int i= 0; i < M1.size(); i++){
        bool bylo = 0;
        int random1 =  rand() % playersarr.length();
        for(int i = 0; i < perechen.length(); i++){
            if(random1==perechen[i]){
                bylo = 1;
            }
        }
        QString s = M1.getRoles()[i];
        if(bylo == 1){
            i--;
        }else{
        s.append("(player "+QString::number(random1+1)+")");
        perechen.append(random1);
    ui -> listView ->addItem(s);
        }
    }


      //vyvodim spisok
      ui -> randomchik ->clear();
       int playersamount =  playersarr.length();

      for(int i=0; i <playersamount;i++){
        QString push;
        push = QString::number(i+1);
        int random1 =  rand() % playersarr.length();
        push.append(". ");
        push.append(playersarr[random1]);
        playersarr.remove(random1);
        ui ->randomchik->append(push );
        }
    } else{
         QMessageBox::about(this,"Padazhi", "Slishkom mnogo roley! Ubiray        ");
    }
    }
}

void MainWindow::on_textBrowser_7_textChanged()
{

}

void MainWindow::on_plusButton_clicked()
{
    M1.AddMafia();
    ui->textBrowser_7->setText(QString::number(M1.getAmountMafia()));
}


void MainWindow::on_minusButton_clicked()
{   if(M1.getAmountMafia()==0){
        QMessageBox::about(this,"Padazhi", "Krasavica, tak delat' nel'zya!       ");

    }else{
    M1.MinusMafia();
    ui->textBrowser_7->setText(QString::number(M1.getAmountMafia()));
    }
}

void MainWindow::on_plusButton_2_clicked()
{
    M1.AddKom();
    ui->textBrowser_8->setText(QString::number(M1.getAmountKom()));
}

void MainWindow::on_minusButton_2_clicked()
{
    if(M1.getAmountKom()==0){
           QMessageBox::about(this,"Padazhi", "Krasavica, tak delat' nel'zya!       ");

       }else{
        M1.MinusKom();
        ui->textBrowser_8->setText(QString::number(M1.getAmountKom()));

       }

}

void MainWindow::on_plusButton_3_clicked()
{
    M1.AddDoc();
    ui->textBrowser_9->setText(QString::number(M1.getAmountDoc()));
}

void MainWindow::on_minusButton_3_clicked()
{
    if(M1.getAmountDoc()==0){
           QMessageBox::about(this,"Padazhi", "Krasavica, tak delat' nel'zya!       ");

       }else{
        M1.MinusDoc();
        ui->textBrowser_9->setText(QString::number(M1.getAmountDoc()));

       }

}

void MainWindow::on_plusButton_4_clicked()
{
    M1.AddManiac();
    ui->textBrowser_10->setText(QString::number(M1.getAmountManiac()));
}

void MainWindow::on_minusButton_4_clicked()
{
    if(M1.getAmountManiac()==0){
           QMessageBox::about(this,"Padazhi", "Krasavica, tak delat' nel'zya!       ");

       }else{
        M1.MinusManiac();
        ui->textBrowser_10->setText(QString::number(M1.getAmountManiac()));

       }


}

void MainWindow::on_plusButton_5_clicked()
{
    M1.AddPrositutka();
    ui->textBrowser_11->setText(QString::number(M1.getAmountProstitutka()));
}

void MainWindow::on_minusButton_5_clicked()
{
    if(M1.getAmountProstitutka()==0){
           QMessageBox::about(this,"Padazhi", "Krasavica, tak delat' nel'zya!       ");

       }else{
        M1.MinusProstitutka();
        ui->textBrowser_11->setText(QString::number(M1.getAmountProstitutka()));

       }

}
