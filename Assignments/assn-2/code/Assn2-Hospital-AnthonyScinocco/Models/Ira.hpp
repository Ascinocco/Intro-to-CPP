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

        void optionTwoCalculator(double hrs)
        {
            double mlPerHour = (1 / hrs) * 1000;
            cout << "----------------------------------------" << endl;
            cout << "The rate in ML per hour is: " << endl;
            display(mlPerHour);
            cout << "----------------------------------------" << endl;
            cout << "\n" << endl;
        }

        void optionThreeCalculator(double mgKgHr, double wKg, double mgMl)
        {
            double mlPerHour = (mgKgHr * wKg) * mgMl;
            cout << "----------------------------------------" << endl;
            cout << "The rate in ML per hour is: " << endl;
            display(mlPerHour);
            cout << "----------------------------------------" << endl;
            cout << "\n" << endl;
        }

        void optionFourCalculator(double uPerHr, double uPerMl)
        {
            double mlPerHour = (uPerHr / uPerMl);
            cout << "----------------------------------------" << endl;
            cout << "The rate in ML per hour is: " << endl;
            display(mlPerHour);
            cout << "----------------------------------------" << endl;
            cout << "\n" << endl;
        }
};