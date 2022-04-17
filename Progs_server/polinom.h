#ifndef TPOLINOM_H
#define TPOLINOM_H
#include <iostream>
#include "rational.h"
#include <QString>
#include <cmath>
using namespace std;

enum EPrintMode
{
    EPrintModeClassic, EPrintModeCanonic,
};

template <class number>
class TPolinom
{
    EPrintMode printMode;
    number a, b, c;
public:
    TPolinom(number,number,number);
    template <class T>
    friend ostream& operator<< (ostream&,TPolinom<T>&);
    number value(number);
    void setPrintMode(EPrintMode);
    int roots(number &x1,number &x2);
    template <class T>
    friend QString& operator << (QString&, TPolinom<T>&);
};

template<class number>
TPolinom<number>::TPolinom(number x,number y,number z)
{
    printMode = EPrintModeClassic;
    a = x;
    b = y;
    c = z;
}
template<class number>
ostream& operator<< (ostream& os,TPolinom<number>& p)
{
    if (p.printMode == EPrintModeClassic)
        {
            os << p.a << "x^2";
            if (p.b < 0)
            os << p.b << "x";
            else
            os << "+" << p.b << "x";
            if (p.c < 0)
            os << p.c;
            else
            os << "+" << p.c;
        }
        else
            {
                number x1,x2;
                 p.roots(x1,x2);
                 os<<p.a;
                 if (x1<0)
                     os<<"(x+"<<-x1<<")";
                 else if(x1==0)
                    os<<"x*";
                 else
                     os<<"(x-"<<x1<<")";
                 if (x2<0)
                     os<<"(x+"<<-x2<<")";
                 else if(x2==0)
                     os<<"x";
                 else os<<"(x-"<<x2<<")";
                }
                return os;
}

template<class number>
number TPolinom<number>::value(number x)
{
    number v;
    v=a*x*x+b*x+c;
    return v;
}
template<class number>
void TPolinom<number>::setPrintMode(EPrintMode m)
{
    printMode = m;
}
template<class number>
int TPolinom<number>::roots (number &x1, number &x2)
{
    number D=b*b-a*c*4;
    if(D > 0)
    {
        x1 = (-b + sqrt(D)) / (a*2);
        x2 = (-b - sqrt(D)) / (a*2);
        return 1;
    }
    else if (D == 0)
    {
        x1 = (-b)/(a*2);
        x2 = x1;
        cout << "D=0 => only 1 root: x_1 = " << x1<< endl;
        return 1;
    }
    else
    {
        cout<<"No roots"<<endl;
        return 0;
    }
    if (value(x1)!=0 && value(x2)!=0)
    {
       cout << "No roots" << endl;
       return 0;
    }
    return 3;
}
template<class number>
QString& operator << (QString& s, TPolinom<number>& p)
{
    if (p.printMode == EPrintModeClassic)
    {
       s << p.a+= "x^2";
       if (p.b < 0)
       s << p.b += "x";
    else
       {
        s += "+";
        s<< p.b += "x";
       }
        if (p.c < 0)
            s << p.c;
        else
        {
         s += "+";
         s<< p.c;
        }
    }
    else
    {
        number x1,x2;
        p.roots(x1,x2);
        s<<p.a;
        if (x1<0)
        {
         s+="(x+";
         s<<-x1+=")";
        }
         else
            if(x1==0)
             s+="x*";
         else
            {
             s+="(x-";
             s<<x1+=")";
            }
         if (x2<0)
         {
          s+="(x+";
          s<<-x2+=")";
         }
         else
             if(x2==0)
              s+="x";
         else
             {
              s+="(x-";
              s<<x2+=")";
             }
    }
    return s;
}

#endif // TPOLINOM_H
