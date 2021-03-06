#include "stdafx.h"
#include <iostream>
using namespace std;

class complex
{
private:                  
	double re, im;

public:
	//complex(double x, double y) : re(x), im(y) 
	complex(double x = 0, double y = 0)
	{
		re = x;
		im = y;
	}

	//constructor de copiere
	complex(const complex& c)
	{
		re = c.re;
		im = c.im;
	}

	// destructor
	~complex() {}

	complex suma(complex c)
	{
		return complex(c.re + re, c.im + im);   
	}

	complex dif(complex c)
	{
		return complex(re - c.re, im - c.im);
	}

	complex inmultire(complex c)
	{
		return complex(c.re*re - c.im*im, c.re*im + c.im*re);
	}

	complex multi(double x)
	{
		return complex(re*x, im*x);
	}

	
	complex div(complex c)
	{
		complex r = this->inmultire(c.conjugat());
		r=r.inmultire(1 / c.modul2());
		return r;
	}

	complex operator+(const complex& c)
	{
		return complex(c.re + re, c.im + im);
	}

	complex operator-(const complex& c)
	{
		return complex(re - c.re, im - c.im);
	}

	complex operator*(const complex& c)
	{
		return complex(c.re*re - c.im*im, c.re*im + c.im*re);
	}

	complex operator*(const double& x) 
	{
		return complex(re*x, im*x);
	}

	complex operator/(complex& c) {
		complex r = this->inmultire(c.conjugat());
		r = r.inmultire(1 / c.modul2());
		return r;
	}

	complex& operator=(const complex& c)  
	{
		im = c.im;
		re = c.re;
		return *this;       
	}

	double modul2() const
	{
		return re*re + im*im;
	}

	complex conjugat() const
	{
		return complex(re, -im);
	}

	void set_im(double im)
	{
		this->im = im;
	}

	void set_re(double re)
	{
		this->re = re;
	}

	double get_im()
	{
		return im;
	}

	double get_re()
	{
		return re;
	}

	void show()
	{
		cout << "re: " << re << "     im: " << im << endl;
	}

	
	friend ostream& operator<<(ostream& os, const complex& c)
	{
		return os << c.re << " " << c.im;
	}

	friend  istream& operator>>(istream& is, complex& c)
	{
		return is >> c.re >> c.im;
	}

};


int main()
{

	a.show();
	b.show();
	c.show();

	//complex d = c;   
	d.show();*/

	complex a(4, 5), b(-2, 3);
	
	//a.suma(b).show();

	//a.div(b).show();

	(a + b - a*a / b).show();

	complex x = a;  
	
	complex y;
	y = a;  

	cout << a;

	return 0;
}


