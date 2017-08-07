#include "./loader.hpp"

// prints my name out to the screen
void printName ()
{
    cout << "Hi Anthony Scinocco (200271982)" << endl;
}

// runs menu system
int menu ()
{
    int choice = 0;
    bool keepGoing = true;

    while (keepGoing) {
        cout << "Please make a selection from the following:" << endl;
        cout << "1.\tOpen a Climate File to Process" << endl;
        cout << "2.\tSave the Climate Data" << endl;
        cout << "3.\tExit" << endl;

        try {
            cin >> choice;

            if (choice < 1 || choice > 3) {
                cout << "Invalid option. Try again." << endl;
                choice = 0;
                keepGoing = true;
            } else {
                keepGoing = false;
            }

        } catch (const exception& ex) {
            cout << "Bad Selection. Try again." << endl;
            choice = 0;
            keepGoing = true;
        }
    }

    return choice;
}

// takes the users choice and runs the appropraite function
bool selectionDispatch(int choice)
{
    if (choice == 3) {
        return false;
    }
    
    cout << "Dispatching" << endl;
    return true;
}

// entry point into my application
int main ()
{
    printName();
    int choice = menu();
    bool keepGoing = selectionDispatch(choice);

    if (keepGoing) {
        main();
    }

    cout << "GoodBye!! :)" << endl;
    return EXIT_SUCCESS;
}