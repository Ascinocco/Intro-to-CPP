class FileSaveController {
    public:
        string fileName;
        string tempFileName;

        // it's only really a psuedo save.
        // I'll just make a copy of the temp
        // and name it based on user input
        FileSaveController (string currFileName, string currTempFileName) {
            fileName = currFileName;
            tempFileName = currFileName;
        }

        // TODO: implement file closing after file saved.
        void closeFile() {

        }
};
