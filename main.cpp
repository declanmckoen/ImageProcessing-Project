#include <iostream>
#include <string>
#include <fstream>
#include "image.h"
#include "functions.h"
using namespace std;


int main(int argc, char** argv) {
    Part1();
    string arg1;
    string arg2;
    string function;
    string outFile;
    if (argc > 1)
        arg1 = argv[1];

    //Argument 1 (output file)
    if (argc == 1 || (argc == 2 && arg1 == "--help")) {
        PrintHelp();
        exit(0);
    }
    else if (arg1.length() <= 4 || arg1.substr(arg1.length()-4, 4) != ".tga") {
        cout << "Invalid file name." << endl;
        exit(1);
    }
    else {
        outFile = arg1;
    }

    //Argument 2 (source file of tracking image)
    if (argc > 2)
        arg2 = argv[2];
    else {
        cout << "Invalid file name." << endl;
        exit(1);
    }
    if (arg2.length() <= 4 || arg2.substr(arg2.length()-4, 4) != ".tga") {
        cout << "Invalid file name." << endl;
        exit(1);
    }
    ifstream testFile;
    testFile.open(arg2, ios_base::binary);
    if (!testFile.is_open()) {
        cout << "File does not exist." << endl;
        exit(1);
    }
    testFile.close();
    Image trackingImage(arg2);


    //Image manipulation
    if (argc < 4) {
        cout << "Invalid method name." << endl;
        exit(1);
    }
    int i = 3;
    while (i < argc) {
        function = argv[i];
        string image1;
        string image2;
        string value;
        if (function == "multiply") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            image1 = argv[i+1];
            if (image1.length() <= 4 || image1.substr(image1.length() - 4, 4) != ".tga") {
                cout << "Invalid argument, invalid file name." << endl;
                exit(1);
            }
            testFile.open(image1);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            Image multiplyImage(image1);
            trackingImage = Multiply(trackingImage, multiplyImage);
            i += 2;
        }
        else if (function == "subtract") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            image1 = argv[i+1];
            if (image1.length() <= 4 || image1.substr(image1.length() - 4, 4) != ".tga") {
                cout << "Invalid argument, invalid file name." << endl;
                exit(1);
            }
            testFile.open(image1);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            Image subtractImage(image1);
            trackingImage = Subtract(trackingImage, subtractImage);
            i += 2;
        }
        else if (function == "overlay") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            image1 = argv[i+1];
            if (image1.length() <= 4 || image1.substr(image1.length() - 4, 4) != ".tga") {
                cout << "Invalid argument, invalid file name." << endl;
                exit(1);
            }
            testFile.open(image1);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            Image overlayImage(image1);
            trackingImage = Overlay(trackingImage, overlayImage);
            i += 2;
        }
        else if (function == "screen") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            image1 = argv[i+1];
            if (image1.length() <= 4 || image1.substr(image1.length() - 4, 4) != ".tga") {
                cout << "Invalid argument, invalid file name." << endl;
                exit(1);
            }
            testFile.open(image1);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            Image screenImage(image1);
            trackingImage = Screen(screenImage, trackingImage);
            i += 2;
        }
        else if (function == "combine") {
            if (argc <= i+2) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            image1 = argv[i+1];
            image2 = argv[i+2];
            if (image1.length() <= 4 || image1.substr(image1.length() - 4, 4) != ".tga") {
                cout << "Invalid argument, invalid file name." << endl;
                exit(1);
            }
            testFile.open(image1);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            testFile.open(image2);
            if (!testFile.is_open()) {
                cout << "Invalid argument, file does not exist." << endl;
                exit(1);
            }
            testFile.close();
            Image combineImage1(image1);
            Image combineImage2(image2);
            trackingImage = CombineChannels(combineImage2, combineImage1, trackingImage);
            i += 3;
        }
        else if (function == "flip") {
            trackingImage = Rotate(trackingImage);
            i++;
        }
        else if (function == "onlyred") {
            trackingImage = RedChannel(trackingImage);
            i++;
        }
        else if (function == "onlygreen") {
            trackingImage = GreenChannel(trackingImage);
            i++;
        }
        else if (function == "onlyblue") {
            trackingImage = BlueChannel(trackingImage);
            i++;
        }
        else if (function == "addred") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = AddRed(trackingImage, newValue);
            i += 2;
        }
        else if (function == "addgreen") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = AddGreen(trackingImage, newValue);
            i += 2;
        }
        else if (function == "addblue") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = AddBlue(trackingImage, newValue);
            i += 2;
        }
        else if (function == "scalered") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = ScaleRed(trackingImage, newValue);
            i += 2;
        }
        else if (function == "scalegreen") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = ScaleGreen(trackingImage, newValue);
            i += 2;
        }
        else if (function == "scaleblue") {
            if (argc <= i+1) {
                cout << "Missing argument." << endl;
                exit(1);
            }
            value = argv[i+1];
            int newValue;
            try {
                newValue = stoi(value);
            }
            catch(invalid_argument& e) {
                cout << "Invalid argument, expected number." << endl;
                exit(1);
            }
            trackingImage = ScaleBlue(trackingImage, newValue);
            i += 2;
        }
        else {
            cout << "Invalid method name." << endl;
            exit(1);
        }
    }
    trackingImage.Write(outFile);
}


