#include "./loader.hpp"

using namespace std;

void welcome()
{
    cout << "----------------------------------------" << endl;
    cout << "Hello, my name is Intravenous Rate Assistant" << endl;
    cout << "but you can call me Ira :)" << endl;
    cout << "----------------------------------------" << endl;
}

int menu()
{
    welcome();

    bool keepGoing = true;
    int choice;

    while(keepGoing)
    {
        cout << "Please make a selection: " << endl;
        cout << "(1) ml/hr & tubing drop factor " << endl;
        cout << "(2) 1 L for n hr " << endl;
        cout << "(3) mg/kg/hr & concentration in mg/ml " << endl;
        cout << "(4) units/hr & concentration in units/ml " << endl;
        cout << "(5) Exit " << endl;
        cout << endl;

        cin >> choice;

        if (choice == 1 || choice == 2 || choice == 3 || choice == 4 || choice == 5)
        {
            keepGoing = false;
        } else
        {
            cout << "----------------------------------------" << endl;
            cout << "Invalid Selection \n Please Enter a selection from 1 - 5" << endl;
            cout << "----------------------------------------" << endl;
        }
    }

    return choice;
}

/**
    In this particular case I believe it is better to use generic function names that relate to the option selection
    than descriptive names relating to the measurements as they would make for horribly hard to read and remember names
 */

void optionOneHandler(Ira ira)
{
    double MLPerHour,
           dropsPerML; 
    // get user input

    MLPerHour = 5;
    dropsPerML = 20;

    // pass to calculator
    ira.optionOneCalculator(MLPerHour, dropsPerML);
}

void optionTwoHandler(Ira ira)
{
    ira.optionTwoCalculator();
}

void optionThreeHandler(Ira ira)
{
    ira.optionThreeCalculator();
}

void optionFourHandler(Ira ira)
{
    ira.optionFourCalculator();
}

void optionFiveHandler()
{
    cout << "----------------------------------------" << endl;
    cout << "Goodbye! :)" << endl;
    cout << "----------------------------------------" << endl;
}

int main()
{
    // get the selection from the menu
    int choice = menu();

    // instantiate ira here and pass as function arg
    Ira ira;

    if (choice == 1)
    {
        optionOneHandler(ira);
        main();
    } else if (choice == 2)
    {
        optionTwoHandler(ira);
        main();
    } else if (choice == 3)
    {
        optionThreeHandler(ira);
        main();
    } else if (choice == 4)
    {
        optionFourHandler(ira);
        main();
    } else if (choice == 5)
    {
        optionFiveHandler();
    }
}