using namespace std;

class TakeAway
{
    private:
        int year;

    public:
        int getYear()
        {
            return year;
        }

        void setYear(int inYear)
        {
            year = inYear;
        }

        double calculate()
        {
            if (this->getYear() >= 2005)
            {
                int yearsSince2005 = this->getYear() - 2005;
                return 33.2 + (16.8 * this->getYear());
            } else
            {
                cout << "Year must be greater than or equal to 2005" << endl;
                return 9;
            }
        }
};