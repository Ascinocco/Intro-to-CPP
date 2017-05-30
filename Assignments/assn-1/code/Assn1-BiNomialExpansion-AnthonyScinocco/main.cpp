#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <regex>
#include "./Models/PascalTriangle.hpp"
#include "./Models/BiNomialExpansion.hpp"

using namespace std;

void takePascalTriangeInput()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Enter 11 to exit!" << endl;
        cout << "-----------------------------------------------" << endl;

        int choice;
        cout << "Enter the number of rows desired (1 - 10): " << endl;
        cin >> choice;

        if (choice == 11)
        {
            keepGoing = false;
        } else 
        {
            PascalTriangle myTriangle;
            bool isValidChoice = myTriangle.setNumOfRows(choice);
            
            if (isValidChoice == false)
            {
                takePascalTriangeInput();
            }

            myTriangle.display();

        }
    }
}

void takeEquationExpansionInput()
{
    bool keepGoing = true;
    while (keepGoing)
    {
        cout << "-----------------------------------------------" << endl;
        cout << "Enter ~ to exit!" << endl;
        cout << "-----------------------------------------------" << endl;
        cout << "DO NOT ENTER WHITE SPACE...SORRY...IT BREAKS EVERYTHING AND STRIPING THE WHITE SPACE DOESN'T FIX IT :(" << endl;
        cout << "-----------------------------------------------" << endl;

        string choice;
        cout << "Enter your equation: " << endl;
        cin >> choice;

        // remove all the white space so that I can sleep at night
        // choice.erase( remove_if( choice.begin(), choice.end(), ::isspace ), choice.end());

        if (choice.compare("~") == 0)
        {
            keepGoing = false;
        } else
        {
            BiNomialExpansion biExp;
            biExp.parse(choice);
            biExp.expand();
            biExp.display();
        }
    }
}

int main()
{
    int choice;
    cout << "Enter a choice: \n Draw Pascal's Triangle (1): \n Expand Equation (2): " << endl;
    cin >> choice;
    
    if (choice == 1)
    {
        takePascalTriangeInput();
    } else if (choice == 2)
    {
        takeEquationExpansionInput();
    }

    cout << "Goodbye! :)" << endl;
    return 0;
}