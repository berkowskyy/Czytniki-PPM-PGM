#include "PGMReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PGMReader::PGMReader(const string& plik)
{
    ifstream file(plik);
    if (!file)
    {
        cout << "BLAD! Nie udalo sie otworzyc pliku!" << plik << endl;
        return;
    }

    string rodzajPliku;
    getline(file, rodzajPliku);
    if (rodzajPliku != "P2")
    {
        cout << "BLAD! Zly format pliku!" << endl;
        return;
    }
    string komentarz;
    getline(file, komentarz);

    if (komentarz.size() > 0 && komentarz[0] == '#')
    {
        
        getline(file, komentarz);
    }

    istringstream iss(komentarz);
    iss >> szerokosc >> wysokosc;

    pixels.resize(wysokosc, vector<int>(szerokosc));

    int maxValue;
    file >> maxValue;

    for (int i = 0; i < wysokosc; ++i)
    {
        for (int j = 0; j < szerokosc; ++j)
        {
            file >> pixels[i][j];
        }
    }
}

void PGMReader::printImageInfo()
{
    cout << "Szerokosc obrazka: " << szerokosc << endl;
    cout << "Wysokosc obrazka: " << wysokosc << endl;
    cout << "Liczba pikseli: " << szerokosc * wysokosc << endl;
}

int PGMReader::calcualteNumberOfUniqueColors()
{
    map<int, int> colorFrequency;
    for (const auto& row : pixels)
    {
        for (int pixel : row)
        {
            colorFrequency[pixel]++;
        }
    }
    return colorFrequency.size();
}

void PGMReader::printMostFrequentColor()
{
    map<int, int> colorFrequency;
    for (const auto& row : pixels)
    {
        for (int pixel : row)
        {
            colorFrequency[pixel]++;
        }
    }

    int mostFrequentColor = 0;
    int maxFrequency = 0;
    for (const auto& pair : colorFrequency)
    {
        if (pair.second > maxFrequency)
        {
            mostFrequentColor = pair.first;
            maxFrequency = pair.second;
        }
    }

    cout << "Najczestszy kolor: " << mostFrequentColor << endl;
}
