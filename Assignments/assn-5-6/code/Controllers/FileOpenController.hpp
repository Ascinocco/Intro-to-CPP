class FileOpenController {
    public:
        string fileName;

        FileOpenController() {
            takeFileName();
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