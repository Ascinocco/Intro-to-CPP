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
            // process weather data
            parseAndStoreMaxTempData();
            parseAndStoreMonths();
            dispayData();
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
                    } else {
                        maxTempWeatherData.push_back(0.0);
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

        // store months in a vector
        void parseAndStoreMonths() {
            closeFile();
            openFile();

            int lcThree = 0;
            bool afterThree = false;
            string valueThree;

            while (myFile.good()) {
                getline(myFile, valueThree, ',');
                lcThree++;
                // for months
                if (lcThree == 3 && afterThree == false) {
                    string tempThree = string(valueThree, 1, valueThree.length() - 2);

                    tempThree.erase(
                        remove( tempThree.begin(), tempThree.end(), '\"' ), tempThree.end()
                    );

                    if (tempThree.length() > 0) {
                        months.push_back(tempThree);
                    }

                    lcThree = 0;
                    afterThree = true;
                }

                if (lcThree == 23 && afterThree == true) {
                    lcThree = 0;
                    afterThree = false;
                }
            }
        }

        void dispayData () {
            int size = 0;

            if (months.size() != maxTempWeatherData.size()) {
                cout << "Data mismatch, results will not be complete." << endl;
                if (months.size() > maxTempWeatherData.size()) {
                    size = maxTempWeatherData.size();
                } else {
                    size = months.size();
                }
            }

            cout << months.size() << endl;
            cout << maxTempWeatherData.size() << endl;

            // for (int i = 0; i < maxTempWeatherData.size(); i++) {
            //     cout << " Temp: " + std::to_string(maxTempWeatherData[i]) << endl;
            // }
        }
};
