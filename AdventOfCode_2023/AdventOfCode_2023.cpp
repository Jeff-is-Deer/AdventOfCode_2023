// AdventOfCode_2023.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <stdlib.h>
#include "Day1.h"

int main()
{
    //vector<string> toSearch = Day1_1(); --- COMPLETE
    ProcessedFile ProcessedResult = Day1_2();
    string query;
    bool userExit = false;
    int int_input = 0;
    char input = ' ';
    int test;
    while (input != 'q') {
        test = 0;
        cout << "\n\t1) Display all results\n\t2) Display items 5 at a time\n\t3) Select specific line items" << endl;
        cin >> input;
        switch (input) {
        case '1':
            for (string line : ProcessedResult.LineResultVector) {
                cout << line << endl;
            }
            break;
        case '2':
            system("CLS");
            for (string line : ProcessedResult.LineResultVector) {
                cout << line << endl;
                test++;
                if (test == 5) {
                    test = 0;
                    cout << '\n';
                    system("pause");
                    system("CLS");
                }
            }
            break;
        case '3':
            while (int_input != 0) {
                system("CLS");
                cout << "  Input the line number to display: ";
                cin >> int_input;
                cout << ProcessedResult.LineResultVector[int_input] << '\n' << endl;
                system("pause");
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
