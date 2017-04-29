#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_N0_clicked();

    void on_N1_clicked();

    void on_N2_clicked();

    void on_N3_clicked();

    void on_N4_clicked();

    void on_N5_clicked();

    void on_N6_clicked();

    void on_N7_clicked();

    void on_N8_clicked();

    void on_N9_clicked();

    void AddToScreen(QString num);

    void on_multiply_clicked();

    void on_divide_clicked();

    void on_plus_clicked();

    void on_minus_clicked();

    void on_equal_clicked();

    void on_clear_screen_clicked();

    void on_comma_clicked();

    void on_memory_add_clicked();

    void on_memory_read_clicked();

    void on_memory_clear_clicked();

private:
    Ui::MainWindow *ui;

public:
    enum Operations{
        plus,
        minus,
        multiply,
        divide,
        none
    };

    double Left, Right, wynik;
    bool isLeft, isRight, isNew, isComma;
    int Opt;
    QString memory;
};

#endif // MAINWINDOW_H
