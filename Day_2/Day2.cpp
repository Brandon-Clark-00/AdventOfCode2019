#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>




using namespace std;




int day2()
{

        cout << "\033[1;34m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n";

        ifstream lineReader;
        string line;
        string token;
        vector<int> values;

        
        cout << "Inserting opcode programs " << endl;
        sleep(1);
        // Reads each line into a vector to then be processed further
        lineReader.open("Day_2/input.txt");
        if (lineReader.is_open())
        {

            while (getline(lineReader, line, ','))
            {
                values.push_back(stoi(line));
                
            }
        }
        else
        {
            lineReader.close();
            return 1;
        }

        lineReader.close();


      for (int i = 0; i < int(values.size()) && i+4 <int(values.size()) ; i+=4)
      {
        for (int j = i; j < i+4 ; j++)
        {
        cout << values.at(j) << "  ";
        }
        
        cout<< endl;
      }





      vector<int> temp;

     for (int i = 0; i < int(values.size()); i++)
     {
       for (int j = 0; j < int(values.size()); j++)
       {
        temp.clear();
        temp = values;
        temp.at(1) = i;
        temp.at(2) = j;

        cout<< i << "-" << j << ": "; 
        for (int i = 0; i < int(values.size()); i+=4)
        {
          if (temp.at(i)==1)
          {
          temp.at(temp.at(i+3)) = temp.at(temp.at(i+1)) + temp.at(temp.at(i+2));
          }
          else if(temp.at(i) == 2)
          {
          temp.at(temp.at(i+3)) = temp.at(temp.at(i+1)) * temp.at(temp.at(i+2));
          }
          else if (temp.at(i) == 99)
          {
            
          break;
          }
          else
          {
            return 1;
          }  
        }

        if (temp.at(0) == 19690720)
        {
          cout << endl << "Found it bro" << endl;
          values = temp;
          break;
          break;
        }
        

       }
        if (temp.at(0) == 19690720)
        {
          values = temp;
         
          break;
        }
       
     }
     
      




cout << endl;

 for (int i = 0; i < int(values.size()) && i+4 <int(values.size()) ; i+=4)
      {
        for (int j = i; j < i+4 ; j++)
        {
        cout << values.at(j) << "  ";
        }
        
        cout<< endl;
      }



      cout << endl << "Value of " << values.at(1) << " & " << values.at(2) << " = " << values.at(0)  << " which means output is ( 100 * " << values.at(1) << ") + " << values.at(2) << " which equals " << ( 100 * int(values.at(1)) ) + int(values.at(2)) << endl;


cout << endl;
        cout << "\033[1;34m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[0m\n";
        sleep(5);

        return 0;
}