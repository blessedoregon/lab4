#include <iostream>
#include <math.h>
#include "complex.h"

using namespace std;

double Complex::Re() const
{
	return re;
}

double Complex::Im() const
{
	return im;
}

double Complex::R() const
{
	return sqrt(pow(re, 2) + pow(im, 2));
}

double Complex::Phi() const
{
	return atan2(im , re);
}

ostream& operator<<(ostream& out, const Complex& ex)
{
	out << "(" << ex.re << ", " << ex.im << ")";
	return out;
}

istream& operator>>(istream& in, Complex& ex)
{
	in >> ex.re >> ex.im;
	return in;
}

Complex Complex::operator+(const Complex& ex) const
{
	return Complex(re + ex.Re(), im + ex.Im());
}

Complex Complex::operator+(double ex1)
{
	return Complex(ex1 + re, ex1 + im);
}

Complex Complex::operator-(const Complex& ex) const
{
	return Complex(re - ex.Re(), im - ex.Im());
}

Complex Complex::operator*(const Complex& ex) const
{
	return Complex(re * ex.Re() - im * ex.Im(), re * ex.Im() + im * ex.Re());
}

Complex Complex::operator*(int ex1)
{
	return Complex(re * ex1, im * ex1);
}

Complex Complex::operator/(const Complex& ex) const
{
	double r = ex.Re() * ex.Re() + ex.Im() * ex.Im();
	return Complex((re * ex.Re() + im * ex.Im()) / r, (im * ex.Re() - re * ex.Im()) / r);
}

Complex Complex::operator/(int ex1)
{
	return Complex(re / ex1, im / ex1);
}

Complex Complex::operator-() const
{
	return Complex(-re, -im);
}

Complex expp(const Complex& z)

{
	return Complex(std::exp(z.Re()) * cos(z.Im()), std::exp(z.Re()) * sin(z.Im()));
}

Complex cosh(const Complex& z)
{
	return ((expp(z) + expp(-z)) / 2);
}

Complex sinh(const Complex& z)
{
	return ((expp(z) - expp(-z)) / 2);;
}