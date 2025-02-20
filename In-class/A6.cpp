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

        int artIndex1 = rand() % 5;  // first article
        int nounIndex1 = rand() % 5; // first noun
        int verbIndex = rand() % 5;  // verb
        int prepIndex = rand() % 5;  // preposition
        int artIndex2 = rand() % 5;  // second article
        int nounIndex2 = rand() % 5; // second noun

        sentence = article[artIndex1];
        sentence[0] = toupper(sentence[0]); //capitalize

        sentence += " " + noun[nounIndex1] + " " + verb[verbIndex] +
                    " " + preposition[prepIndex] + " " + article[artIndex2] + " " + noun[nounIndex2] + ".";

        cout << sentence << endl;
    }
    
}