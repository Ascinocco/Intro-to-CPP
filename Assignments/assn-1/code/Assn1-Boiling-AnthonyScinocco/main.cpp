#include <iostream>

using namespace std;

class Substance
{
    // 0 is celcius
    static const int CELCIUS = 0;
    static const int FAHRENHEIT = 1;
    static const int KELVIN = 2;

    public:
      float celcius,
            fahrenheit,
            kelvin;

      Substance()
      {
        cout << "Substance Constructor Called." << endl;
      };

      float getCelcius()
      {
        return this->celcius;
      };

      float getFahrenheit()
      {
        return this->fahrenheit;
      };

      float getKelvin()
      {
        return this->kelvin;
      };

      bool isInRange(int selection, float value)
      {
        float higher,
              lower,
              range;
        
        if(selection == Substance::CELCIUS)
        {
            range = this->celcius * 0.05;
            lower = this->celcius - range;
            higher = this->celcius + range;

            if (value > lower && value < higher)
            {
                return true;
            } else
            {
                return false;
            }

        } else if (selection == Substance::FAHRENHEIT)
        {
            range = this->fahrenheit * 0.05;
            lower = this->fahrenheit - range;
            higher = this->fahrenheit + range;

            if (value > lower && value < higher)
            {
                return true;
            } else
            {
                return false;
            }
        } else if (selection == Substance::KELVIN)
        {
            range = this->kelvin * 0.05;
            lower = this->kelvin - range;
            higher = this->kelvin + range;

            if (value > lower && value < higher)
            {
                return true;
            } else
            {
                return false;
            }
        } else
        {
            cout << "Substance unknown..." << endl;
            return false;
        }
      };
};

class Water :public Substance
{
    public:
        Water()
        {
          this->celcius = 100;
          this->fahrenheit = 212;
          this->kelvin = 373.15;
        };
};

class Mercury :public Substance
{
    public:
        Mercury()
        {
          this->celcius = 357;
          this->fahrenheit = 674.6;
          this->kelvin = 630.15;
        };
};

class Copper :public Substance
{
    public:
        Copper()
        {
          this->celcius = 1187;
          this->fahrenheit = 2168.6;
          this->kelvin = 1460.15;
        };
};

class Silver :public Substance
{
    public:
        Silver()
        {
          this->celcius = 2193;
          this->fahrenheit = 3979.4;
          this->kelvin = 2466.15;
        };
};

class Gold :public Substance
{
    public:
        Gold()
        {
          this->celcius = 2660;
          this->fahrenheit = 4820;
          this->kelvin = 2933.15;
        };
};

class Selector
{
    // 0 is celcius
    static const int CELCIUS = 0;
    // 1 is fahrenheit
    static const int FAHRENHEIT = 1;
    // 2 is kelvin
    static const int KELVIN = 2;

    public:
      int selection;
      int boilingPoint;
      Selector(int sel)
      {
        if(sel == Selector::CELCIUS || sel == Selector::FAHRENHEIT || sel == Selector::KELVIN)
        {
            this->selection = sel;
            this->boilingPoint = 0;
        } else 
        {
            cout << "Invalid choice, defaulting to celcius...\n" << endl;
            cout << "Restart program if a different measurement is required...\n" << endl;
        }
      };

      float getSelection()
      {
          return this->selection;
      }

      float getBoildingPoint()
      {
          return this->boilingPoint;
      }

      void setBoilingPoint(float point)
      {
        this->boilingPoint = point;
      }
};

int main()
{
    // vars
    int choice;
    int boilingPoint;

    cout << "Celcius (0) \nFahrenheit (1) \nKelvin (2) \nSelect your unit of measure: " << endl;
    cin >> choice;
    
    Selector mySelector(choice);
    
    cout >> "Enter boiling point: " << endl;
    cin >> boilingPoint;

    Water myWater;
    Copper myCopper;
    Silver mySilver;
    Gold myGold;

    return 0;
}