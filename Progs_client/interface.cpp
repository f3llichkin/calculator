#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №5");
    setFixedSize(300,290);
    name_a = new QLabel("a =",this);
    name_a->setGeometry(40,20,30,25);
    a_a = new QLineEdit("1",this);
    a_a->setGeometry(90,20,50,25);
    delimeter_a = new QLabel("/",this);
    delimeter_a->setGeometry(150,20,30,25);
    a_b = new QLineEdit("1",this);
    a_b->setGeometry(165,20,50,25);

    name_b = new QLabel("b =",this);
    name_b->setGeometry(40,50,30,25);
    b_a = new QLineEdit("1",this);
    b_a->setGeometry(90,50,50,25);
    delimeter_b = new QLabel("/",this);
    delimeter_b->setGeometry(150,50,30,25);
    b_b = new QLineEdit("1",this);
    b_b->setGeometry(165,50,50,25);

    name_c = new QLabel("c =",this);
    name_c->setGeometry(40,80,30,25);
    c_a = new QLineEdit("1",this);
    c_a->setGeometry(90,80,50,25);
    delimeter_c = new QLabel("/",this);
    delimeter_c->setGeometry(150,80,30,25);
    c_b = new QLineEdit("1",this);
    c_b->setGeometry(165,80,50,25);

    name_x = new QLabel("x =",this);
    name_x->setGeometry(40,110,30,25);
    x_a = new QLineEdit("1",this);
    x_a->setGeometry(90,110,50,25);
    delimeter_x = new QLabel("/",this);
    delimeter_x->setGeometry(150,110,30,25);
    x_b = new QLineEdit("1",this);
    x_b->setGeometry(165,110,50,25);

    roots_btn = new QPushButton ("roots",this);
    roots_btn->setGeometry(20,150,60,30);
    value_btn = new QPushButton ("value",this);
    value_btn->setGeometry(90,150,60,30);
    print_classic_btn = new QPushButton ("classic",this);
    print_classic_btn->setGeometry(160,150,60,30);
    print_canonic_btn = new QPushButton ("canonic",this);
    print_canonic_btn->setGeometry(230,150,60,30);

    i_mode=new QRadioButton("Целые",this);
    i_mode->setGeometry(10,200,130,25);
    r_mode=new QRadioButton("Рациональные",this);
    r_mode->setGeometry(160,200,130,25);
    i_mode->setChecked(true);

    output = new QLabel(this);
    output->setGeometry(10,240,280,25);


    connect(value_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(print_classic_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(roots_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
    connect(print_canonic_btn,SIGNAL(pressed()),this,SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete name_a;
    delete a_a;
    delete delimeter_a;
    delete a_b;

    delete name_b;
    delete b_a;
    delete delimeter_b;
    delete b_b;

    delete name_c;
    delete c_a;
    delete delimeter_c;
    delete c_b;

    delete name_x;
    delete x_a;
    delete delimeter_x;
    delete x_b;

    delete value_btn;
    delete roots_btn;
    delete print_classic_btn;
    delete print_canonic_btn;

    delete i_mode;
    delete r_mode;
    delete output;

}
 /*
  * Из прошлой работы,void TInterface::value()
{
    number a(a_a->text().toInt(),a_b->text().toInt());
    number b(b_a->text().toInt(),b_b->text().toInt());
    number c(c_a->text().toInt(),c_b->text().toInt());
    TPolinom p(a, b, c);
    number x(x_a->text().toInt(),x_b->text().toInt());
    number v = p.value(x);
    QString s("p");
    s << x;
    s += "=";
    s << v;
    output->setText(s);
}
void TInterface::print_classic()
{
    number a(a_a->text().toInt(),a_b->text().toInt());
    number b(b_a->text().toInt(),b_b->text().toInt());
    number c(c_a->text().toInt(),c_b->text().toInt());
    TPolinom p(a, b, c);
    p.setPrintMode(EPrintModeClassic);
    QString s("p(x)=");
    s<<p;
    output->setText(s);
}
void TInterface::print_canonic()
{
    number x1,x2;
    number a(a_a->text().toInt(),a_b->text().toInt());
    number b(b_a->text().toInt(),b_b->text().toInt());
    number c(c_a->text().toInt(),c_b->text().toInt());
    TPolinom p(a, b, c);
    if (p.roots(x1,x2)==0)
    {
        QString p("No roots");
        output->setText(p);
    }
    else
    {
    p.setPrintMode(EPrintModeCanonic);
    QString s("p(x)=");
    s<<p;
    output->setText(s);
    }
}
void TInterface::roots()
{
    number x1,x2;
    number a(a_a->text().toInt(),a_b->text().toInt());
    number b(b_a->text().toInt(),b_b->text().toInt());
    number c(c_a->text().toInt(),c_b->text().toInt());
    TPolinom p(a, b, c);
    if (p.roots(x1,x2)==0)
    {
        QString p("No roots");
        output->setText(p);
    }
    else
    {
        QString s("x1=");
        s<<x1;
        s+="; x2=";
        s<<x2;
        s+=";";
        output->setText(s);
    }
}*/
void TInterface::formRequest()
{
    QString msg;
    if(i_mode->isChecked()){
    msg<< QString().setNum(I_MODE);
    msg << a_a->text();
    msg << b_a->text();
    msg << c_a->text();
    }else{
        msg<< QString().setNum(R_MODE);
        msg << a_a->text() << a_b->text();
        msg << b_a->text() << b_b->text();
        msg << c_a->text() << c_b->text();

    }
   /* msg << a_a->text() << a_b->text();
    msg << b_a->text() << b_b->text();
    msg << c_a->text() << c_b->text();*/
    QPushButton *btn = (QPushButton*)sender();
    if (btn == value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        if(i_mode->isChecked())
            msg << x_a->text();
        else
            msg << x_a->text() << x_b->text();
    }
    if (btn == print_classic_btn){
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
        if(i_mode->isChecked())
            msg << x_a->text();
        else
            msg << x_a->text() << x_b->text();
    }
    if (btn == roots_btn){
        msg << QString().setNum(ROOTS_REQUEST);
        if(i_mode->isChecked())
            msg << x_a->text();
        else
            msg << x_a->text() << x_b->text();
    }
    if (btn == print_canonic_btn){
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
        if(i_mode->isChecked())
            msg << x_a->text();
        else
            msg << x_a->text() << x_b->text();

    }
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            break;
        case ROOTS_ANSWER:
            text = "x_1=";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += "; x_2=(";
            text += msg.right(p);
            output->setText(text);
        break;
        case NOROOTS_ANSWER:
        p = msg.indexOf(separator);
        text+=msg.left(p);
            output->setText(text);
        break;
        default: break;
    }
}
