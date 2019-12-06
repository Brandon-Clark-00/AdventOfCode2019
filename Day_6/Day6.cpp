#include <iostream>
#include <cstdlib>
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <iterator>

using namespace std;


  map<string, string> orbmap;

int recursive(string satellite)
{
    cout<< "Made it to " << satellite << endl;
   
    cout << "This is something: " << orbmap.find(satellite)->second << endl;
    string key =(orbmap.find(satellite)->second);
    cout << "This is a key " << endl;
    sleep(20);
    if ( key != "COM")
        {
            return recursive(key) +1;
        }
    else
        {
            return 1;
        }
}


int day6()
{

    ifstream fyallStream;
    string line;
    vector<string> orbits;

    fyallStream.open("Day_6/input.txt");
    if (fyallStream.is_open())
    {
        while(getline(fyallStream,line))
        {
            orbits.push_back(line);
        }
    }
    else
    {
        fyallStream.close();
        return 1;
    }

    fyallStream.close();
    
    for (int i = 0; i < int(orbits.size()); i++)
    {
        int delim = 0;
        for (int j = 0; j < int(orbits.at(i).size()); j++)
        {
            if (orbits.at(i)[j] == ')')
            {
                delim = j+1;
                break;
            }
        }

        string body, satellite;

        for (int j = 0; j < delim; j++)
        {
           body += orbits.at(i)[j];
        }
        for (int j = delim; j < int(orbits.at(i).size()); j++)
        {
           satellite += orbits.at(i)[j];
        }
        
        
        orbmap.insert({satellite, body});
    }

cout << "Made it here " << endl;
    map<string, string>::iterator itr;
    cout << "Here again?" << endl;
    int total_orbits = 0;
    for (itr = orbmap.begin(); itr != orbmap.end(); itr++)
    {
        cout << "Made it to" << itr-> first<< endl;
       
        
        if (itr->second != "COM")
        {
            cout << itr->second << endl;
            
            total_orbits += recursive(itr->second);
        }
        else
        {
            total_orbits++;
        }
       
    }

    cout << "Total: " << total_orbits << endl;
     
    return 0;
}