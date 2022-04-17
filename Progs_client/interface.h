#ifndef TINTERFACE_H
#define TINTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QRadioButton>
class TInterface : public QWidget
{
    Q_OBJECT
    QLabel *name_a, *delimeter_a;
    QLineEdit *a_a,*a_b;
    QLabel *name_b, *delimeter_b;
    QLineEdit *b_a,*b_b;
    QLabel *name_c, *delimeter_c;
    QLineEdit *c_a,*c_b;
    QLabel *name_x, *delimeter_x;
    QLineEdit *x_a,*x_b;

    QPushButton *value_btn;
    QPushButton *roots_btn;
    QPushButton *print_classic_btn;
    QPushButton *print_canonic_btn;

    QRadioButton *i_mode;
    QRadioButton *r_mode;

    QLabel *output;

/*
 * Из прошлой работы,
 * public:
    TInterface(QWidget *parent = nullptr);
    ~TInterface();*/

/*public slots:
    void value();
    void print_classic();
    void print_canonic();
    void roots();*/
public:
    TInterface(QWidget *parent = 0);
    ~TInterface();

public slots:
    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);
};
#endif // TINTERFACE_H
