#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>

#include <fstream>


using namespace std;


  int day4()
    {
        ofstream fyall;
        vector<string> list;
        string current = "";
        bool containsAdj = false, inOrder = true;
        
        for (int i = 178416; i < 676462; i++)
        {
            inOrder = true;
            containsAdj = false;
            current = to_string(i);
           
            for (int i = 0; i < int(current.size()-1) ; i++)
            {
               if (current[i] == current[i+1])
               {
                   int j = i+2, count = 1;
                   
                   while (current[j] == current[i])
                    {
                        count++;
                        j++;
                    }
                   
                   if (count > 1)
                    {
                        i= j-1;
                        containsAdj = false;
                    }
                   else
                    {
                            containsAdj = true;
                            break;
                    }
                   
               }
            }

            if (containsAdj == false)
            {
                continue;
            }

            for (int i = 0; i < int(current.size()-1) ; i++)
            {
               if (current[i] > current[i+1])
               {
                   inOrder = false;
                   break;
               }
            }

            if (inOrder == true)
            {
                 cout << current << endl;
               list.push_back(current);
            }
            
            

        }

        int total = 0;
        fyall.open("Output.txt");
        for (int i = 0; i < int(list.size()); i++)
        {
           fyall << i << ": " << list.at(i) << endl;
           cout << i << ": " << list.at(i) << endl;
           total++;
        }
        fyall.close();
        cout << "\nTotal is " << total << endl;
        
        
        return 0;
    }