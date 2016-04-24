#include <iostream>
#include <fstream> // ifstream
#include <string>
#include <sstream>
#include <iterator>
#include <string>
#include <sstream>
#include <stdio.h>

using namespace std;

namespace avr
{

enum    // konstanter
{
    NMEA_LINES=26
};

std::string* splitString(std::string &str);
std::string* getNMEA();

void setup()
{
    //Serial.begin(115200);
}

void loop()
{
//    ifstream input("input.txt");
    std::string* output = getNMEA();
//    readFromFile(input, output);
    for (int i=0; i < NMEA_LINES; ++i)
    {
        printf("%s\n", output[i].c_str());
        //splitString(output[i]);
    }
//    input.close();
//    delay(1000);
}
std::string* splitString(std::string &str)
{
    int j=0;
    int i=0;
    while (i < str.size())
    {
        if (str[i] == ',')   // komma funnet
        {
            std::string t=str.substr(0, i);  // ta ut ord før komma
            str=str.substr(i+1);        // fjern ord og komma fra string
            printf("%s",t.c_str());
//            items[j] = new string;
            ++j;      // antall ord funnet
            i=0;      // gjør på nytt med ny string
            continue; // hopp over ++i;
        }
        else if (i == str.size()-1)   // på enden av string -> siste ord
        {
            printf("%s\n",str.c_str());
        }
        ++i;
    }
}
std::string* getNMEA()
{
    std::string str[NMEA_LINES];
    str[0] = new string("$PSRPM,E,2,654,81,A*68");
    str[1] = "$PSRPM,E,1,652,83,A*6F";
    str[2] = "$PSRPM,S,2,137,81,A*7C";
    str[3] = "$PSRPM,S,1,136,83,A*7C";
    str[4] = "$PSAECLT,1,1,A*31";
    str[5] = "$PSAECLT,2,1,A*32";
    str[6] = "$PSAECLT,3,0,A*32";
    str[7] = "$PSAECLT,4,0,A*35";
    str[8] = "$PSAEPOW,1,138.9,A*3E";
    str[9] = "$PSAEPOW,2,127.3,A*39";
    str[10] = "$PSAEGES,127.3,A,322.7,A,138.9,A,311.1,A,221,A*24";
    str[11] = "$PSAETRM,0.2,A*21";
    str[12] = "$PSAEHEL,1.3,A*28";
    str[13] = "$PSAEDFT,4.7,4.9,A*32";
    str[14] = "$PSAETHR,1,0.0,A*38";
    str[15] = "$PSAETHR,2,0.0,A*38";
    str[16] = "$PSAEAZT,3,0.0,0.0,0.0,181.0,A*32";
    str[17] = "$PSAEFOT,1,0.0,V*3F";
    str[18] = "$PSAEFOC,1,0.0,V,0.0,V,400,A,0.0,V*5D";
    str[19] = "$PSAEFOC,2,0.0,V,0.0,V,300,A,0.0,V*59";
    str[20] = "$PSAEFOC,3,0.0,V,0.0,V,600,A,0.0,V*5D";
    str[21] = "$PSAEFOC,4,0.0,V,0.0,V,500,A,0.0,V*59";
    str[22] = "$PSAEFOT,1,45,A*07";
    str[23] = "$PSAEFOT,2,46,A*07";
    str[24] = "$PSAEFOT,3,37,A*00";
    str[25] = "$PSAEFOT,4,37,A*07";
    return str;
}
}

enum { NMEA_LINES=26 };

int main()
{
    avr::loop();

}
