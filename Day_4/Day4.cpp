#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <vector>


using namespace std;


  int day4()
    {
        
        vector<string> list;
        string current = "";
        bool containsAdj = false, inOrder = true;
        
        for (int i = 206938; i < 679129; i++)
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
        for (int i = 0; i < int(list.size()); i++)
        {
           cout << i << ": " << list.at(i) << endl;
           total++;
        }

        cout << "\nTotal is " << total << endl;
        
        
        return 0;
    }