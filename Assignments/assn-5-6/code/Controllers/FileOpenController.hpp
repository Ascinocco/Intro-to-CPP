class FileOpenController {
    public:
        string fileName;
        ofstream myFile;

        FileOpenController() {
            takeFileName();            
            myFile.open("2014-Barrie-Oro-Daily.csv");

            if (myFile.is_open()) {
                cout << "It's fucking open" << endl;
                myFile.close();
                exit(1);
            } else  {
                cout << "Go fuck yourself" << endl;
            }
        }

        void takeFileName () {
            string myFileName = "";
            cout << "What is the name of the file you would like to open: " << endl;

            try {
                cin >> myFileName;
                fileName = myFileName;
            } catch (const exception& ex) {
                cout << "Bad input. Try again." << endl;
                takeFileName();
            }
        }
};