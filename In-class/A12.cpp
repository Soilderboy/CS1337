/*Psuedocode:
So I'm given a circle class

I need to instantiate c1 a circle object
Set the radius and print the data of it

Then a pointer to c2 and set the radius through that
Print the data through the pointer

When defining functions in the class, I just do it like Circle::function() {}

The const keyword after a function means the function can't change the object's data members - meaning read-only
*/

// This program demonstrates a simple class.
#include <iostream>
using namespace std;

#define PI 3.14
// Circle class declaration.
class Circle
{
   private:
      double radius;

   public:
      void setRadius(double);
      double getRadius() const;
      double getDiameter() const;
      double getArea() const;
};


// setRadius assigns a value to the radius member.
void Circle::setRadius(double r){
   radius = r;
}

// getRadius assigns a value to the radius member.
double Circle::getRadius() const{
   return radius;
}

// getDiameter 
double Circle::getDiameter() const{
   return radius * 2;
}

// getArea
double Circle::getArea() const{
   return PI * radius * radius;
}

int main()
{
   Circle c1;     // Define an instance of the Circle class
   double rad, rad1;  // Local variable for radius

   // Get the radius from the user.
   cout << "This program will calculate the area of a circle.\n";
   cout << "What is the radius? ";
   cin >> rad;
   
   cout << "What is the radius of the object pointed by c2? ";
   cin >> rad1;


   // Store the radius of the circle in the c1 object.
   if(rad < 0){ //input validation
      cout << "Radius must be a positive value" << endl;
      return -1;
   }
   c1.setRadius(rad);

 

   // Display the circle's data.
   cout << "\nHere is the circle's data:\n";
   cout << "Radius: " << c1.getRadius() << endl;
   cout << "Diameter: " << c1.getDiameter() << endl;
   cout << "Area: " << c1.getArea() << endl;

    Circle *c2 = new Circle;
    

   // Store the radius of the circle in the c2 object.
   if(rad1 < 0){ //input validation
      cout << "Radius must be a positive value" << endl;
      return -1;
   }
   c2->setRadius(rad1);
   

   // Display the circle's data.
   cout << "\nHere is the circle's data through the pointer:\n";
   cout << "Radius: " << c2->getRadius() << endl;
   cout << "Diameter: " << c2->getDiameter() << endl;
   cout << "Area: " << c2->getArea() << endl;

   return 0;
}
