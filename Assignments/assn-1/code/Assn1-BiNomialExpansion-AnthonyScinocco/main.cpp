#include <iostream>
#include "./Models/PascalTriangle.hpp"

using namespace std;

void takeInput()
{
    bool keepGoing = true;
    while (keepGoing)
    {
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
                takeInput();
            }

            myTriangle.display();

        }
    }
}

int main()
{
    cout << "-----------------------------------------------" << endl;
    cout << "Enter 11 to exit!" << endl;
    takeInput();
    return 0;
}