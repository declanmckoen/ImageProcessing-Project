#include <iostream>
#include <string>
#include "image.h"
using namespace std;

void Part1();
void PrintHelp();

int Compare(const string& file1, const string& file2);
Image Multiply(const Image& f1, const Image& f2);
Image ScaleRed(const Image& f1, int value);
Image ScaleGreen(const Image& f1, int value);
Image ScaleBlue(const Image& f1, int value);
Image Subtract(const Image& f1, const Image& f2);
Image Screen(const Image& f1, const Image& f2);
Image Add(const Image& f1, const Image& f2);
Image AddRed(const Image& f1, int value);
Image AddGreen(const Image& f1, int value);
Image AddBlue(const Image& f1, int value);
Image Overlay(const Image& f1, const Image& f2);
Image RedChannel(const Image& f1);
Image GreenChannel(const Image& f1);
Image BlueChannel(const Image& f1);
Image CombineChannels(const Image& f1, const Image& f2, const Image& f3);
Image Rotate(const Image& f1);



void PrintHelp() {
    cout << "Project 2: Image Processing, Fall 2023" << endl;
    cout << "\nUsage:\n\t./project2.out [output] [firstImage] [method] [...]" << endl;
}

int Compare(const string& file1, const string& file2) {
    Image image1(file1);
    Image image2(file2);

    for (int i = 0; i < image1.pixels.size(); ++i) {
        if (image1.pixels[i].blue != image2.pixels[i].blue) return i;
        if (image1.pixels[i].green != image2.pixels[i].green) return i;
        if (image1.pixels[i].red != image2.pixels[i].red) return i;
    }
    return -1;
}

Image Multiply(const Image& f1, const Image& f2) {
    Image combined;
    combined.pixels.reserve(f2.pixels.size());
    combined.header.idLength = f2.header.idLength;
    combined.header.cmapType = f2.header.cmapType;
    combined.header.dataTypeCode = f2.header.dataTypeCode;
    combined.header.cmapOrigin = f2.header.cmapOrigin;
    combined.header.cmapLength = f2.header.cmapLength;
    combined.header.cmapDepth = f2.header.cmapDepth;
    combined.header.xOrigin = f2.header.xOrigin;
    combined.header.yOrigin = f2.header.yOrigin;
    combined.header.width = f2.header.width;
    combined.header.height = f2.header.height;
    combined.header.bitsPerPixel = f2.header.bitsPerPixel;
    combined.header.imageDescriptor = f2.header.imageDescriptor;
    for (int i = 0; i <f2.pixels.size(); ++i) {
        Pixel p;
        float n1blue = f1.pixels[i].blue / 255.0f;
        float n2blue = f2.pixels[i].blue / 255.0f;
        float temp = (n1blue * n2blue * 255) + 0.5f;
        int temp2 = static_cast<int>(temp);
        unsigned char blue = static_cast<unsigned char>(temp2);
        p.blue = blue;

        float n1green = f1.pixels[i].green / 255.0f;
        float n2green = f2.pixels[i].green / 255.0f;
        temp = (n1green * n2green * 255) + 0.5f;
        temp2 = static_cast<int>(temp);
        unsigned char green = static_cast<unsigned char>(temp2);
        p.green = green;

        float n1red = f1.pixels[i].red / 255.0f;
        float n2red = f2.pixels[i].red / 255.0f;
        temp = (n1red * n2red * 255) + 0.5f;
        temp2 = static_cast<int>(temp);
        unsigned char red = static_cast<unsigned char>(temp2);
        p.red = red;

        combined.pixels.push_back(p);
    }
    return combined;
}

