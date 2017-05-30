#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <string>
#include "./Utils/MyUtils.hpp"

using namespace std;

class BiNomialExpansion
{
    private:
        string expandedEqn; // eqn in fully expanded form
        string baseEqn; // base equation input
        
        string a; // value of a
        string b; // value of b
        string nString; // string representation of n
        double nDouble; // double representation of n

        string op; // oprator

        string buildNumerator(int i)
        {
            string numerator = nString + " ";

            for (int x = 1; x <= i; x++)
            {
                string xString = MyUtils::toString(x);
                numerator += "(" + nString + " - " + xString + ")";
            }

            return numerator;
        }

        string buildDenominator(int i)
        {
            i++;
            string denom = MyUtils::toString(i);
            denom += "!";
            return denom;
        }

        void init()
        {
            expandedEqn = ""; // eqn in fully expanded form
            baseEqn = ""; // base equation input
            a = ""; // value of a
            b = ""; // value of b
            nString = ""; // string representation of n
            nDouble = 0; // double representation of n
        }

    public:
        void parse(string eqn)
        {        
            init();
            // save copy of base eqn
            baseEqn = eqn;

            string symbols [2]  = { "+", "-" }; // operators
            string openParen    = "(";
            string closeParen   = ")";
            string caret        = "^";
            string comma        = ",";

            eqn = eqn + ","; // comma for easy delimitation

            for (int i = 0; i < sizeof(symbols)/sizeof(symbols[0]); i++)
            {
                if (eqn.find(symbols[i]))
                {
                    op = symbols[i];
                }
            }

            // find the positions of each special character in the 
            // equation and then extrapolate the values
            unsigned OPNum   = eqn.find(openParen);
            unsigned CPNum   = eqn.find(closeParen); 
            unsigned operNum = eqn.find(op);
            unsigned cNum    = eqn.find(caret);
            unsigned comNum  = eqn.find(comma);

            // a little guess work to get the desired character positions
            a = eqn.substr((OPNum + 1), (operNum - 1) - OPNum);
            b = eqn.substr((operNum + 1), (CPNum - 1 ) - operNum);
            nString = eqn.substr((cNum + 1), (comNum - 1) - cNum);
            nDouble = atof(nString.c_str());
        }

        void expand()
        {
            expandedEqn = a + "^" + nString + " + " + nString;
            expandedEqn += " * ";

            for (int i = 1; i < nDouble; i++)
            {
                string iString = MyUtils::toString(i);
                expandedEqn += a + "^(" + nString + " - " + iString + ") ";
                expandedEqn += op + " " + b + " + ";

                string numerator = buildNumerator(i);
                string denom = buildDenominator(i);

                expandedEqn += "[ " + numerator + " / " + denom + " ] ";
            }

            expandedEqn += b + "^" + nString;
        }

        void display()
        {
            cout << baseEqn + " = " << endl;
            cout <<  "\t" << expandedEqn << endl;
        }

       
};