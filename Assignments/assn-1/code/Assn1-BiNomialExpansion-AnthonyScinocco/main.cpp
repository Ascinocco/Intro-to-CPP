#include <iostream>
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

        string choice;
        cout << "Enter your equation: " << endl;
        cin >> choice;

        BiNomialExpansion myBiExpansion;
        // myBiExpansion.parseEqn(choice);
        myBiExpansion.expand();
        myBiExpansion.display();

        // if (choice.compare("~") == 0)
        // {
        //     keepGoing = false;
        // } else
        // {
        //     BiNomialExpansion myBiExpansion;
        //     myBiExpansion.parseEqn(choice);
        //     myBiExpansion.expand();
        //     myBiExpansion.display();

        // }
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