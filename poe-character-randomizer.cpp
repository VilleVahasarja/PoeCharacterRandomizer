#include <iostream>
#include <conio.h>
#include <random>
#include <map>
#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include <stdio.h> 
#include <cctype>
#include <algorithm>
#include <cstring>

#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold Red */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */

int main(){
    std::mt19937 rand;
    rand.seed(std::chrono::system_clock::now().time_since_epoch().count());
    std::map<std::string, std::vector<std::string>> ascendancy;
    ascendancy["duelist"] = {"Slayer", "Gladiator", "Champion"};
    ascendancy["shadow"] = {"Assassin", "Saboteur", "Trickster"};
    ascendancy["marauder"] = {"Juggernaut", "Berserker", "Chieftain"};
    ascendancy["witch"] = {"Necromancer", "Occultist", "Elementalis"};
    ascendancy["ranger"] = {"Deadeye", "Raider", "Pathfinder"};
    ascendancy["templar"] = {"Inquisitor", "Hierophant", "Guardian"};
    ascendancy["scion"] = {"Ascendant"};

    std::ifstream in("gems.txt");
    std::string str;
    std::vector<std::string> gemList;
    std::string sub;
   
    while (std::getline(in, str))
    {
        int pos = str.find(","); 
        std::string sub = str.substr(pos + 2); 

        if(str[0] == 'D') // Gems will be colored by their Dexterity, Strenght or Intelligence type
        {
        sub = GREEN + sub;
        }
        else if(str[0] == 'S')
        {
        sub = RED + sub;
        }
        else if(str[0] == 'I')
        {
        sub = BLUE + sub;
        }
	   gemList.push_back(sub);
    }

    std::string input;
    bool repeat = true;

    std::cout << "write" << BOLDYELLOW << " stop" << RESET << " to stop rolling builds" << std::endl;
    std::cout << "write" << BOLDYELLOW << " roll" << RESET << " to roll randomized builds" << std::endl;

  while (repeat)
  {
   
    std::string inputString;
    std::getline (std::cin, inputString);
    std::transform(inputString.begin(), inputString.end(), inputString.begin(),
    [](unsigned char c){ return std::tolower(c); 
    }); 
 
    if(inputString == "stop")
    {
        repeat = false;
    } 
    else if (inputString == "roll")
    {
        std::vector<std::string> classes;
        for (auto& it : ascendancy) classes.push_back(it.first);
        auto _class = classes[rand() % classes.size()];
        auto& v = ascendancy[_class]; 
        std::string asc = v[rand() % v.size()];
        _class[0] = toupper(_class[0]);
        std::cout << "your class is " << YELLOW << _class << RESET <<" your ascendancy is " << YELLOW << asc << RESET << std::endl;
        std::cout << "and your main gem will be " << gemList[rand() % gemList.size()] << RESET << std::endl;
    } 
        else if (input != "roll")
        {
            std::cout << "Wrong input, try writing " << YELLOW << "roll " << RESET << "again" << std::endl; 
        }
    }  
  return 1;
}

 