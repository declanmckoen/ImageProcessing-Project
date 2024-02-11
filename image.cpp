#include <iostream>
#include "image.h"
using namespace std;


Image::Image() {}

Image::Image(const string& fileName) {
    name = fileName;

    inFile.open(fileName, ios_base::binary);

    if (!inFile.is_open()) {
        cerr << "Not open!" << endl;
    }

    inFile.read(&header.idLength, 1);
    inFile.read(&header.cmapType, 1);
    inFile.read(&header.dataTypeCode, 1);
    inFile.read(reinterpret_cast<char*>(&header.cmapOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.cmapLength), 2);
    inFile.read(&header.cmapDepth, 1);
    inFile.read(reinterpret_cast<char*>(&header.xOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.yOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.width), 2);
    inFile.read(reinterpret_cast<char*>(&header.height), 2);
    inFile.read(&header.bitsPerPixel, 1);
    inFile.read(&header.imageDescriptor, 1);

    int imageSize = header.width * header.height;
    for (int i = 0; i < imageSize; ++i) {
        Pixel p;
        inFile.read(reinterpret_cast<char*>(&p.blue), 1);
        inFile.read(reinterpret_cast<char*>(&p.green), 1);
        inFile.read(reinterpret_cast<char*>(&p.red), 1);
        pixels.push_back(p);
    }
}

void Image::Read(const string& fileName) {
    inFile.close();

    name = fileName;

    inFile.open(fileName, ios_base::binary);

    if (!inFile.is_open()) {
        cerr << "Not open!" << endl;
    }

    inFile.read(&header.idLength, 1);
    inFile.read(&header.cmapType, 1);
    inFile.read(&header.dataTypeCode, 1);
    inFile.read(reinterpret_cast<char*>(&header.cmapOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.cmapLength), 2);
    inFile.read(&header.cmapDepth, 1);
    inFile.read(reinterpret_cast<char*>(&header.xOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.yOrigin), 2);
    inFile.read(reinterpret_cast<char*>(&header.width), 2);
    inFile.read(reinterpret_cast<char*>(&header.height), 2);
    inFile.read(&header.bitsPerPixel, 1);
    inFile.read(&header.imageDescriptor, 1);

    int imageSize = header.width * header.height;
    for (int i = 0; i < imageSize; ++i) {
        Pixel p;
        inFile.read(reinterpret_cast<char*>(&p.blue), 1);
        inFile.read(reinterpret_cast<char*>(&p.green), 1);
        inFile.read(reinterpret_cast<char*>(&p.red), 1);
        pixels.push_back(p);
    }
}

void Image::Write(const string& fileName) {
    ofstream outFile(fileName, ios_base::binary);

    if (!outFile.is_open()) {
        cerr << "Not open!" << endl;
    }

    outFile.write(&header.idLength, 1);
    outFile.write(&header.cmapType, 1);
    outFile.write(&header.dataTypeCode, 1);
    outFile.write(reinterpret_cast<char*>(&header.cmapOrigin), 2);
    outFile.write(reinterpret_cast<char*>(&header.cmapLength), 2);
    outFile.write(&header.cmapDepth, 1);
    outFile.write(reinterpret_cast<char*>(&header.xOrigin), 2);
    outFile.write(reinterpret_cast<char*>(&header.yOrigin), 2);
    outFile.write(reinterpret_cast<char*>(&header.width), 2);
    outFile.write(reinterpret_cast<char*>(&header.height), 2);
    outFile.write(&header.bitsPerPixel, 1);
    outFile.write(&header.imageDescriptor, 1);

    for (int i = 0; i < pixels.size(); ++i) {
        outFile.write(reinterpret_cast<char*>(&pixels[i].blue), 1);
        outFile.write(reinterpret_cast<char*>(&pixels[i].green), 1);
        outFile.write(reinterpret_cast<char*>(&pixels[i].red), 1);
    }
}

bool Image::operator==(const Image& other) {
    for (int i = 0; i < this->pixels.size(); ++i) {
        if (pixels[i].blue != other.pixels[i].blue || pixels[i].green != other.pixels[i].green || pixels[i].red != other.pixels[i].red) {
            return false;
        }
    }
    return true;
}


