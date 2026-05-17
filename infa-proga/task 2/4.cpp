#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>


void print(int count, std::string word, std::vector<char> alph)
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif

    std::cout << "moves left: " << count << "\n";
    std::cout << "word: " << word << "\n";
    std::cout << "alphabet" << "\n";
    for (int i = 0; i < 28; i++)
    {
        if (i % 7 == 0)
            std::cout << "\n";
        std::cout << alph[i] << " ";
    }
    std::cout << "\n";
}


void game(bool& play)
{
    std::cout << "play again (1 - yes, 0 - no)?" << "\n";
    int g = 0;
    std::cin >> g;
    if (g == 0)
        play = false;
    else
        play = true;
}


int main()
{
    std::vector<std::string> words = {"elephant", "computer", "notebook", "beautiful", "applesauce", "adventure", "friendship", "chocolate", "basketball", "activity", "dolphin", "caterpillar", "happiness", "relationship", "firefighter"};
    srand(time(0));
    bool play = true;


    while (play)
    {
        std::cout << "\n";
        int index = rand() % 15;
        std::string word1 = words[index];
        std::string word2 (word1.size(), '_');
        int count = word1.size() / 2;
        std::vector<char> alph = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};


        while (count > 0)
        {
            print(count, word2, alph);
            std::cout << "1. enter word" << "\n" << "2. enter letter" << "\n";
            int var = 0;
            std::cin >> var;
            if (word1 == word2)
                {
                    std::cout << "you win" << "\n";
                    game(play);
                    break;
                }


            if (var == 1)
            {
                std::string ans;
                std::cout << "word: ";
                std::cin >> ans;
                if (ans != word1)
                {
                    std::cout << "you lost" << "\n";
                    game(play);
                    break;
                }
                else
                {
                    std::cout << "you win" << "\n";
                    game(play);
                    break;
                }
            }
            if (var == 2)
            {
                char ch;
                std::cout << "char: ";
                std::cin >> ch;

                if (word1.find(ch) != std::string::npos)
                {
                    for (int i = 0; i < (int)word1.size(); i++)
                    {
                        if (word1[i] == ch)
                        {
                            word2[i] = ch;
                        }
                    }
                }
                else
                {
                    count --;
                }
                auto it = std::find(alph.begin(), alph.end(), ch);
                *it = 'X';
            }
        }
        if (count == 0)
        {
            print(count, word2, alph);
            std::cout << "you lost" << "\n";
            game(play);
        }
    }
    return 0;
}
