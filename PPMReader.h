#ifndef PPM_READER_H
#define PPM_READER_H

#include "ImageReader.h"
#include <vector>
#include <map>
#include <iostream>

using namespace std;

class PPMReader : public ImageReader
{
private:
    int szerokosc;
    int wysokosc;
    vector<vector<vector<int>>> pixels;

public:
    /// <summary>
    /// Konstruktor czytnika PPM
    /// </summary>
    /// <param name="plik">Typ, dzieki ktoremu wczytuje sie obraz z pliku o danej nazwie</param>
    PPMReader(const string& plik);

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

#endif // PPM_READER_H
