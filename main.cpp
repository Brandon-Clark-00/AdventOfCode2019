#include <iostream>
#include <cstdlib>
#include <string>
#include "Utils.hpp"
#include "Day_1/Day1.cpp"
#include "Day_2/Day2.cpp"
#include "Day_3/Day3.cpp"
#include "Day_4/Day4.cpp"
#include "Day_5/Day5.cpp"
#include "Day_6/Day6.cpp"

using namespace std;


void displayMenu();


int main()
{
     int result = 35; 
    

    while (true)
    {
        displayMenu(); // display the menu
        

        result = getIntInput(); // store input from keyboard inside variable

        switch (result)
        {
        case 1:
            cout << "Day 1 selected" << endl;
            if (day1() == 1)
            {
                cout << "Error occured with day " << result << endl;
            }
            else
            {
                cout << "Code ran successfully" << endl;
            }
            break;
        case 2:
            cout << "Day 2 selected" << endl << endl; // Runs simulator using user selected file
            if (day2() == 1)
            {
                cout << "Error occured with day " << result << endl;
            }
            else
            {
                cout << "Code ran successfully" << endl;
            }
            break;
        case 3:
            cout << "Day 3 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            if (day3() == 1)
                {
                    cout << "Error occured with day " << result << endl;
                }
            else
                {
                    cout << "Code ran successfully" << endl;
                }
            break;
        case 4:
            cout << "Day 4 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            if (day4() == 1)
                {
                    cout << "Error occured with day " << result << endl;
                }
            else
                {
                    cout << "Code ran successfully" << endl;
                }
            break;
        case 5:
            cout << "Day 5 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 6:
            cout << "Day 6 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            if (day6() == 1)
                {
                    cout << "Error occured with day " << result << endl;
                }
            else
                {
                    cout << "Code ran successfully" << endl;
                }
            break;
        case 7:
            cout << "Day 7 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
        case 8:
            cout << "Day 8 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 9:
            cout << "Day 9 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 10:
            cout << "Day 10 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
        case 11:
            cout << "Day 11 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 12:
            cout << "Day 12 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 13:
            cout << "Day 13 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
        case 14:
            cout << "Day 14 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 15:
            cout << "Day 15 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 16:
            cout << "Day 16 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
        case 17:
            cout << "Day 17 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 18:
            cout << "Day 18 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 19:
            cout << "Day 19 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
        case 20:
            cout << "Day 20 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 21:
            cout << "Day 21 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 22:
            cout << "Day 22 selected" << endl << endl; // Compiles user selected file from assembly language into machine code
            break;
         case 23:
            cout << "Day 23 selected" << endl << endl; // Runs simulator using user selected file
            break;
        case 24:
            cout << "Day 24 selected" << endl; // Compiles "Atest_file.txt" from assembly language into machine code
            break;
        case 25:
            cout << "Day 25 selected" << endl; // Exits program
            compareFiles("Output.txt","ramsay.txt");
            break;
         case 26:
            cout << "Day 26 selected" << endl; // Exits program
            exit(0);
            break;
        default:
            cout << "Invalid input. Try again" << endl;
            break;
        }
    }
    return 0;
}

void displayMenu()
{
    int numOfDays = 6;
    cout << endl;
    cout << "\033[4;36mDays\033[0m\n";
    for (int i = 1; i < 26; i++)
    {
        if (i != 25)
        {
            
        
            if (i <= numOfDays)
            {
            
                    cout << std::left << "\033[42;30m " << i << " \033[0m";
            } else {
                    cout << std::left << "\033[41;30m " << i  <<  " \033[0m";
            }
            
            if ((i % 6) == 0 && i > 0)
            {
                cout << endl << endl;
            }
        }
        else
        {
            cout << std::left << "\033[43;30m CF/25 \033[0m\n";
        }
        
    }

    
    cout << "Please select an number relative to the day" << endl;
}
    


