/*
Details:
write a program to find max,min, and average for any group of players
input file has 
    name, age, score, rebound, steals, blocks, pf (personal fouls)

    output:
    max, min scores need to have the player name

ifstream filename

read file
calculate # of records
define array for as many records in file
seekg(0) and display the header
read from input file all player data and store it in array of structs

print all values
int - setw8
string - setw16
left adjust

use functions to calc avg, min, max of field


*/
// This will pass a structure in the array

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
enum Field {SCORES, AGE, STEALS, FOULS, BLOCKS, REBOUNDS, QUIT};
struct Nbastats
{
    int pscores;
    int age;
    int steals;
    int fouls;
    int blocks;
    int rebounds;
    string pname;
};
const int NUM_PLAYERS = 50;
const int NAME_COL_WIDTH = 16;
double getAvg(Nbastats plr[], int asize, Field f);
int getMax(Nbastats plr[], int asize, Field f);
int getMin(Nbastats plr[], int asize, Field f);

int main()
{
    ifstream infile;
    string filename = "nbastats.txt";


    infile.open(filename);              //nbastats.txt
   
    if (!infile){
        cout << "Invalid file name \n";
        return -1;
    }
    string temp;
    // Skip  the header line
    getline(infile, temp);
    
    //Read the total number of records
    int numRecords = 0;
    while(getline(infile, temp)){
        numRecords++;
    }
    
    //After counting the number of records, seek to the beginning to again read and store the values
    infile.clear();
    infile.seekg(0); // seek to start
    
    //Declare an array of structures
    //{} initializes all values to 0
    Nbastats* player = new Nbastats[numRecords]{};

    //read header line and display it
    getline(infile, temp);
    cout << temp << endl;
    //read from input file all player data and store
    for(int i = 0; i < numRecords; i++){
        infile >> player[i].pname >> player[i].age >> player[i].pscores >> player[i].rebounds >> player[i].steals >> player[i].blocks >> player[i].fouls;
    }

    //display file data
    for(int i = 0; i < numRecords; i++){
        cout << left << setw(NAME_COL_WIDTH) << player[i].pname << setw(8) << player[i].age << setw(8) << player[i].pscores << setw(8) << player[i].rebounds << setw(8) << player[i].steals << setw(8) << player[i].blocks << setw(8) << player[i].fouls << endl;
    }

    //display field value we want and then get average,min and max of that field
    bool quit = false;
    while(!quit){
        cout << endl;
        cout << "Enter the field for getting average, min and max:" << endl; //number this time
        cout << "Please pick one item from the menu:" << endl;
        cout << "Enter 0 for Scores" << endl;
        cout << "Enter 1 for Age" << endl;
        cout << "Enter 2 for Steals" << endl;
        cout << "Enter 3 for Fouls" << endl;
        cout << "Enter 4 for Blocks" << endl;
        cout << "Enter 5 for Rebounds" << endl;
        cout << "Enter 6 for quit: " << endl;

        string field;
        cin >> field;
        if(field == "6"){
            quit = true;
            break;
        }
        //convert input to int, then to the field enum
        Field f = static_cast<Field>(stoi(field));
        //convert field to string
        getAvg(player,numRecords,f);
        getMin(player,numRecords,f);
        getMax(player,numRecords,f);
    }
    infile.close();
    delete [] player;
    return 0;
}
//cout statements needed bc different fields have different couts
double getAvg(Nbastats player[], int numRecords, Field f){
    double sum = 0;
    string field = "";
    //making this enum work and not getting rid of last assignment's
    if(f == SCORES){
        field = "scores";
    }
    else if(f == REBOUNDS){
        field = "rebounds";
    }
    else if(f == STEALS){
        field = "steals";
    }
    else if(f == BLOCKS){
        field = "blocks";
    }
    else if(f == FOULS){
        field = "fouls";
    }
    else if(f == AGE){
        field = "age";
    }
    
    for(int i = 0; i < numRecords; i++){
        if(field == "scores"){
            sum += player[i].pscores;
        }
        else if(field == "rebounds"){
            sum += player[i].rebounds;
        }
        else if(field == "steals"){
            sum += player[i].steals;
        }
        else if(field == "blocks"){
            sum += player[i].blocks;
        }
        else if(field == "fouls"){
            sum += player[i].fouls;
        }
        else if(field == "age"){
            sum += player[i].age;
        }
    }
    if(field == "age"){
        cout << "The average age of team is " << sum/numRecords << endl;
    }
    else{
        //if field is scores, make it singular
        if(field == "scores") field = "score";
        cout << "The average " << field << " is " << sum/numRecords << endl;
    }
    return sum/numRecords;
}
//need to have the cout statement here because different fields and we cant have a variable member name
int getMax(Nbastats player[], int numRecords, Field f){
    int max = 0;
    //store index of player with max value and update max
    int index = 0;
    string field = "";
    if(f == SCORES){
        field = "scores";
    }
    else if(f == REBOUNDS){
        field = "rebounds";
    }
    else if(f == STEALS){
        field = "steals";
    }
    else if(f == BLOCKS){
        field = "blocks";
    }
    else if(f == FOULS){
        field = "fouls";
    }
    else if(f == AGE){
        field = "age";
    }
    for(int i = 0; i < numRecords; i++){

        if(field == "scores"){
            if(player[i].pscores > max){
                max = player[i].pscores;
                index = i;
            }
        }
        else if(field == "rebounds"){
            if(player[i].rebounds > max){
                max = player[i].rebounds;
                index = i;
            }
        }
        else if(field == "steals"){
            if(player[i].steals > max){
                max = player[i].steals;
                index = i;
            }
        }
        else if(field == "blocks"){
            if(player[i].blocks > max){
                max = player[i].blocks;
                index = i;
            }
        }
        else if(field == "fouls"){
            if(player[i].fouls > max){
                max = player[i].fouls;
                index = i;
            }
        }
        else if(field == "age"){
            if(player[i].age > max){
                max = player[i].age;
                index = i;
            }
        }
    }
    if(field == "age"){
        cout << "The player with maximum age is " << player[index].pname << "  = " << max << endl;
    }
    else{
        if(field == "scores") field = "score";
        cout << "Maximum " << field << " by " << player[index].pname << "  = " << max << endl;
    }

    return index;
}

