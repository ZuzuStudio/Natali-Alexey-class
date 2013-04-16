#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

#include <iostream>
using namespace std;


class Vector
{
public:
    Vector(int);
    Vector(int,double *);
    ~Vector();
    Vector operator=(const Vector&);
    Vector operator+(const Vector&) const;
    Vector operator-(const Vector&) const;

    Vector operator%(const int&) const;//умножение вектора на число
    double operator*(const Vector&) const;//скалярное
    double &operator[](int i);
    friend ostream& operator << (ostream&,const Vector&);
private:
    int length;
    double *coords;
};

#endif // VECTOR_H_INCLUDED
