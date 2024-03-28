#include <iostream>
#include "PGMReader.h"
#include "PPMReader.h"

using namespace std;

int main()
{
    cout << "CZYTNIK PGM\n\n";
    PGMReader r_pgm("przykladPGM.pgm");
    ImageReader* reader_pgm = &r_pgm;

    reader_pgm->printImageInfo();
    cout << "Liczba unikalnych kolorow: " << r_pgm.calcualteNumberOfUniqueColors() << endl;
    r_pgm.printMostFrequentColor();

    cout << endl;

    cout << "CZYTNIK PPM\n\n";
    PPMReader r_ppm("przykladPPM.ppm");
    ImageReader* reader_ppm = &r_ppm;

    reader_ppm->printImageInfo();
    cout << "Liczba unikalnych kolorow: " << r_ppm.calcualteNumberOfUniqueColors() << endl;
    r_ppm.printMostFrequentColor();

    return 0;
}
