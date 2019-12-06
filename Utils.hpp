#ifndef UTILITIES_H
#define UTILITIES_H

#include <cmath>
#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <unistd.h>

using namespace std;


int getIntInput()
{

    //init input variable
    string input = "";
    bool isInt = false;

    do
    {
        cin >> input; //Gets input from user

        int inputLength = input.length();

        // Goes through the string by input to make sure each character is a digit and not a char
        for (int i = 0; i < inputLength; i++)
        {

            if (!isdigit(input[i])) // Check for digit
            {
                cout << "INVALID INPUT - PLEASE ENTER A VALID NUMBER" << endl;
                break;
            }
            else
            {
                isInt = true;
            }
        }

    } while (!isInt);

    // cout << typeid(input).name() << endl;

    return atoi(input.c_str()); //Converts input to integer and returns it
}

int compareFiles(string file, string file2)
{
    vector<string> uno;
    vector<string> dos;

        bool equal1 = true, equal2 = true;
        ifstream lineReader;
        string line;

        
        cout << "Inserting file 1" << endl;
        sleep(1);
        // Reads each line into a vector to then be processed further
        lineReader.open(file);
        if (lineReader.is_open())
        {
            while (getline(lineReader, line))
            {
                uno.push_back(line);
            }
        }
        else
        {
            lineReader.close();
            return 1;
        }

        lineReader.close();

          cout << "Inserting file 2" << endl;
        sleep(1);
        // Reads each line into a vector to then be processed further
        lineReader.open(file2);
        if (lineReader.is_open())
        {
            while (getline(lineReader, line))
            {
                dos.push_back(line);
            }
        }
        else
        {
            lineReader.close();
            return 1;
        }

        lineReader.close();


        if (int(uno.size()) == int(dos.size()))
        {
            cout << "Files are equally sized." << endl;
        }
        else
        {
            cout << "Files are not equally sized." << endl;
            equal1 = false;
        }
        
        for (int i = 0; i < int(uno.size()); i++)
        {
            for (int j = 0; j < int(uno.at(i).size()); j++)
            {
                if (uno.at(i)[j] != dos.at(i)[j])
                {
                   cout << "Files are not the same, first file at pos " << i << ":" << j << "(" <<uno.at(i)[j] << ") not equal to second file at pos "<< i << ":" << j << "(" <<dos.at(i)[j] << ")" << endl;
                equal2 = false;
                }
                
            }
            
        }

        if (equal1 && equal2)
        {
            cout<< "Files are equal" << endl;
        }
        
        
        




return 0;
    
}

#endif