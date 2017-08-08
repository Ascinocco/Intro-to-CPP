// NOTE: don't forget to close all files
// TODO: allow for files to be outside of working dir.
class FileOpenController {
    public:
        vector<string> maxTempWeatherData;
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

            readFile();
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

        // this is so upsetting
        void readFile () {

            int lineCount = 0;
            bool afterSix = false;
            string value;

            while (myFile.good()) {
                getline(myFile, value, ',');
                lineCount++;

                if (lineCount == 6 && afterSix == false) {
                    cout << string(value, 1, value.length() - 2) << endl;
                    lineCount = 0;
                    afterSix = true;
                }

                if (lineCount == 20 && afterSix == true) {
                    lineCount = 0;
                    afterSix = false;
                }
            }


            // int commaCount = 0;
            // int captureCount = 0;
            // string theDataIWant = "";

            // while (myFile.good()) {
            //     char currValue = (char) myFile.get();
                
            //     if (currValue == ',') {
            //         commaCount++;
            //     }

            //     if (commaCount == 5 && captureCount < 5) {
            //         // grab the data between the  "" and add it to csv
                    
            //         theDataIWant += currValue;
            //         captureCount++;
            //     }

            //     if (commaCount >= 5 && captureCount >= 5) {
            //         // move on
            //         commaCount = 0;
            //         captureCount = 0;
            //         maxTempWeatherData.push_back(theDataIWant);
            //         cout << theDataIWant << endl;
            //         theDataIWant = "";
            //     }
            // }
        }
};