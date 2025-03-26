#ifndef COMPLEX_H
#define COMPLEX_H


#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class Complex
{
        private:
        double real, imaginary;

    public:
        Complex(double rreal=0, double imag=0);
        Complex(string input);
        ~Complex();

        double getReal();
        double getImaginary();
        void setReal(double rreal);
        void setImaginary(double imag);

        // c = a + b;  instead of  c = a.add(b);
        Complex operator+(const Complex &second) const;
        // a += b;
        void operator+=(const Complex &second);
        Complex operator~();

        // friend functions
        friend istream& operator>>(istream& input, Complex &object);
        friend ostream& operator<<(ostream& output, const Complex &object);
};

#endif // COMPLEX_H


//#include "Complex.h" !!!! we are including the header file because we can't upload the header file in submission

//write the parametrized constructor
Complex::Complex(double rreal, double imag) {
  real = rreal;
  imaginary = imag;
}

//we are assuming string is of format "10.1 20.2"
Complex::Complex(string input) {
  real = imaginary = 0; //additional safety!
  istringstream(input) >> real >> imaginary;
}
Complex::~Complex()
{
    cout <<"Destructor called" << endl;
}

//Write getters and setters
double Complex::getReal() {
  return real;
}

double Complex::getImaginary() {
  return imaginary;
}

void Complex::setReal(double rreal){
  real = rreal;
}

void Complex::setImaginary(double imag){
  imaginary = imag;
}

//write overloaded operators for + and =+
//we'll return complex object by value
//return void for +=
Complex Complex::operator+(const Complex &second) const {
  return Complex(real + second.real, imaginary + second.imaginary);

  /* In other words,
  Complex result
  result.setReal(this->real + second.real);
  result.setImaginary(this->imaginary + second.imaginary);
  return result;
  "this" is a pointer to object that is called the function
  
 return Complex(this->real + second.real, this->imaginary + second.imaginary);
 */
}

//return conjugate?
Complex Complex::operator~() {
  return Complex(real, -imaginary);
}

//treat input like cin
//basically, overload >> operator to do cin >> c1;
istream& operator>>(istream& input, Complex &object) {
  input >> object.real >> object.imaginary;
  return input; //return cin allows chaining cin >> c1 >> c2
}

//treat output like cout

ostream& operator<<(ostream& output, const Complex &object) {
  output << "(" << object.real << ","
                << object.imaginary << ")";
  return output;
}
