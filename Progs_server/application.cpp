#include "application.h"
#include "polinom.h"
#include "common.h"
#include <cmath>
#include "rational.h"

QByteArray& operator>>(QByteArray& arr, int& c)
{
    int p = arr.indexOf(separator);

    if (p > 0)
    {
        c = atoi(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

QString& operator<<(QString& s, const int &c){
    s += QString().setNum(c);
    return s;
}

TApplication::TApplication(int argc, char *argv[])
            : QCoreApplication(argc,argv)
{
    TCommParams pars = { QHostAddress("127.0.0.1"), 10000,
                         QHostAddress("127.0.0.1"), 10001};
    comm = new TCommunicator(pars, this);

    connect(comm,SIGNAL(recieved(QByteArray)),this,SLOT(recieve(QByteArray)));
}

void TApplication::recieve(QByteArray msg)
{
    QString answer, s;
    int pos = msg.indexOf(separator);
    int t,mode = msg.left(pos).toInt();
    msg=msg.right(msg.length()-pos-1);
    if(mode==R_MODE){
    rational a, b, c, x, v,x1,x2;
    msg>>a>>b>>c;
    TPolinom<rational> p(a,b,c);
    pos = msg.indexOf(separator);
    t = msg.left(pos).toInt();
    switch (t)
    {
        case VALUE_REQUEST:
            msg = msg.right(msg.length()-pos-1);
            msg>>x;
            v = p.value(x);
            s<<(QString)x<<(QString)v;
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
        case PRINT_CLASSIC_REQUEST:
            p.setPrintMode(EPrintModeClassic);
            s<<p;
            answer<<QString().setNum(PRINT_ANSWER)<<s;
            break;
        case ROOTS_REQUEST:
            if(p.roots(x1,x2)==0)
            {
                s<<"No roots";
                answer<<QString().setNum(NOROOTS_ANSWER)<<s;
            }else
            {
                s<<(QString)x1<<(QString)x2;
                answer<<QString().setNum(ROOTS_ANSWER)<<s;
            }
            break;
        case PRINT_CANONIC_REQUEST:
            if (p.roots(x1,x2)==0)
            {
                s<<"No roots";
                answer<<QString().setNum(NOROOTS_ANSWER)<<s;
            }
            else
            {
                p.setPrintMode(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
            }
         break;
        default: return;
        }
    }
    if(mode == I_MODE)
      {
        int a, b, c, x, v;
        //msg>>a>>b>>c;
        int pos = msg.indexOf(';');
        a = msg.left(pos).toInt();
        msg = msg.right(msg.length()-pos-1);
        pos = msg.indexOf(';');
        b = msg.left(pos).toInt();
        msg = msg.right(msg.length()-pos-1);
        pos = msg.indexOf(';');
        c = msg.left(pos).toInt();
        msg = msg.right(msg.length()-pos-1);
        TPolinom<int> p(a,b,c);
        pos = msg.indexOf(';');
        int t = msg.left(pos).toInt();
        msg = msg.right(msg.length()-pos-1);
        int x1,x2;
        switch (t)
        {
            case VALUE_REQUEST:
            pos = msg.indexOf(';');
            x = msg.left(pos).toInt();
            v = p.value(x);
            s<<("("+QString().setNum(x)+")")<<QString().setNum(v);
            answer<<QString().setNum(VALUE_ANSWER);
            answer += s;
            break;
            case ROOTS_REQUEST:
                 if(p.roots(x1,x2)==0)
                  {
                      s<<"No roots";
                      answer<<QString().setNum(NOROOTS_ANSWER)<<s;
                  }else{
                     msg = msg.right(msg.length()-pos-1);
                     s<<("("+QString().setNum(x1)+")")<<(QString().setNum(x2)+");");
                     answer<<QString().setNum(ROOTS_ANSWER);
                     answer += s;
                  }
                break;
            case PRINT_CLASSIC_REQUEST:
                    p.setPrintMode(EPrintModeClassic);
                    s<<p;
                    answer<<QString().setNum(PRINT_ANSWER)<<s;
                break;
            case PRINT_CANONIC_REQUEST:
            if (p.roots(x1,x2)==0)
            {
                s<<"No roots";
                answer<<QString().setNum(NOROOTS_ANSWER)<<s;
            }
            else{
                p.setPrintMode(EPrintModeCanonic);
                s<<p;
                answer<<QString().setNum(PRINT_ANSWER)<<s;
            }
             break;

            default: return;
        }
      }
    comm->send(QByteArray().append(answer));
}

