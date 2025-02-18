/**
* listhelpers.hpp has been provided by the instructor as starter code
* contains the following procedures to work with lists:
* display, append, insert, remove, length
*/
#include "listhelpers.hpp"

#include <cstdlib>   // srand, rand
#include <ctime>     // time
#include <iostream>  // std::cin, std::cout
#include <string>    // std::string, std::getline
#include <vector>    // std::vector

int main()
{
    std::vector<std::string> songname = {};
    std::vector<std::string> songartist = {};
    std::vector<std::string> songduration = {};
    std::cout << "would you like to enter a song in to the database? (y/n)" << std::endl;
    std::string answer;
    std::cin >> answer;

    while (answer != "n")
    {
        std::cout << std::endl << "Enter the following information in order: " << std::endl << "1. any song name" << std::endl << "2. the song's artist" << std::endl << "3. the song's duration IN SECONDS" << std::endl;
    
        std::string sName;
        std::string sArtist;
        int sDuration;
        std::cin >> sName >> sArtist >> sDuration;
    
        songname.push_back(sName);
        songartist.push_back(sArtist);
        songduration.push_back(sDuration);

        std::cout << "would you like to play again? (y/n)" << std::endl;
        std::string response;
        std::cin >> response;
    }
    std::cout << "bye!" << std::endl;
   

   
    return 0;
}
