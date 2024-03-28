#include "PPMReader.h"
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

PPMReader::PPMReader(const string& plik)
{
    ifstream file(plik);
    if (!file)
    {
        cout << "BLAD! Nie udalo sie otworzyc pliku" << plik << endl;
        return;
    }

    string rodzajPliku;
    getline(file, rodzajPliku);
    if (rodzajPliku != "P3")
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

    pixels.resize(wysokosc, vector<vector<int>>(szerokosc, vector<int>(3)));

    int maxValue;
    file >> maxValue;

    for (int i = 0; i < wysokosc; ++i)
    {
        for (int j = 0; j < szerokosc; ++j)
        {
            for (int k = 0; k < 3; ++k)
            {
                file >> pixels[i][j][k];
            }
        }
    }
}

void PPMReader::printImageInfo()
{
    cout << "Szerokosc obrazka: " << szerokosc << endl;
    cout << "Wysokosc obrazka: " << wysokosc << endl;
    cout << "Liczba pikseli: " << szerokosc * wysokosc << endl;
}

int PPMReader::calcualteNumberOfUniqueColors()
{
    map<vector<int>, int> colorFrequency;
    for (const auto& row : pixels)
    {
        for (const auto& pixel : row)
        {
            colorFrequency[pixel]++;
        }
    }
    return colorFrequency.size();
}

void PPMReader::printMostFrequentColor()
{
    map<vector<int>, int> colorFrequency;
    for (const auto& row : pixels)
    {
        for (const auto& pixel : row)
        {
            colorFrequency[pixel]++;
        }
    }

    vector<int> mostFrequentColor;
    int maxFrequency = 0;
    for (const auto& pair : colorFrequency)
    {
        if (pair.second > maxFrequency)
        {
            mostFrequentColor = pair.first;
            maxFrequency = pair.second;
        }
    }

    cout << "Najczestszy kolor: (";
    for (size_t i = 0; i < mostFrequentColor.size(); ++i)
    {
        cout << mostFrequentColor[i];
        if (i < mostFrequentColor.size() - 1)
            cout << ", ";
    }
    cout << ")" << endl;
}

