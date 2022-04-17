#include "rational.h"
#include <iostream>
#include <cmath>
#include "common.h"
using namespace std;

QChar rational::SEPARATOR = separator;

rational::rational()
{

}
rational::rational(const int& x)
{
    a = x;
    b = 1;
}
rational::rational(int x,  int y)
{
    a = x;
    b = y;
}
istream& operator >> (istream& is, rational& r)
{
    is >> r.a;
    is >> r.b;
    return is;
}
int rational::NOD()
{
    int a1 = abs(a);
    int b1 = abs(b);
    while (a1 != b1)
    {
        if (a1 > b1)
        {
            int div = a1;
            a1 = b1;
            b1 = div;
        }
        b1 = b1 - a1;
    }
    a = a / a1;
    b = b / a1;
    return 0;
}
 ostream& operator << (ostream& os, rational r)
 {
     r.NOD();
     if (r.b == 1)
     {
         os << r.a;
     }
     else if(r.b == -1)
     {
         os << -r.a;
     }
     else
     {
        os << r.a << "/" << (r.b);
     }
     return os;
 }
 rational rational :: operator * (rational r)
{
     rational t;
     t.a = a * r.a;
     t.b = b * r.b;
     t.NOD();
     return t;
}
 rational rational :: operator * (int r)
{
     rational t;
     t.a = a * r;
     t.b = b;
     t.NOD();
    return t;
}
rational rational :: operator / (rational r)
{
     rational t;
     t.a = a * r.b;
     t.b = b * r.a;
     if (t.b < 0)
     {
         t.a = -1*t.a;
         t.b = -1*t.b;
     }
     t.NOD();
    return t;
}
rational rational :: operator + (rational r)
{
     rational t;
     t.a = a * r.b + r.a * b;
     t.b = b * r.b;
     t.NOD();
     return t;
}
rational rational :: operator - (rational r)
{
     rational t;
     t.a = a * r.b - r.a * b;
     t.b = b * r.b;
     t.NOD();
     return t;
}
rational rational :: operator - ()
{
     rational t;
     t.a = -a;
     t.b = b;
     t.NOD();
     return t;
}
bool rational :: operator == (rational r)
{
    return ((double(a) / double(b)) == ((double(r.a) / double(r.b))));
}
bool rational :: operator != (rational r)
{
    return ((double(a) / double(b)) != ((double(r.a) / double(r.b))));
}
bool rational :: operator < (rational r)
{
    return ((double(a) / double(b)) < ((double(r.a) / double(r.b))));
}
bool rational :: operator > (rational r)
{
    return ((double(a) / double(b)) > ((double(r.a) / double(r.b))));
}
rational sqrt(rational r)
{
    rational t;
    t.a = int(sqrt(r.a));
    t.b = int(sqrt(r.b));
    return t;
}

QString& operator << (QString& s, rational r)
{
    r.NOD();
    s+="(";
    if (r.b == 1)
    {
        s+=QString().setNum(r.a);
    }
    else if(r.b == -1)
    {
        s+=QString().setNum(-r.a);
    }
    else
    {
       s+=QString().setNum(r.a);
       s+="/";
       s+=QString().setNum(r.b);
    }
    s+=")";
    return s;
}

rational::rational(const QByteArray& arr)
{
    int p = arr.indexOf(SEPARATOR);
    a = arr.left(p).toDouble();
    b = arr.right(arr.length()-p-1).toDouble();
}

QByteArray& operator>>(QByteArray& arr, rational& c)
{
    int p = arr.indexOf(rational::SEPARATOR);
    p = arr.indexOf(rational::SEPARATOR,p+1);
    if (p > 0)
    {
        c = rational(arr.left(p));
        arr = arr.right(arr.length()-p-1);
    }
    return arr;
}

void rational::setSeparator(QChar ch)
{
    SEPARATOR = ch;
}
rational::operator QString ()
{
    QString s = "(";
    s += QString().setNum(a);
    s += "/";
    s += QString().setNum(b);
    s += ")";
    return s;
}
