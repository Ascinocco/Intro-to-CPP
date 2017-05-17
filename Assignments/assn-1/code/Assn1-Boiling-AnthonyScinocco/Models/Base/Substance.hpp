#include <iostream>

using namespace std;

class Substance
{
    private:
        double celcius, fahrenheit, kelvin;

    public:
        static const int CELCIUS = 0;
        static const int FAHRENHEIT = 1;
        static const int KELVIN = 2;

        double getCelcius()
        {
            return celcius;
        }

        double getFahrenheit()
        {
            return fahrenheit;
        }

        double getKelvin()
        {
            return kelvin;
        }

        void setCelcius(double cel)
        {
            celcius = cel;
        }

        void setFahrenheit(double fah)
        {
            fahrenheit = fah;
        }

        void setkelvin(double kel)
        {
            kelvin = kel;
        }

        bool isInRange(int selection, double value)
        { 
            if (selection == Substance::CELCIUS)
            {
                double range, lower, higher;
                range = this->getCelcius() * 0.05;
                higher = this->getCelcius() + range;
                lower = this->getCelcius() - range;
                
                if (value >= lower && value <= higher)
                {
                    return true;
                } else 
                {
                    return false;
                }
            }

            if (selection == Substance::FAHRENHEIT)
            {
                double range, lower, higher;
                range = this->getFahrenheit() * 0.05;
                higher = this->getFahrenheit() + range;
                lower = this->getFahrenheit() - range;
                
                if (value >= lower && value <= higher)
                {
                    return true;
                } else 
                {
                    return false;
                }
            }

            if (selection == Substance::KELVIN)
            {
                double range, lower, higher;
                range = this->getKelvin() * 0.05;
                higher = this->getKelvin() + range;
                lower = this->getKelvin() - range;
                
                if (value >= lower && value <= higher)
                {
                    return true;
                } else 
                {
                    return false;
                }
            }

            cout << "Invalid Selection..." << endl;
            return 0;
        }
};