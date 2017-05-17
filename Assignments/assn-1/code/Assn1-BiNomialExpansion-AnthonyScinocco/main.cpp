#include <iostream>
#include "./Controllers/BiNomial.hpp"

using namespace std;

void takeInput()
{
    bool keepGoing = true;
    int value;

    while (keepGoing)
    {
        cout << "Enter an exponent from 0 to 10: " << endl;
        cin >> value;

        if (value >= 0 && value <= 10)
        {
            BiNomial myBiNomial;
            int result = myBiNomial.numExponents(value);
            myBiNomial.display(result);
        } else if (value == 12)
        {
            keepGoing = false;
        } else 
        {
            cout << "NUMBER MUST BE FROM 1 TO 10!!!" << endl;
        }
    }
}

int main()
{
    cout << "----------------------------------" << endl;
    cout << "Enter '12' to exit the program" << endl;
    takeInput();
    cout << "Goodbye!" << endl;
    return 1;
}