Image ScaleRed(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newRed = f1.pixels[i].red * value;
        if (newRed > 255)
            newRed = 255;
        else if (newRed < 0)
            newRed = 0;
        p.blue = f1.pixels[i].blue;
        p.green = f1.pixels[i].green;
        p.red = static_cast<unsigned char>(newRed);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image ScaleGreen(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newGreen = f1.pixels[i].green * value;
        if (newGreen > 255)
            newGreen = 255;
        else if (newGreen < 0)
            newGreen = 0;
        p.blue = f1.pixels[i].blue;
        p.red = f1.pixels[i].red;
        p.green = static_cast<unsigned char>(newGreen);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image ScaleBlue(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newBlue = f1.pixels[i].blue * value;
        if (newBlue > 255)
            newBlue = 255;
        else if (newBlue < 0)
            newBlue = 0;
        p.red = f1.pixels[i].red;
        p.green = f1.pixels[i].green;
        p.blue = static_cast<unsigned char>(newBlue);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image Subtract(const Image& f1, const Image& f2) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int bottomblue = f2.pixels[i].blue;
        int topblue = f1.pixels[i].blue;
        int temp = topblue - bottomblue;
        int combinedblue;
        if (temp < 0)
            combinedblue = 0;
        else if (temp > 255)
            combinedblue = 255;
        else
            combinedblue = temp;
        p.blue = static_cast<unsigned char>(combinedblue);

        int bottomgreen = f2.pixels[i].green;
        int topgreen = f1.pixels[i].green;
        temp = topgreen - bottomgreen;
        int combinedgreen;
        if (temp < 0)
            combinedgreen = 0;
        else if (temp > 255)
            combinedgreen = 255;
        else
            combinedgreen = temp;
        p.green = static_cast<unsigned char>(combinedgreen);

        int bottomred = f2.pixels[i].red;
        int topred = f1.pixels[i].red;
        temp = topred - bottomred;
        int combinedred;
        if (temp < 0)
            combinedred = 0;
        else if (temp > 255)
            combinedred = 255;
        else
            combinedred = temp;
        p.red = static_cast<unsigned char>(combinedred);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image Screen(const Image& f1, const Image& f2) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        float n1blue = f1.pixels[i].blue / 255.0f;
        float n2blue = f2.pixels[i].blue / 255.0f;
        float temp = 1 - ((1 - n1blue) * (1 - n2blue));
        int temp2 = static_cast<int>(temp * 255.0f + 0.5f);
        p.blue = static_cast<char>(temp2);

        float n1green = f1.pixels[i].green / 255.0f;
        float n2green = f2.pixels[i].green / 255.0f;
        temp = 1 - ((1 - n1green) * (1 - n2green));
        temp2 = static_cast<int>(temp * 255.0f + 0.5f);
        p.green = static_cast<char>(temp2);

        float n1red = f1.pixels[i].red / 255.0f;
        float n2red = f2.pixels[i].red / 255.0f;
        temp = 1 - ((1 - n1red) * (1 - n2red));
        temp2 = static_cast<int>(temp * 255.0f + 0.5f);
        p.red = static_cast<char>(temp2);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image Add(const Image& f1, const Image& f2) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int bottomblue = f2.pixels[i].blue;
        int topblue = f1.pixels[i].blue;
        int temp = topblue + bottomblue;
        int combinedblue;
        if (temp < 0)
            combinedblue = 0;
        else if (temp > 255)
            combinedblue = 255;
        else
            combinedblue = temp;
        p.blue = static_cast<unsigned char>(combinedblue);

        int bottomgreen = f2.pixels[i].green;
        int topgreen = f1.pixels[i].green;
        temp = topgreen + bottomgreen;
        int combinedgreen;
        if (temp < 0)
            combinedgreen = 0;
        else if (temp > 255)
            combinedgreen = 255;
        else
            combinedgreen = temp;
        p.green = static_cast<unsigned char>(combinedgreen);

        int bottomred = f2.pixels[i].red;
        int topred = f1.pixels[i].red;
        temp = topred + bottomred;
        int combinedred;
        if (temp < 0)
            combinedred = 0;
        else if (temp > 255)
            combinedred = 255;
        else
            combinedred = temp;
        p.red = static_cast<unsigned char>(combinedred);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image AddRed(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newRed = f1.pixels[i].red + value;
        if (newRed > 255)
            newRed = 255;
        else if (newRed < 0)
            newRed = 0;
        p.blue = f1.pixels[i].blue;
        p.green = f1.pixels[i].green;
        p.red = static_cast<unsigned char>(newRed);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image AddGreen(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newGreen = f1.pixels[i].green + value;
        if (newGreen > 255)
            newGreen = 255;
        else if (newGreen < 0)
            newGreen = 0;
        p.blue = f1.pixels[i].blue;
        p.red = f1.pixels[i].red;
        p.green = static_cast<unsigned char>(newGreen);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image AddBlue(const Image& f1, int value) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        int newBlue = f1.pixels[i].blue + value;
        if (newBlue > 255)
            newBlue = 255;
        else if (newBlue < 0)
            newBlue = 0;
        p.red = f1.pixels[i].red;
        p.green = f1.pixels[i].green;
        p.blue = static_cast<unsigned char>(newBlue);

        combined.pixels.push_back(p);
    }
    return combined;
}

Image Overlay(const Image& f1, const Image& f2) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;

        float n2blue = f2.pixels[i].blue / 255.0f;
        if (n2blue <= 0.5) {
            float n1blue = f1.pixels[i].blue / 255.0f;
            float temp = (2 * n1blue * n2blue * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.blue = static_cast<unsigned char>(temp2);
        }
        else {
            float n1blue = f1.pixels[i].blue / 255.0f;
            float temp = ((1 - (2 * (1 - n1blue) * (1 - n2blue))) * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.blue = static_cast<unsigned char>(temp2);
        }

        float n2green = f2.pixels[i].green / 255.0f;
        if (n2green <= 0.5) {
            float n1green = f1.pixels[i].green / 255.0f;
            float temp = (2 * n1green * n2green * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.green = static_cast<unsigned char>(temp2);
        }
        else {
            float n1green = f1.pixels[i].green / 255.0f;
            float temp = ((1 - (2 * (1 - n1green) * (1 - n2green))) * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.green = static_cast<unsigned char>(temp2);
        }

        float n2red = f2.pixels[i].red / 255.0f;
        if (n2red <= 0.5) {
            float n1red = f1.pixels[i].red / 255.0f;
            float temp = (2 * n1red * n2red * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.red = static_cast<unsigned char>(temp2);
        }
        else {
            float n1red = f1.pixels[i].red / 255.0f;
            float temp = ((1 - (2 * (1 - n1red) * (1 - n2red))) * 255) + 0.5f;
            int temp2 = static_cast<int>(temp);
            p.red = static_cast<unsigned char>(temp2);
        }

        combined.pixels.push_back(p);
    }
    return combined;
}

Image RedChannel(const Image& f1) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;
        p.blue = f1.pixels[i].red;
        p.green = f1.pixels[i].red;
        p.red = f1.pixels[i].red;
        combined.pixels.push_back(p);
    }
    return combined;
}

Image GreenChannel(const Image& f1) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;
        p.blue = f1.pixels[i].green;
        p.green = f1.pixels[i].green;
        p.red = f1.pixels[i].green;
        combined.pixels.push_back(p);
    }
    return combined;
}

Image BlueChannel(const Image& f1) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;
        p.blue = f1.pixels[i].blue;
        p.green = f1.pixels[i].blue;
        p.red = f1.pixels[i].blue;
        combined.pixels.push_back(p);
    }
    return combined;
}

