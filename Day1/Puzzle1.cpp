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
int SimilarityScore(std::vector<int> links, std::vector<int>rechts);
int main()
{
    DateiEinlesen("Input1-1.txt");
    int TotalDistance = SortierenUndVergleichen(LinkeSeite, RechteSeite);
    std::cout << "TotalDistance > " << TotalDistance << std::endl;
    int SimScore = SimilarityScore(LinkeSeite, RechteSeite);
    std::cout << "SimilarityScore > " << SimScore << std::endl;
}

void DateiEinlesen(std::string Dateiname)
{
    std::ifstream datei;
    datei.open(Dateiname, std::ios::in);

    std::string line;
    while(datei.good())
    {
        std::getline(datei, line);
        ZahlenSpeichern(line);
    }
}

void ZahlenSpeichern(std::string Zeile)
{   
    int Zahl1 = std::stoi(Zeile.substr(0, 5),0,10);
    LinkeSeite.push_back(Zahl1);
    int Zahl2 = std::stoi(Zeile.substr(8, 5),0,10);
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

int SimilarityScore(std::vector<int> links, std::vector<int>rechts)
{
    std::sort(links.begin(), links.end());
    std::sort(rechts.begin(), rechts.end());

    int counter;
    int SimScore = 0;
    for(size_t i = 0; i < links.size(); i++)
    {
        counter = 0;
        for(size_t j = 0; j < rechts.size(); j++)
        {
            if(links[i] == rechts[j])
            {
                counter++;
            }
        }
        SimScore += links[i] * counter;
    }
    return SimScore;
}