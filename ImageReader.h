#ifndef IMAGE_READER_HPP
#define IMAGE_READER_HPP

#include <string>

class ImageReader
{
public:
    virtual void printImageInfo() = 0;
    virtual void printMostFrequentColor() = 0;
    virtual int calcualteNumberOfUniqueColors() = 0;
};

#endif // IMAGE_READER_HPP
