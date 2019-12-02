#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include "../Utils.hpp"


using namespace std;




int day1()
{

        cout << "\033[1;34m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n";

        ifstream lineReader;
        string line;
        int total = 0;
        vector<int> lines;

        
        cout << "Inserting all the values " << endl;
        sleep(1);
        // Reads each line into a vector to then be processed further
        lineReader.open("Day_1/input.txt");
        if (lineReader.is_open())
        {

            while (getline(lineReader, line))
            {
                lines.push_back(stoi(line));
            }
        }
        else
        {
            lineReader.close();
            return 1;
        }

        lineReader.close();

        cout << "Calculating total " <<endl ;
        sleep(1);
        sleep(1);
       

        for (int i = 0; i < int(lines.size()); i++)
        {
          lines.at(i) = (lines.at(i)/3)-2;
            int temp = lines.at(i);
            while ((temp/3)-2 > 0)
            {
              temp = (temp/3)-2;
              lines.at(i) += temp;
            }
            
            total = total + lines.at(i);
        }

        cout << "Total: " << total << endl;        
        cout << "\033[1;34m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n";
        sleep(5);

        return 0;
}