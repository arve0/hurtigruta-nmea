#include <iostream>
#include <fstream> // ifstream
#include <string>
#include <sstream>

using namespace std;

namespace pc
{
enum { NMEA_LINES=26 };

bool readFromFile(ifstream &in, string* );
string* splitString(string &str);

int main()
{
    ifstream input("input.txt");
    string* output = new string[NMEA_LINES];
    readFromFile(input, output);
    for (int i=0; i < NMEA_LINES; ++i)
    {
        cout << i << ": " << output[i] << endl;
        splitString(output[i]);
    }
    input.close();
    return 0;
}
bool readFromFile(ifstream &input, string* output)
{
    if(!input.is_open()) return false;
    int i=0;
    while(input.good() && i < NMEA_LINES)
    {
        string line;
        getline(input, line);
        output[i] = line;
        i++;
//        cout << i << ": " << line << endl;
    }
    if (i+1 < NMEA_LINES) return false; // fikk ikke lest alle linjene som vi skulle
    return true;
}
string* splitString(string &str)
{
    int j=0;
    int i=0;
    while (i < str.size())
    {
        if (str[i] == ',')   // komma funnet
        {
            string t=str.substr(0, i);  // ta ut ord før komma
            str=str.substr(i+1);        // fjern ord og komma fra string
            //cout << t << " ";
//            items[j] = new string;
            ++j;      // antall ord funnet
            i=0;      // gjør på nytt med ny string
            continue; // hopp over ++i;
        }
        else if (i == str.size()-1)   // på enden av string -> siste ord
        {
            //cout << str;
        }
        ++i;
    }
    //cout << endl;
}
}
