#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

int main()
{
    string article[] = { "the", "a", "one", "some", "any" };
    string noun[] = { "boy", "girl", "dog", "town", "car" };
    string verb[] = { "drove", "jumped", "ran", "walked", "skipped" };
    string preposition[] = { "to", "from", "over", "under", "on" };
    string sentence = ""; // completed sentence
    int seed; 
    cout << "Enter a seed Value: ";
    cin >> seed;
    srand(seed);
    // create 8 sentences
    for(int i = 0; i < 8; i++){
        sentence = article[rand()%5] + " " + noun[rand()%5] + " " + verb[rand()%5] +
         " " + preposition[rand()%5] + " " + article[rand()%5] + " " + noun[rand()%5] + ".";
         cout << sentence << endl;
    }
    
}
