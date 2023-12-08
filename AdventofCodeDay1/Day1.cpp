#include "Day1.h"

#include "Day1.h"

void Day1::SolveDay1(string day1filename) {
    //Step 1. Create the input stack.
    stack<string> coordinates;
    std::ifstream infile(day1filename);
    string tempstring;
    int filesize = 0;

    if (infile.is_open()) {
        while (infile.good()) {
            getline(infile, tempstring);
            coordinates.push(tempstring);
            filesize++;
        }
        infile.close();
    }
    else {
        std::cout << "Couldn't open file\n";
    }

    std::cout << "Last string is: " << coordinates.top() << "\n";
    std::cout << "Total strings: " << filesize << "\n";

    //Step 1.a. Create the vector for analysis 
    vector<string> working;
    vector<string> working2;

    string numberwords[10] = { "one","two","three","four","five","six","seven","eight","nine","zero" };
    string numberhash[10] = { "1","2","3","4","5","6","7","8","9","0" };

    //Step 2. Find the first and last numeral in each string pulled off the stack.
    while (!coordinates.empty()) {
        string foo = coordinates.top();
        string tempspace;
        //find 1st digit, not using find function!
        for (int i = 0; i < foo.length(); i++) {
            if (isdigit(foo[i])) {
                tempspace = foo[i];
                break;
            }
        }
        //find last digit, not using find function!
        for (int i = foo.length() - 1; i >= 0; i--) {
            if (isdigit(foo[i])) {
                tempspace += foo[i];
                break;
            }
        }

        working.push_back(tempspace);

        string tempalphaspace;

        //find 1st alphanumeric digit, not using find function!
        for (int i = 0; i < foo.length(); i++) {
            bool itsaword = false;
            if (isdigit(foo[i])) {
                tempalphaspace = foo[i];
                break;
            }
            //if the character matches a first letter && there's space left in the word for that letter, try to read the rest of the word
            else for (int j = 0; j < 10; j++) {
                if (foo[i] == numberwords[j][0] && foo.length() >= i + numberwords[j].length()) {
                    itsaword = true;
                    for (int k = 1; k < numberwords[j].length(); k++) {
                        if (foo[i + k] != numberwords[j][k]) {
                            itsaword = false;
                            break;
                        }
                    }
                }
                //reached the end of the word without resetting to false? it's a word!
                if (itsaword) {
                    tempalphaspace = numberhash[j];
                    break;
                }

            }
            if (itsaword) {
                break;
            }
        }
        //find last alphanumeric digit, not using find function!
        for (int i = foo.length() - 1; i >= 0; i--) {
            bool itsaword = false;
            if (isdigit(foo[i])) {
                tempalphaspace += foo[i];
                break;
            }
            //if the character matches a last letter && there's space left in the word for that letter, try to read the word backwards
            else for (int j = 0; j < 10; j++) {
                if ((i + 1 - numberwords[j].length()) >= 0 && foo[i] == numberwords[j][numberwords[j].length() - 1]) {
                    itsaword = true;
                    for (int k = 1; k < numberwords[j].length(); k++) {
                        if (foo[i - k] != numberwords[j][numberwords[j].length() - 1 - k]) {
                            itsaword = false;
                            break;
                        }
                    }
                }
                if (itsaword) {
                    tempalphaspace += numberhash[j];
                    break;
                }
            }
            if (itsaword) {
                break;
            }
        }

        //push values and clear temps

        working2.push_back(tempalphaspace);
        cout << "tempalphaspace: " << tempalphaspace << "\n";
        tempspace = "";
        tempalphaspace = "";
        //remove current foo
        coordinates.pop();

        //cout << "\n";
    }
    //cout << "total runs:" << working.size() << "\n";

    //Step 3. Return sum.
    int coordtotal = 0;
    for (int i = 0; i < working.size(); i++) {
        coordtotal += stoi(working[i]);
    }
    cout << "Coordinate sum is: " << coordtotal;

    int alphacoordtotal = 0;
    for (int i = 0; i < working2.size(); i++) {
        alphacoordtotal += stoi(working2[i]);
    }

    cout << "Coordinate sum with alpha is: " << alphacoordtotal;
}