Image CombineChannels(const Image& f1, const Image& f2, const Image& f3) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = 0; i < f1.pixels.size(); ++i) {
        Pixel p;
        p.blue = f1.pixels[i].blue;
        p.green = f2.pixels[i].green;
        p.red = f3.pixels[i].red;
        combined.pixels.push_back(p);
    }
    return combined;
}

Image Rotate(const Image& f1) {
    Image combined;
    combined.pixels.reserve(f1.pixels.size());
    combined.header.idLength = f1.header.idLength;
    combined.header.cmapType = f1.header.cmapType;
    combined.header.dataTypeCode = f1.header.dataTypeCode;
    combined.header.cmapOrigin = f1.header.cmapOrigin;
    combined.header.cmapLength = f1.header.cmapLength;
    combined.header.cmapDepth = f1.header.cmapDepth;
    combined.header.xOrigin = f1.header.xOrigin;
    combined.header.yOrigin = f1.header.yOrigin;
    combined.header.width = f1.header.width;
    combined.header.height = f1.header.height;
    combined.header.bitsPerPixel = f1.header.bitsPerPixel;
    combined.header.imageDescriptor = f1.header.imageDescriptor;
    for (int i = f1.pixels.size()-1; i >= 0; --i) {
        Pixel p;
        p.blue = f1.pixels[i].blue;
        p.green = f1.pixels[i].green;
        p.red = f1.pixels[i].red;
        combined.pixels.push_back(p);
    }
    return combined;
}

void Part1() {
    Image image1("input/layer1.tga");
    Image image2("input/pattern1.tga");
    Image newImage = Multiply(image1, image2);
    newImage.Write("output/part1.tga");

    Image image3("input/car.tga");
    Image image4("input/layer2.tga");
    Image newImage2 = Subtract(image3, image4);
    newImage2.Write("output/part2.tga");

    Image image5("input/layer1.tga");
    Image image6("input/pattern2.tga");
    Image newImage3 = Multiply(image5, image6);
    Image image7("input/text.tga");
    Image newImage4 = Screen(newImage3, image7);
    newImage4.Write("output/part3.tga");

    Image image8("input/layer2.tga");
    Image image9("input/circles.tga");
    Image newImage5 = Multiply(image8, image9);
    Image image10("input/pattern2.tga");
    Image newImage6 = Subtract(newImage5, image10);
    newImage6.Write("output/part4.tga");

    Image image11("input/layer1.tga");
    Image image12("input/pattern1.tga");
    Image newImage7 = Overlay(image11, image12);
    newImage7.Write("output/part5.tga");

    Image image13("input/car.tga");
    Image newImage8 = AddGreen(image13, 200);
    newImage8.Write("output/part6.tga");

    Image image14("input/car.tga");
    Image newImage9 = ScaleRed(image14, 4);
    Image newImage10 = ScaleBlue(newImage9, 0);
    newImage10.Write("output/part7.tga");

    Image image15("input/car.tga");
    Image newImage11 = RedChannel(image15);
    newImage11.Write("output/part8_r.tga");

    Image image16("input/car.tga");
    Image newImage12 = GreenChannel(image16);
    newImage12.Write("output/part8_g.tga");

    Image image17("input/car.tga");
    Image newImage13 = BlueChannel(image17);
    newImage13.Write("output/part8_b.tga");

    Image image18("input/layer_blue.tga");
    Image image19("input/layer_green.tga");
    Image image20("input/layer_red.tga");
    Image newImage14 = CombineChannels(image18, image19, image20);
    newImage14.Write("output/part9.tga");

    Image image21("input/text2.tga");
    Image newImage15 = Rotate(image21);
    newImage15.Write("output/part10.tga");
}
