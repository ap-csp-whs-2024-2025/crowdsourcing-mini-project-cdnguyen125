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


void LongestSongInfo (std::vector<std::string> names, std::vector<std::string> artists, std::vector<int> duration, int durMax)
{
    int durIndex = 0;
    while (duration[durIndex] != durMax)
    {
        durIndex = durIndex  + 1;
    }
    std::cout << "the song with the longest duration was: " << names[durIndex] << " by " << artists[durIndex] << ", " << durMax << " seconds"<< std::endl;
}

void ShortestSongInfo (std::vector<std::string> names, std::vector<std::string> artists, std::vector<int> duration, int durMin)
{
    int durIndex2 = 0;
    while (duration[durIndex2] != durMin)
    {
        durIndex2 = durIndex2 + 1;
    }
    std::cout << "the song with the least duration was: " << names[durIndex2] << " by " << artists[durIndex2] << ", " << durMin << " seconds"<< std::endl;
}

bool validAns( std::string answer)
{
    if (answer != "y" && answer != "Y" && answer != "n" && answer != "N")
    {
        return false;
    }
    return true;
}


int main()
{
    std::vector<std::string> songname = {};
    std::vector<std::string> songartist = {};
    std::vector<int> songduration = {};
    std::cout << "would you like to enter a song into the database? (y/n)" << std::endl;

    std::string answer;
    std::cin >> answer;

    while (!validAns(answer))
    {
        std::cout << std::endl << "invalid response; try again" << std::endl << "would you like to enter another song? (y/n)" << std::endl;
        std::cin >> answer;
    }

    
    while (answer != "n" && answer!= "N")
    {
        std::cin.ignore();

        std::cout << std::endl << "Enter the following information in order: " << std::endl << "1. the song name" << std::endl << "2. the song's artist" << std::endl << "3. the song's duration IN SECONDS" << std::endl << std::endl;
    
        std::string sName;
        std::string sArtist;
        int sDuration;
        std::getline(std::cin, sName);
        std::getline(std::cin, sArtist);
        std::cin >> sDuration;
    
        songname.push_back(sName);
        songartist.push_back(sArtist);
        songduration.push_back(sDuration);

        std::cout << std::endl << "would you like to enter another song? (y/n)" << std::endl;
        std::cin >> answer;


        while (!validAns (answer))
        {
            std::cout << std::endl << "invalid response; try again" << std::endl << "would you like to enter another song? (y/n)" << std::endl;
            std::cin >> answer;
        }
    }
   
    int index = 0;
    int durTotal = 0;
    int durMax = songduration[0];
    int durMin = songduration[0];
    while (index < songduration.size())
    {
        durTotal = durTotal + songduration[index];
        if (songduration[index] > durMax)
        {
            durMax = songduration[index];
        }
        if (songduration[index] < durMin)
        {
            durMin = songduration[index];
        }
        
        index = index + 1;
    }
    std::cout << std::endl << "the total duration of your songs is: " << durTotal << " seconds" <<std::endl;
   
    int durAvg = 0;
    durAvg = durTotal/songduration.size();
    std::cout << "the average duration of your songs is: " << durAvg << " seconds" << std::endl;

    LongestSongInfo(songname, songartist, songduration, durMax);

    ShortestSongInfo(songname, songartist, songduration, durMin);
    

   
    return 0;
}
