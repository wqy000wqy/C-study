#include<iostream>
#include<stdio.h>
using namespace std;
class Complex
{
	private:
	double real;
	double imag;
	public:
	Complex ()
	{
		real=0;imag=0;
		
	}
	Complex(double a,double b)
	{
		real =a;
		imag=b;
	}
	Complex operator+(Complex c2)
	{
		Complex c;
		c.real=real+c2.real;
		c.imag=imag+c2.imag;
		return c;
	}
		Complex operator-(Complex c2)
	{
		Complex c;
		c.real=real-c2.real;
		c.imag=imag-c2.imag;
		return c;
	}
		Complex operator*(Complex c2)
	{
		Complex c;
		c.real=real*c2.real;
		c.imag=imag*c2.imag;
		return c;
	}
		Complex operator/(Complex c2)
	{
		Complex c;
		c.real=real/c2.real;
		c.imag=imag/c2.imag;
		return c;
	}
	void display()
	{
		cout<<"("<<real<<","<<imag<<"i)"<<endl;
	}
} ;


int main()
{
	Complex c1(3,4),c2(5,-10),c3;
	c3=c1+c2;
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c3=";c3.display();
	c3=c1-c2;
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c3=";c3.display();
	c3=c1*c2;
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c3=";c3.display();
	c3=c1/c2;
	cout<<"c1=";c1.display();
	cout<<"c2=";c2.display();
	cout<<"c3=";c3.display();
	return 0;
	
}
