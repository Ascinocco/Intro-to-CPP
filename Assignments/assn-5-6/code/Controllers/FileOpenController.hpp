// NOTE: don't forget to close all files
// TODO: allow for files to be outside of working dir.
class FileOpenController {
    public:
        vector<float> maxTempWeatherData;
        vector<string> months;
        string fileName;
        ifstream myFile;
        FileOpenController() {
            bool fileFound = false;
            bool validName = false;

            while (!fileFound) {
                validName = takeFileName();

                if (validName) {
                    fileFound = openFile();
                }
            }

            parseAndStoreMaxTempData(); // process weather data
            parseAndStoreMonths(); // process the months the weather occured in
        }

        bool takeFileName () {
            bool validName = false;
            string myFileName = "";
            cout << "What is the name of the file you would like to open: " << endl;

            try {
                cin >> myFileName;
                validName = true;
                fileName = myFileName;
            } catch (const exception& ex) {
                cout << "Bad input. Try again." << endl;
                validName = false;
            }

            return validName;
        }

        bool openFile () {
            bool fileFound = false;
            try {
                if (myFile.is_open()) {
                    myFile.close();
                }

                string tempName = "./Data/" + fileName;
                myFile.open(tempName.c_str());

                if (myFile.is_open()) {
                    cout << "File opened." << endl;
                    fileFound = true;
                } else {
                    cout << "File not found." << endl;
                    fileFound = false;
                }
            } catch (const exception& ex) {
                cout << "Error occured opening file. Try again." << endl;
                fileFound = false;
            }

            return fileFound;
        }

        void closeFile () {
            cout << "Closing file..." << endl;
            myFile.close();
        }

        void parseAndStoreMaxTempData () {

            int lineCount = 0;
            bool afterSix = false;
            string value;

            while (myFile.good()) {
                getline(myFile, value, ',');
                lineCount++;

                if (lineCount == 6 && afterSix == false) {
                    string temp = string(value, 1, value.length() - 2);
                    
                    temp.erase(
                        remove( temp.begin(), temp.end(), '\"' ), temp.end()
                    );

                    if (temp.length() > 0) {
                        float tempAsFloat = ::atof(temp.c_str());
                        maxTempWeatherData.push_back(tempAsFloat);
                    }

                    lineCount = 0;
                    afterSix = true;
                }

                if (lineCount == 20 && afterSix == true) {
                    lineCount = 0;
                    afterSix = false;
                }
            }
        }

        void parseAndStoreMonths () {
            // int lineCount = 0;
            // bool afterThree = false;
            string value;

            while (myFile.good()) {
                getline(myFile, value, ',');
                cout << value << endl;
            }
                
            cout << string(value, 1, value.length() - 2) << endl;

            cout << myFile.good() << endl;

            while (myFile.good()) {
                getline(myFile, value, ',');
                lineCount++;
                
                cout << string(value, 1, value.length() - 2) << endl;

                if (lineCount == 3 && afterThree == false) {
                    string temp = string(value, 1, value.length() - 2);
                    cout << temp << endl;

                    lineCount = 0;
                    afterThree = true;
                }

                if (lineCount == 23 && afterThree == true) {
                    lineCount = 0;
                    afterThree = false;
                }
            }
        }
};