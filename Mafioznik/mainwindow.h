#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

    void on_textBrowser_7_textChanged();

    void on_plusButton_clicked();

    void on_minusButton_clicked();

    void on_plusButton_2_clicked();

    void on_minusButton_2_clicked();

    void on_plusButton_3_clicked();

    void on_minusButton_3_clicked();

    void on_plusButton_4_clicked();

    void on_minusButton_4_clicked();

    void on_plusButton_5_clicked();

    void on_minusButton_5_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
