#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<array>

std::vector<std::vector<int>>input;

void DateiEinlesen(std::string Dateiname);
void Test(std::string Report);

int main()
{
    DateiEinlesen("wtf.txt");
}

void DateiEinlesen(std::string Dateiname)
{
    std::ifstream datei;
    datei.open(Dateiname, std::ios::in);

    std::string line;
    while(datei.good())
    {
        std::getline(datei, line);
        Test(line);
    }
}

void Test(std::string Report)
{
    std::vector<int>Zeile;
    std::stringstream test(Report);
    test >> Zeile;
    for(size_t i = 0; i < Zeile.size(); i++)
    {
        std::cout << Zeile[i] << std::endl;
    }

    input.push_back(Zeile);
}
