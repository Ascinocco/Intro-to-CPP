#include "./Utilities/loader.hpp"

string currFileName = "";
string currTempFileName = "";

// prints my name out to the screen
void printName () {
    cout << "Hi Anthony Scinocco (200271982)" << endl;
}

void goodBye () {
    cout << "GoodBye!" << endl;
}

void openFileToProcess () {
    FileOpenController fileOpener;
    currFileName = fileOpener.fileName;
    currTempFileName = fileOpener.currTempFileName;
    fileOpener.closeFile();
}

void saveTheClimateData () {
    FileSaveController fileSaver;
    fileSaver.closeFile();
}

// runs menu system
void menu () {
    char choice = 'z';
    bool quit = false;

    while (!quit) {
        cout << "Please make a selection from the following:" << endl;
        cout << "1.\tOpen a Climate File to Process" << endl;
        cout << "2.\tSave the Climate Data (Only the last file you processed. Temp files are always available in the data dir.)" << endl;
        cout << "3.\tExit" << endl;

        try {
            cin >> choice;

            if (choice == '1') {
                openFileToProcess();
            } else if (choice == '2') {
                saveTheClimateData();
            } else if (choice == '3') {
                quit = true;
            } else {
                cout << "Invalid Option. Try again." << endl;
            }

        } catch (const exception& ex) {
            cout << "That is not a valid option. Try again." << endl;
        }
   }
}

// entry point into my application
int main () {
    printName();
    menu();
    goodBye();
    return EXIT_SUCCESS;
}