int getMin(Nbastats player[], int numRecords, Field f){
    int min = 1000; //set a high value so we can get a min value from the first element of different fields
    //store index of player with min value and update min
    int index = 0;
    string field = "";
    if(f == SCORES){
        field = "scores";
    }
    else if(f == REBOUNDS){
        field = "rebounds";
    }
    else if(f == STEALS){
        field = "steals";
    }
    else if(f == BLOCKS){
        field = "blocks";
    }
    else if(f == FOULS){
        field = "fouls";
    }
    else if(f == AGE){
        field = "age";
    }
    for(int i = 0; i < numRecords; i++){
        if(field == "scores"){
            if(player[i].pscores < min){
                min = player[i].pscores;
                index = i;
            }
        }
        else if(field == "rebounds"){
            if(player[i].rebounds < min){
                min = player[i].rebounds;
                index = i;
            }
        }
        else if(field == "steals"){
            if(player[i].steals < min){
                min = player[i].steals;
                index = i;
            }
        }
        else if(field == "blocks"){
            if(player[i].blocks < min){
                min = player[i].blocks;
                index = i;
            }
        }
        else if(field == "fouls"){
            if(player[i].fouls < min){
                min = player[i].fouls;
                index = i;
            }
        }
        else if(field == "age"){
            if(player[i].age < min){
                min = player[i].age;
                index = i;
            }
        }
    }
    if(field == "age"){
        cout << "The player with minimum age is " << player[index].pname << "  = " << min << endl;
    }
    else{
        if(field == "scores") field = "score";
        cout << "Minimum " << field << " by " << player[index].pname << "  = " << min << endl;
    }
    return index;
}