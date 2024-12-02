#include<iostream>
#include<fstream>
#include<string>


void DateiEinlesen(std::string Dateiname);

int main()
{
    DateiEinlesen("Input.txt");
}

void DateiEinlesen(std::string Dateiname)
{
    std::ifstream datei;
    datei.open(Dateiname, std::ios::in);

    std::string line;
    int 
    while(datei.good())
    {
        std::getline(datei, line);
    }
}
