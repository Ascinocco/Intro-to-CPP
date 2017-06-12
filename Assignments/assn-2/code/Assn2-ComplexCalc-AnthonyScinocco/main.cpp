#include "./loader.hpp"

using namespace std;

int main()
{
    
    double aReal,
           aImag,
           bReal,
           bImag;

    bool keepGoing = true;
    int choice;

    // not an ideal solution
    while(keepGoing)
    {   
        cout << "---------------------------------" << endl;
        cout << "Complex Number Calculator...." << endl;
        cout << "---------------------------------" << endl;
        cout << "enter \"A real\": " << endl;
        cin >> aReal;

        cout << "enter \"A imag\": " << endl;
        cin >> aImag;

        cout << "Enter \"B real\": " << endl;
        cin >> bReal;

        cout << "Enter \"B imag\": " << endl;
        cin >> bImag;

        cout << "Select an operation...." << endl;
        cout << "---------------------------------" << endl;

        cout << " (1) Add \n (2) Subtract \n (3) Multiply \n (4) Divide " << endl;
        cin >> choice;

        ComplexCalculator calc(aReal, aImag, bReal, bImag);

        if (choice == 1)
        {
            calc.add();
        } else if (choice == 2)
        {
            calc.subtract();
        } else if (choice == 3)
        {
            calc.multiply();
        } else if (choice == 4)
        {
            calc.divide();
        }

        cout << "---------------------------------" << endl;
        cout << "Would you like run again? (1) yes | (2) no " << endl;
        cin >> choice;

        if (choice == 2)
        {
            keepGoing = false;
        }
    }

    return 0;
}