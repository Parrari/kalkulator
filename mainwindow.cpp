#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Kalkulator");

    ui->centralWidget->setStyleSheet("background-color: #535353;" "color: white;");
    ui->screen->setStyleSheet("background-color: white;" "color: blue;");

    Left=0;
    Right=0;
    isLeft=false;
    isRight=false;
    Opt=Operations::none;
    memory = "0";
    wynik=0;
    isNew=true;
    isComma=false;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_N0_clicked()
{
    QString text = ui->screen->text();
    if(text=="0" || text.length()>=ui->screen->maxLength()) return;
    if (!isNew) ui->screen->setText(text+"0");
    else ui->screen->setText("0");
    isNew=false;
}

void MainWindow::on_N1_clicked()
{
    AddToScreen("1");
    isNew=false;
}

void MainWindow::on_N2_clicked()
{
    AddToScreen("2");
    isNew=false;
}

void MainWindow::on_N3_clicked()
{
    AddToScreen("3");
    isNew=false;
}

void MainWindow::on_N4_clicked()
{
    AddToScreen("4");
    isNew=false;
}

void MainWindow::on_N5_clicked()
{
    AddToScreen("5");
    isNew=false;
}

void MainWindow::on_N6_clicked()
{
    AddToScreen("6");
    isNew=false;
}

void MainWindow::on_N7_clicked()
{
    AddToScreen("7");
    isNew=false;
}

void MainWindow::on_N8_clicked()
{
    AddToScreen("8");
    isNew=false;
}

void MainWindow::on_N9_clicked()
{
    AddToScreen("9");
    isNew=false;
}

void MainWindow::AddToScreen(QString num){
    QString text = ui->screen->text();
    if(text.length()>=ui->screen->maxLength()) return;
    if(text=="0" || isNew) ui->screen->setText(num);
    else ui->screen->setText(text+num);
}


void MainWindow::on_multiply_clicked()
{
    QString text = ui->screen->text();


    if(!isLeft) Left=text.toDouble();
    else {
        Right=text.toDouble();
        if(!isNew) on_equal_clicked();}

    if(isRight==false) ui->screen->setText(QString::number(Left));
    else if(!isNew) ui->screen->setText(QString::number(wynik));

    isComma=false;
    isNew=true;
    isLeft=true;
    isRight=false;
    Opt=this->multiply;
}

void MainWindow::on_divide_clicked()
{
    QString text = ui->screen->text();


    if(!isLeft) Left=text.toDouble();
    else {
        Right=text.toDouble();
        if(!isNew) on_equal_clicked();}

    if(isRight==false) ui->screen->setText(QString::number(Left));
    else if(!isNew) ui->screen->setText(QString::number(wynik));

    isComma=false;
    isNew=true;
    isLeft=true;
    isRight=false;
    Opt=this->divide;
}

void MainWindow::on_plus_clicked()
{
    QString text = ui->screen->text();


    if(!isLeft) Left=text.toDouble();
    else {
        Right=text.toDouble();
        if(!isNew) on_equal_clicked();}

    if(isRight==false) ui->screen->setText(QString::number(Left));
    else if(!isNew) ui->screen->setText(QString::number(wynik));

    isComma=false;
    isNew=true;
    isLeft=true;
    isRight=false;
    Opt=this->plus;
}

void MainWindow::on_minus_clicked()
{
    QString text = ui->screen->text();


    if(!isLeft) Left=text.toDouble();
    else {
        Right=text.toDouble();
        if(!isNew) on_equal_clicked();}

    if(isRight==false) ui->screen->setText(QString::number(Left));
    else if(!isNew) ui->screen->setText(QString::number(wynik));

    isComma=false;
    isNew=true;
    isLeft=true;
    isRight=false;
    Opt=this->minus;
}

void MainWindow::on_equal_clicked()
{
    if(!isLeft) return;

    QString text = ui->screen->text();


        if(isRight==false) {
            Right=text.toDouble();
            isRight=true;}

    double tmp;
    switch(Opt){
    case plus:
        tmp=Left+Right;
        break;
    case minus:
        tmp=Left-Right;
        break;
    case multiply:
        tmp=Left*Right;
        break;
    case divide:
        tmp=Left/Right;
        break;
    }
    wynik=tmp;
    if(!isNew) ui->screen->setText(QString::number(tmp));
    Left=(ui->screen->text()).toDouble();
    isNew=true;
    isComma=false;
    isLeft=false;
}

void MainWindow::on_clear_screen_clicked()
{
    Left=0;
    Right=0;
    wynik=0;
    isComma=false;
    isNew=true;
    isLeft=false;
    isRight=false;
    Opt=Operations::none;
    ui->screen->setText("0");
}


void MainWindow::on_comma_clicked()
{
    if(!isComma) {
        QString text = ui->screen->text();
        if(text.length()>=ui->screen->maxLength()) return;
        if(isNew) ui->screen->setText("0.");
        else ui->screen->setText(text+".");
        isNew=false;}
    else return;
    isComma=true;
}

void MainWindow::on_memory_add_clicked()
{
    memory = ui->screen->text();
    ui->memory_read->setStyleSheet("color: #ceb008;");
}

void MainWindow::on_memory_read_clicked()
{
    ui->screen->setText(memory);
    isNew=false;
}

void MainWindow::on_memory_clear_clicked()
{
    memory = "0";
    ui->memory_read->setStyleSheet("color: white;");
}
