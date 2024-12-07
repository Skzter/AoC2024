#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include<vector>
#include<array>

std::vector<std::vector<int>>input;

void DateiEinlesen(std::string Dateiname);
void StrToVec(std::string t);
bool CheckLevel(std::vector<int> level);
bool CheckDecr(std::vector<int> level);
bool CheckIncr(std::vector<int> level);

int main()
{
    DateiEinlesen("wtf.txt");

    int counter = 0;
    for(size_t i = 0; i < input.size(); i++)
    {
        std::cout << "\n[MAIN] Level > " << i << std::endl;
        if(CheckLevel(input[i]))
        {
            counter++;
        }
            
    }
    std::cout << "Counter > " << counter << std::endl;
}

void DateiEinlesen(std::string Dateiname)
{
    std::ifstream datei;
    datei.open(Dateiname, std::ios::in);

    std::string line;
    while(datei.good())
    {
        std::getline(datei, line);
        StrToVec(line);
    }
}

void StrToVec(std::string t)
{
    std::vector<int> v_temp;
    std::stringstream ss(t);
    std::string s_temp;

    while (ss >> s_temp)
    {
        std::stringstream st(s_temp);

        while(st)
        {
            int i;
            if(st >> i)
            {
                v_temp.push_back(i);
            }
            else
            {
                st.clear();
                st.get();
            }
        }
    }
    input.push_back(v_temp);
}

bool CheckLevel(std::vector<int> level)
{
    if(level.size() == 1)
        return true;
    if(CheckDecr(level))
        return true;
    if(CheckIncr(level))
        return true;
    
    return false;
}

bool CheckDecr(std::vector<int> level)
{
    int del = 0;
    
    for(size_t i = 0; i < level.size()-1; i++)
    {
        std::cout << "[DECR] Size > " << level.size() << std::endl;
        std::cout << "[DECR] i > " << i << std::endl;
        std::cout << "[DECR] Check 1 > " << (level.at(i) > level.at(i+1)) << std::endl;
        std::cout << "[DECR] Check 2 > " << ((level.at(i) - level.at(i+1)) <= 3) << std::endl;

        if(level.at(i) > level.at(i+1) && (level.at(i) - level.at(i+1)) <= 3)
        {
            std::cout << "[DECR] Worked" << std::endl;
        }
        else
        {
            if(del == 0)
            {
                std::cout << "[DECR] Delete" << std::endl;
                level.erase(level.begin() + i);
                del++;
                i = i - 2;
                std::cout << "[DECR] DEL " << del << std::endl;
            }
            else
            {
                std::cout << "[DECR] BROKEN" << std::endl;
                return false;
            }
            
        }
        std::cout << "[DECR] Vector ";
        for(size_t i = 0; i < level.size(); i++)
        {
            std::cout << level.at(i) << " ";
        }
        std::cout << std::endl;
    }
    return true;
}

bool CheckIncr(std::vector<int> level)
{
    int del = 0;
    std::cout << "[INCR] Size > " << level.size() << std::endl;
    for(size_t i = 0; i < level.size()-1; i++)
    {
        std::cout << "[INCR] i > " << i << std::endl;
        std::cout << "[INCR] Check 1 > " << (level.at(i) < level.at(i+1)) << std::endl;
        std::cout << "[INCR] Check 2 > " << ((level.at(i+1) - level.at(i)) <= 3) << std::endl;
        if(level.at(i) < level.at(i+1) && (level.at(i+1) - level.at(i)) <= 3)
        {
            std::cout << "[INCR] Worked" << std::endl;
        }
        else
        {
            if(del == 0)
            {
                std::cout << "[INCR] Delete" << std::endl; 
                level.erase(level.begin() + i);
                del++;
                i = i - 2;
                std::cout << "[INCR] DEL " << del << std::endl;
            }
            else
            {
                std::cout << "[INCR] BROKEN" << std::endl;
                return false;
            }
        }
        
    }
    return true;
}