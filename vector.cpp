#include "vector.h"
#include <iostream>

Vector::Vector(int n)
{
    length=n;
    coords=new double [n];

}

Vector::Vector(int l,double *c)
{
    length=l;
    coords=new double [l];
    for(int i=0; i<l; ++i)
        *(coords+i)=*(c+i);
}

Vector::~Vector()
{
    delete [] coords;
    length = 0;
}

Vector Vector::operator = (const Vector & other)
{
    if (this != &other)
    {
        double *new_coords=new double[other.length];
        for(int i=0; i<other.length; ++i)
            new_coords[i]=other.coords[i];

        delete [] coords;

        coords = new_coords;
        length = other.length;
    };

    return *this;
}

Vector Vector::operator + (const Vector & other)const
{
    if(length != other.length) throw -1;
    Vector sum(length);
    sum.coords=new double[other.length];
    for(int i=0; i<other.length; ++i)
        sum[i]=other.coords[i]+coords[i];
    return sum;
}

Vector Vector::operator % (const int& k) const
{
    Vector new_vector(length);
    new_vector.coords=new double[length];
    for(int i=0; i<length; ++i)
        new_vector[i]=coords[i]*k;
    return new_vector;
}

//Vector Vector::operator ? (const Vector& v) const
//{
  //  Vector new_vector(length);
    //new_vector.coords=new double[length];
    //for(int i=0; i<length; ++i)
     //   new_vector[i]=coords[i]*k;
    //return new_vector;
//}



Vector Vector::operator - (const Vector & other)const
{
    if(length != other.length) throw -1;
    Vector diference(length);
    diference.coords=new double[other.length];
    for(int i=0; i<other.length; ++i)
        diference[i]=coords[i]-other.coords[i];
    return diference;
}

double Vector::operator * (const Vector & other)const
{
    if(length != other.length) throw -1;
    double skalyar;
    for(int i=0; i<other.length; ++i)
        skalyar+=other.coords[i]*coords[i];
    return skalyar;
}

double &Vector::operator[](int i)
{
    if(i<length && i>(-1))
    {
        return coords[i];
    }
    else throw -1;
}
ostream& operator << (ostream& out,const Vector& v) {
	out<<'(';
	for(int i=0;i<v.length;i++)
	{
		out<<v.coords[i];
		if (i!=v.length-1)
			out<<',';
	}
	out<<')';
	return out;
}

