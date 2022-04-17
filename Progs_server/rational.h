#ifndef RATIONAL_H
#define RATIONAL_H
#include <iostream>
#include <QString>
using namespace std;

class rational
{
    int a, b;
    static QChar SEPARATOR;
    public:
        rational();
        rational(const int&);
        rational(int, int);
        rational(const QByteArray&);

        friend ostream& operator << (ostream&, rational);
        friend istream& operator >> (istream&, rational&);
        friend QString& operator << (QString&, rational);
        friend rational sqrt (rational);
        friend QByteArray& operator>>(QByteArray&,rational&);

        rational operator * (rational);
        rational operator * (int);
        rational operator / (rational);
        rational operator + (rational);
        rational operator - (rational);
        rational operator - ();

        bool operator == (rational);
        bool operator != (rational);
        bool operator > (rational);
        bool operator < (rational);

        static void setSeparator(QChar);
        operator QString ();

        int NOD();

};

#endif //RATIONAL_H
