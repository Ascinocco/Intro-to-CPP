#include <iostream>
#include "./loader.hpp"

using namespace std;

void takeInput()
{
    int choice = 8;

    while(choice != 9)
    {
        bool success = false;
        double boilingPoint;

        cout << "Celcius (0) \nFahrenheit (1) \nKelvin (2) \nSelect your unit of measure: " << endl;
        cin >> choice;

        cout << "Enter boiling point: " << endl;
        cin >> boilingPoint;

        Water myWater;
        Mercury myMercury;
        Copper myCopper;
        Silver mySilver;
        Gold myGold;

        cout << "-------------------" << endl;

        if (myWater.isInRange(choice, boilingPoint))
        {
            cout << "Substance is water" << endl;
            success = true;
        }

        if (myMercury.isInRange(choice, boilingPoint))
        {
            cout << "Substance is Mercury" << endl;
            success = true;
        }

        if (myCopper.isInRange(choice, boilingPoint))
        {
            cout << "Substance is copper" << endl;
            success = true;
        }

        if (mySilver.isInRange(choice, boilingPoint))
        {
            cout << "Substance is Silver" << endl;
            success = true;
        }

        if (myGold.isInRange(choice, boilingPoint))
        {
            cout << "Substance is Gold" << endl;
            success = true;
        }

        if (success == false)
        {
            cout << "Substance unknown..." << endl;
        }
        
        cout << "-------------------" << endl;
    }
}

int main()
{
    takeInput();
    return 1;
}