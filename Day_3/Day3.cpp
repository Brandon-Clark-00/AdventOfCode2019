#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>


using namespace std;






    int day3()
    {

        vector <vector<string>> lines;
        lines.resize(2);
    

    
        ifstream lineReader;
        string line;

        
        cout << "Inserting file" << endl;
        sleep(1);

        // Reads each line into a vector to then be processed further
        lineReader.open("Day_3/input.txt");
        if (lineReader.is_open())
        {
            int counter = 0;
            while (getline(lineReader, line, ','))
            {
                bool endLine = false;
                int pos;
                for (int i = 0; i < int(line.size()); i++)
                {
                    if (line[i] == '\n')
                    {
                        endLine = true;
                        pos = i;
                        cout << "Found it at " << i << " of " << int(line.size()) << " for '" << line << "'" << endl;
                    }
                }
                
                    
                    if(endLine == true)
                    {
                        string temp1, temp2;
                        for (int j = 0; j < pos; j++)
                        {
                            temp1+=line[j];
                        }
                            for (int j = pos+1; j < int(line.size()); j++)
                        {
                            temp2+=line[j];
                        }

                        cout << "Temp1: '" <<temp1 << "' & Temp2: '" << temp2 << "' " << endl;
                        lines.at(counter).push_back(temp1);
                        counter++;
                        lines.at(counter).push_back(temp2);
                    }
                    else
                    {
                        lines.at(counter).push_back(line);
                    }            
            }
              
        }
        else
        {
            lineReader.close();
            return 1;
        }
        lineReader.close();

         vector <vector<vector<long>>> active;
        active.resize(2);

    
    for (int i = 0; i < 2; i++)
    {
        vector<long> current;
        current.push_back(0);
        current.push_back(0);
       
        for (int j = 0; j < int(lines.at(i).size()); j++)
        {
            cout << "This time: " << j << endl;
            string dist = "";
            for (int k = 1; k < int(lines.at(i)[j].size()); k++)
            {
                dist+= lines.at(i)[j][k];
                cout<< "Dist = " << dist << endl;
            }
                if (lines.at(i)[j][0] == 'R')
                {
                    cout << "Right " << dist << endl;
                    for (int k = 0; k < stoi(dist); k++)
                    {
                        active.at(i).push_back(current);
                        current[0]++;
                    }
                    cout << "Current:" << current[0] << ":" << current[1] << ". Final element now " << active.at(i).at(int(active.at(i).size()-1))[0]<< ":"  << active.at(i).at(int(active.at(i).size()-1))[1] << endl;
                    continue;
                }
                else if (lines.at(i)[j][0] == 'D')
                {
                    cout << "Down " << dist << endl;
                    for (int k = 0; k < stoi(dist); k++)
                    {
                        active.at(i).push_back(current);
                        current[1]--;
                    }
                    cout << "Current:" << current[0] << ":" << current[1] << ". Final element now " << active.at(i).at(int(active.at(i).size()-1))[0]<< ":"  << active.at(i).at(int(active.at(i).size()-1))[1] << endl;
                    continue;
                } 
                else if (lines.at(i)[j][0] == 'L')
                {
                    cout << "Left " << dist << endl;
                    for (int k = 0; k < stoi(dist); k++)
                    {
                            active.at(i).push_back(current);
                            current[0]--;
                    }
                    cout << "Current:" << current[0] << ":" << current[1] << ". Final element now " << active.at(i).at(int(active.at(i).size()-1))[0]<< ":"  << active.at(i).at(int(active.at(i).size()-1))[1] << endl;
                    continue;
                }
                else if (lines.at(i)[j][0] == 'U')
                {
                    cout << "Up " << dist << endl;
                    for (int k = 0; k < stoi(dist); k++)
                    {
                        active.at(i).push_back(current);
                        current[1]++;
                    }
                    cout << "Current:" << current[0] << ":" << current[1] << ". Final element now " << active.at(i).at(int(active.at(i).size()-1))[0]<< ":"  << active.at(i).at(int(active.at(i).size()-1))[1] << endl;
                    continue;
                }
                else
                {
                    cout << "What have you done" << endl;
                    exit(0);
                }
                
        }
         cout << "End of " << i << endl;
         cout << active.at(i).size() << endl;
    }
    
    for (int i = 0; i < 15; i++)
    {
       cout << active.at(0).at(i)[0] << ":" << active.at(0).at(i)[1] << " ||| " << active.at(1).at(i)[0] << ":" << active.at(1).at(i)[1] << endl;
    }
    //  for (int i = 0; i < 15; i++)
    // {
    //     if (active.at(0).at(i)[0] == active.at(1).at(i)[0])
    //     {
    //         cout << active.at(0).at(i)[0] << ":" << active.at(0).at(i)[1] << " ||| " << active.at(1).at(i)[0] << ":" << active.at(1).at(i)[1] << endl;
   
    //     }
        
    //     }
    sleep(10);

   
    
    
    

    vector <vector<long>> collisions;
    int totalSize = int(active.at(0).size());
    for (int i = 0; i < 40000; i++)
    {
        if (i % 1000 == 0)
        {
            cout << "I = " << i << " of " << totalSize << endl;
        }
        
       
            int wireI1, wireI2;
            
            
                wireI1 = active.at(0).at(i)[0];
                wireI2 = active.at(0).at(i)[1];
    
            for (int j = 0; j < int(active.at(1).size()); j++)
            {
                int wireJ1, wireJ2;
                
                 
                 wireJ1 = active.at(1).at(j)[0];

                 wireJ2 = active.at(1).at(j)[1];
                
                
                
                if (wireI1 == wireJ1)
                {                    
                    if(wireI2 == wireJ2)
                    {
                        collisions.push_back(active.at(0)[i]);
                        collisions.at(int(collisions.size()-1))[2] = i+j;
                        cout << " got one at " << i << "][" << j << "  " << wireI1 << ":" << wireI2 << " ||| " << wireJ1 << ":" << wireJ2 << endl;
                       
                    }
                }
           
            }        
    }


    cout << "Got here" << endl;
    long f = collisions.at(1)[0], s = collisions.at(1)[1];
    if (f<0)
    {
        f = f*-1;
    }
    if(s < 0)
    {
        s = s*-1;
    }
    
    long shortest = f+s;

    long current;

    for (int i = 2; i < int(collisions.size()); i++)
    {
        f = collisions.at(i)[0];
        s = collisions.at(i)[1];
        if (f<0)
            {
                f = f*-1;
            }
        if(s < 0)
            {
                s = s*-1;
            }
            current = f+s;
        
        if (current < shortest)
        {
            shortest = current;
        }
        
       
    }

     for (int i = 0; i < int(collisions.size()); i++)
    {
     cout << i << " = " << collisions.at(i)[0] << ":" << collisions.at(i)[1] << " & total wire = " << collisions.at(i)[2] << endl;
    }
    

       cout << "Closest intersection " << shortest << "." << endl;

    return 0;

    }