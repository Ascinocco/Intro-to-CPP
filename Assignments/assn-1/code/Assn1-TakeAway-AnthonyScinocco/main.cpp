#include <iostream>
#include "./Controllers/TakeAway.hpp"

using namespace std;

void takeInput()
{
    cout << "Enter '9' to exit program" << endl;
    bool keepGoing = true;
    int year;

    while(keepGoing)
    {
        cout << "Enter a year: " << endl;
        cin >> year;

        if (year == 9)
        {
            keepGoing = false;
        } else 
        {
            TakeAway myTakeAway;
            myTakeAway.setYear(year);

            double result;
            result = myTakeAway.calculate();

            if (result > 0 && result != 9)
            {
                cout << "---------------------------------------" << endl;
                cout << "The prediction is: " << result << endl;
                cout << "---------------------------------------" << endl;
            } else if (result == 9)
            {
                keepGoing = false;
            }
        }
    }
}

int main()
{
    cout << "------------------------------------------------------------" << endl;
    cout << "Entering a year below 2005 will cause this progam to exit!" << endl;
    takeInput();
    cout << "-----------------" << endl;
    cout << "Goodbye!" << endl;
    cout << "-----------------" << endl;
    return 1;
}