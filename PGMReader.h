#ifndef PGM_READER_H
#define PGM_READER_H

#include "ImageReader.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class PGMReader : public ImageReader
{
private:
    int szerokosc;
    int wysokosc;
    vector<vector<int>> pixels;

public:
    /// <summary>
    /// Konstruktor czytnika PGM
    /// </summary>
    /// <param name="plik">Typ, dzieki ktoremu wczytuje sie obraz z pliku o danej nazwie</param>
    PGMReader(const string& plik);

    /// <summary>
    /// Wyswietla informacje o obrazie
    /// </summary>
    void printImageInfo() override;

    /// <summary>
    /// Oblicza ile jest unikalnych kolorow w obrazie
    /// </summary>
    /// <returns>Zwraca liczbe unikalnych kolorow</returns>
    int calcualteNumberOfUniqueColors() override;

    /// <summary>
    /// Wyswietla informacje o najczesciej wystepujacym kolorze
    /// </summary>
    void printMostFrequentColor() override;
};

#endif // PGM_READER_H
