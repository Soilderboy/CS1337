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


// getRadius assigns a value to the radius member.

// getDiameter 

// getArea






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
 

   // Display the circle's data.
   cout << "\nHere is the circle's data:\n";
   cout << "Radius: " <<  << endl;
   cout << "Diameter: " << << endl;
   cout << "Area: " <<  << endl;

    Circle *c2 = new Circle;
    

   // Store the radius of the circle in the c2 object.
   

   // Display the circle's data.
   cout << "\nHere is the circle's data through the pointer:\n";
   cout << "Radius: " <<  << endl;
   cout << "Diameter: " <<  << endl;
   cout << "Area: " <<  << endl;

   return 0;
}
