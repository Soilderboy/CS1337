#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

#define INFONUM 255 //horrible idea

// patients structure definition
struct Patients {
    // fields
    //id fname, lname, vitals (int) 3 fields
    int id;
    string fName;
    string lName;
    int BPU;
    int BPL;
    int Pulse;

};

int main()
{
   //open the input file for reading.
    string filename;
    cout << "Enter filename: ";
    cin >> filename;
    cout << endl;
    ifstream inFile;
    inFile.open(filename);
    if(!inFile){
        cout << "Could not open file" << endl;
        cout << "Exiting" << endl;
        return 1;
    }
    //Dynamically create Patients array
    //count number of patients in file
    int count = 0;
    string line;
    bool header = false;
    while(getline(inFile, line)){
        if(!line.empty()){
            if(!header){
                header = true;
            }
            else{
                count++;
            }
        }
    }
    inFile.clear(); //clear eof flag
    inFile.seekg(0); //move to beginning so we can read again
    if(count == 0){
        cout << "No patients found" << endl;
        return 1;
    }
    int numPatients = count - 1;
    Patients *patients = new Patients[numPatients]; 
    // Read the header line and parse using istringstream Use setw(10) for First and last name.
    //Setw(4) for  for ID and other vitals
    cout << setw(4) << left << "ID" << setw(10) << left << "FN" << setw(10) << left << "LN" << setw(4) << left << "BPU" << setw(4) << left << "BPL" << setw(4) << left << "Pulse" << endl;
    
    // Read the values into array of structures
    getline(inFile, line); //skip header
    for(int i = 0; i < numPatients; i++){
        stringstream ss;
        getline(inFile, line);
        ss << line;
        ss >> patients[i].id >> patients[i].fName >> patients[i].lName >> patients[i].BPU >> patients[i].BPL >> patients[i].Pulse;
    }

    
    // Display the values
    //Use setw(10) for First and last name, Setw(4) for ID and other vitals
    for(int i = 0; i < numPatients; i++){
        cout << setw(4) << left <<  patients[i].id << setw(10) << left << patients[i].fName << setw(10) << left << patients[i].lName
        << setw(4) << left << patients[i].BPU << setw(4) << left << patients[i].BPL << setw(4) << left << patients[i].Pulse << endl;
    }
    //close the file
    inFile.close();
    
    //delete the pointer
    delete [] patients;
    return 0;
}//end of main

//patientsinfo.txt
