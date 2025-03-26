#include "Complex.h"

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
//return void for +=
void Complex::operator+=(const Complex &second) {
  real += second.real;
  imaginary += second.imaginary;
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
