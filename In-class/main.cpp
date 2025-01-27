/*Get hourly pay rate & # of hours from the user, compute & output the # of regular hours, # of overtime hours & the weekly pay, subject to following conditions:

Do not pay for the extra hours beyond 50.
For the overtime hours (hours beyond regular 40 hours), pay at 1.5 times regular rate.
Here is one sample input & output:

Input hourly pay rate: 10
Input # of hours: 57
Regular hours: 40 Overtime hours: 10
Your weekly pay: 550
*/


#include <iostream>


using namespace std;
int main()
{
    double payRate;
    double hours;
    double weeklyWages;

    cout <<  "Input hourly pay rate: " ;
    cin >> payRate;

    cout <<  "Input # of hours: " ;
    cin >> hours;

//Input validation
   while (//write your code here) {
        cout << "\nInvalid input. Hours cannot be negative" << endl;
        cout << "Enter a valid value: " ;
        cin >> hours;

    }

    
/*

      Enter Code
      
   */
   
   /*
   // This is how your output shoudl be. 
   //If you declare variables accordingly you should be able to get correct answers.
    cout << "\nRegular hours: " <<  regularHours;
    cout << " Overtime hours: " <<   overtimeHours << endl;
    cout << "Your weekly pay: " << weeklyWages << endl;
   */

}
