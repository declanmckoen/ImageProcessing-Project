#include <vector>
#include <string>
#include <fstream>
#pragma once
using namespace std;


struct Header {
    char idLength;
    char cmapType;
    char dataTypeCode;
    short cmapOrigin;
    short cmapLength;
    char cmapDepth;
    short xOrigin;
    short yOrigin;
    short width;
    short height;
    char bitsPerPixel;
    char imageDescriptor;
};

struct Pixel {
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class Image {
private:
    ifstream inFile;
public:
    string name;
    Header header;
    vector<Pixel> pixels;
    Image();
    Image(const string& fileName);
    void Read(const string& fileName);
    void Write(const string& fileName);
    bool operator==(const Image& other);
};

