//
//  main.cpp
//  Project
//
//  Created by Hoa on 5/7/19.
//  Copyright © 2019 Hoa Ly. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <fstream>
#include "utility.hpp"
#include "median.hpp"
#include "unistd.h"


int main(int argc, const char * argv[]) {
    
    /**Get current working directory**/
    string filePath;
    char cwd[256];
    if (getcwd(cwd, sizeof(cwd)) == NULL){
        perror("getcwd() error");
    }else{
        string s(cwd);
        filePath = s + "/images";
    }
    //cout << filePath << endl;
    vector<string> listImageFile = fileSysTem::listImageFile(filePath);
    ifstream openFile(listImageFile[0].c_str());
    string line;
    int lineNumber = 1;
    while(getline(openFile, line)){
        if (lineNumber < 4){
            lineNumber = lineNumber + 1;
            continue;
        }

        calculateMedian redPixelMedian; 
        calculateMedian greenPixelMedian;
        calculateMedian bluePixelMedian;
        for (auto const& image: listImageFile){
            vector<int> currentImagePixel = fileSysTem::goToLine(image, lineNumber);
            redPixelMedian.addNumber(currentImagePixel[0]);
            greenPixelMedian.addNumber(currentImagePixel[1]);
            bluePixelMedian.addNumber(currentImagePixel[2]);
        }
        cout <<"Line "<< lineNumber <<" "<< redPixelMedian.getMedian() << " " << greenPixelMedian.getMedian() << " " << bluePixelMedian.getMedian() << endl;
        lineNumber = lineNumber + 1;

    }
    return 0;
}
