#include<iostream>
#include<fstream> //ifstream
#include<string>
#include<vector>
#include<algorithm> //sort
#include<stdlib.h> //abs

std::vector<int>LinkeSeite;
std::vector<int>RechteSeite;

// Part 1
void DateiEinlesen(std::string Dateiname);
void ZahlenSpeichern(std::string Zeile);
int SortierenUndVergleichen(std::vector<int> links, std::vector<int>rechts);

//Part 2

int main()
{
    DateiEinlesen("test.txt");
    int gesamt = SortierenUndVergleichen(LinkeSeite, RechteSeite);
    std::cout << "Gesamt > " << gesamt << std::endl;
}

void DateiEinlesen(std::string Dateiname)
{
    std::ifstream datei;
    datei.open(Dateiname, std::ios::in);

    std::string line;
    while(datei.good())
    {
        std::cout << "test" << std::endl;
        std::getline(datei, line);
        ZahlenSpeichern(line);
    }
}

void ZahlenSpeichern(std::string Zeile)
{   
    int Zahl1 = std::stoi(Zeile.substr(0, 1),0,10);
    std::cout << "Z1 > " << Zahl1;
    LinkeSeite.push_back(Zahl1);
    int Zahl2 = std::stoi(Zeile.substr(4, 1),0,10);
    std::cout << " Z2 > " << Zahl2 << std::endl;
    RechteSeite.push_back(Zahl2);

}

int SortierenUndVergleichen(std::vector<int>links, std::vector<int>rechts)
{
    std::sort(links.begin(), links.end());
    std::sort(rechts.begin(), rechts.end());

    int GesamtDistanz = 0; 
    for(size_t i = 0; i < links.size(); i++)
    {
        int temp = abs(links.at(i) - rechts.at(i));
        GesamtDistanz += temp;
    }

    return GesamtDistanz;
}