#include <iostream>
#include <cmath>

class Complex
{
private:
	double re;
	double im;
public:
	Complex() { re = 0; im = 0; };
	Complex(double r, double i) { re = r; im = i; }
	Complex(double r) { re = r; im = 0; }
	~Complex() {}   // Деструктор
	double Re() const;
	double Im() const;
	double R() const;
	double Phi() const;
	double cosh(Complex z) const;
	double exp(Complex z) const;

	Complex operator+(const Complex&) const;   // Перегрузка оператора сложения
	Complex operator+(double ex1);
	Complex operator-(const Complex&) const;   // Перегрузка оператора вычитания
	Complex operator*(const Complex&) const; // Перегрузка оператора умножения
	Complex operator/(const Complex&) const; // Перегрузка оператора деления
	Complex operator*(int ex1);// Перегрузка оператора умножения Const на комплексное число
	Complex operator/(int ex1);
	Complex operator-() const;
	friend std::ostream& operator<<(std::ostream& out, const Complex& ex);
	friend std::istream& operator>>(std::istream& in, Complex& ex);
};

Complex expp(const Complex& z);
Complex cosh(const Complex& z);
Complex sinh(const Complex& z);