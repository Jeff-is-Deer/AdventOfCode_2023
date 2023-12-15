#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
#include <format>

using namespace std;

struct ProcessedFile
{
    vector<string> LineResultVector;
    size_t NumLines;
    int Result;
};

vector<string> GetFileContent(string const& path) {
    fstream myFile;
    vector<string> fileContent;
    string line;
    myFile.open(path);
    while (getline(myFile, line)) {
        fileContent.push_back(line);
    }
    myFile.close();
    return fileContent;
}



ProcessedFile Day1_1()
{
    ProcessedFile result = {};
    vector<string> processedIndex;
    vector<string> fileLines = GetFileContent(".\\TextFiles\\Day1\\day1_1.txt");
    int numFileLines = fileLines.size();
    int total = 0, finalNum = 0, lineNum = 0;
    string sentence;
    for (string line : fileLines) {
        lineNum++;
        for (int i = 0; i <= line.size(); i++) {
            char c = line[i];
            if (isdigit(c)) {
                int firstNum = line[i] - '0';
                finalNum = firstNum * 10;
                break;
            }
        }
        for (int i = line.size(); i >= 0; i--) {
            char c = line[i];
            if (isdigit(c)) {
                int secondNum = line[i] - '0';
                finalNum = finalNum + secondNum;
                break;
            }
        }
        total = total + finalNum;
    }
    return result;
} // COMPLETED


ProcessedFile Day1_2() {
    ProcessedFile result = {};
    map<string, int> numPairs;
    map<int, string> foundLocations;
    string sentence;
    int lineTotal = 0;
    vector<string>fileLines = GetFileContent(".\\TextFiles\\Day1\\day1_2.txt");
    result.NumLines = fileLines.size();
    numPairs["one"] = 1;
    numPairs["two"] = 2;
    numPairs["three"] = 3;
    numPairs["four"] = 4;
    numPairs["five"] = 5;
    numPairs["six"] = 6;
    numPairs["seven"] = 7;
    numPairs["eight"] = 8;
    numPairs["nine"] = 9;
    numPairs["1"] = 1;
    numPairs["2"] = 2;
    numPairs["3"] = 3;
    numPairs["4"] = 4;
    numPairs["5"] = 5;
    numPairs["6"] = 6;
    numPairs["7"] = 7;
    numPairs["8"] = 8;
    numPairs["9"] = 9;

    for (string line : fileLines) {
        int lineTotal = 0;
        string numStrOne = "";
        string numStrTwo = "";
        for (auto const& pair : numPairs) {
            int start = 0;
            size_t location = 0;
            while ((location = line.find(pair.first, start)) != string::npos) {
                foundLocations[location] = pair.first;
                start += (location + pair.first.length() - 1);
            }
        }
        numStrOne = foundLocations.begin()->second;
        numStrTwo = foundLocations.rbegin()->second;
        lineTotal = (numPairs[numStrOne] * 10) + numPairs[numStrTwo];
        result.Result += lineTotal;
        sentence = format("{0}  ---  {1}  ---  {2}",line,lineTotal,result.Result);
        result.LineResultVector.push_back(sentence);
        foundLocations.clear();
    }
    return result;
}