using namespace std;

class Ira
{
    private:
        void display(double result)
        {
            ostringstream strs;
            strs << result;
            string str = strs.str();
            cout << str << endl;
        }

    public:
        void optionOneCalculator(double MLPerHour, double dropsPerML)
        {
            double dropRate = (MLPerHour / 60) * dropsPerML;
            cout << "----------------------------------------" << endl;
            cout << "The drop rate is: " << endl;
            display(dropRate);
            cout << "----------------------------------------" << endl;
            cout << "\n" << endl;
        }

        void optionTwoCalculator()
        {

        }

        void optionThreeCalculator()
        {

        }

        void optionFourCalculator()
        {

        }

};