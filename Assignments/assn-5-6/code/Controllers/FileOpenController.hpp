// NOTE: don't forget to close all files
// TODO: allow for files to be outside of working dir.
class FileOpenController {
    public:
        vector<float> eachMonthsAvg;
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
            // dispayData();
            calculateMonthlyAverages();

            cout << "------------ Averages for each month ------------" << endl;
            for (int i = 0; i < eachMonthsAvg.size(); i++) {
                int monthHolder = i + 1;
                cout << "Month: " + to_string(monthHolder) + "'s average: " + to_string(eachMonthsAvg[i]) << endl;
            }
            cout << "--------------------------------------------------" << endl;
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

        // helpful for debugging
        // TODO: remove when do
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

            for (int i = 0; i < maxTempWeatherData.size(); i++) {
                cout << "Month: " + months[i] + " Temp: " + std::to_string(maxTempWeatherData[i]) << endl;
            }
        }

        // this is probably the most upsetting function of all the functions in this project
        // I was rushing so I made things more static than I'd like to
        void calculateMonthlyAverages () {
            vector<float> jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec;

            // a little bit of blunt force trauma
            for (int i = 0; i < months.size(); i++) {
                if (months[i] == "01") {
                    jan.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "02") {
                    feb.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "03") {
                    mar.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "04") {
                    apr.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "05") {
                    may.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "06") {
                    jun.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "07") {
                    jul.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "08") {
                    aug.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "09") {
                    sep.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "10") {
                    oct.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "11") {
                    nov.push_back(maxTempWeatherData[i]);
                } else if (months[i] == "12") {
                    dec.push_back(maxTempWeatherData[i]);
                }
            }

            // store each months average in a vector
            eachMonthsAvg.push_back(calculateAvg(jan));
            eachMonthsAvg.push_back(calculateAvg(feb));
            eachMonthsAvg.push_back(calculateAvg(mar));
            eachMonthsAvg.push_back(calculateAvg(apr));
            eachMonthsAvg.push_back(calculateAvg(may));
            eachMonthsAvg.push_back(calculateAvg(jun));
            eachMonthsAvg.push_back(calculateAvg(jul));
            eachMonthsAvg.push_back(calculateAvg(aug));
            eachMonthsAvg.push_back(calculateAvg(sep));
            eachMonthsAvg.push_back(calculateAvg(oct));
            eachMonthsAvg.push_back(calculateAvg(nov));
            eachMonthsAvg.push_back(calculateAvg(dec));
        }

        // this does the actual calculation
        float calculateAvg (vector<float> v) {
            float avg = accumulate(v.begin(), v.end(), (double) 0) / v.size();
            return avg;
        }
};
