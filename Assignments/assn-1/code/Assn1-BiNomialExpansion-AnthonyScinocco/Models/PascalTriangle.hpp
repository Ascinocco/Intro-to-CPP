#include <iostream>

using namespace std;

class PascalTriangle
{
    private:
        int numOfRows;
    
    public:
        int getNumOfRows()
        {
            return numOfRows;
        }

        bool setNumOfRows(int rows)
        {
            if (rows >= 1 && rows <= 10)
            {
                numOfRows = rows;
                return true;
            } else 
            {
                cout << "----------------------------------------------" << endl;                
                cout << "The number of rows must be between 0 and 10" << endl;
                cout << "----------------------------------------------" << endl;
                return false;
            }
        }

        bool display()
        {
            int rows = this->getNumOfRows();

            cout << "-------------------------" << endl;

            for (int i = 0; i < rows; i++)
            {
                int val = 1;
                
                for (int j = 1; j < (rows - i); j++)
                {
                    cout << "   ";
                }

                for (int k = 0; k <= i; k++)
                {
                    cout << "      " << val;
                    val = val * (i - k) / (k + 1);
                }

                cout << endl << endl;
            }
            
            cout << "-------------------------" << endl;
            return true;
        }
};