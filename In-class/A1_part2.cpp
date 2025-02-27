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
using std::cout;
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
   while (hours < 0) {
        cout << "\nInvalid input. Hours cannot be negative" << endl;
        cout << "Enter a valid value: " ;
        cin >> hours;

    }
 
    int regularHours;
    int overtimeHours;

//three if statements
//checks hours and then calculates overtimeHours with a cap of 10 hours on it
    if(hours> 50){
        weeklyWages = (40 * payRate) + (10 * (1.5 * payRate));
        regularHours = 40;
        overtimeHours = 10;
    } else if(hours > 40 && hours <= 50) {
        weeklyWages = (40 * payRate) + ((hours - 40) * (1.5 * payRate));
        regularHours = 40;
        overtimeHours = hours - 40;
    } else {
        weeklyWages = hours * payRate;
        regularHours = hours;
        overtimeHours = 0;
    }
    
   
   // This is how your output shoudl be. 
   //If you declare variables accordingly you should be able to get correct answers.
    cout << "\nRegular hours: " <<  regularHours;
    cout << " Overtime hours: " <<  overtimeHours << endl;
    cout << "Your weekly pay: " << weeklyWages << endl;

    return 0;
}
