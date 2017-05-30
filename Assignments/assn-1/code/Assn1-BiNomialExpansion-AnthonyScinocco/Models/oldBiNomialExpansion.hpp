#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// this code got really out of hand but I do not have the time to
// make it better
class oldBiNomialExpansion
{
    private:
        string expandedEqn;
        string baseEqn;
        string biNomialFactorOne;
        string biNomialFactorTwo;
        string eqnExponent;
        string eqnOperator;
    
    public:
        bool parseEqn(string eqn)
        {
            eqn = eqn + ","; // added comma to the end of the equation for ease of find the end
            string symbols [4] = { "+", "-", "*", "/" };
            int symbolsLength = sizeof(symbols)/sizeof(symbols[0]);
            char openParenthesis = '(';
            char closeParenthesis = ')';
            char exponent = '^';
            char comma = ',';
            string eqnOperator;

            string eqnExponent;
            string biNomialFactorOne;
            string biNomialFactorTwo;

            // find operator between binomial expressions
            for (int i = 0; i < symbolsLength; i++)
            {
                if (eqn.find(symbols[i]))
                {
                    eqnOperator = " " + symbols[i] + " ";
                }
            }
            
            this->setEqnOperator(eqnOperator);

            // find expression between open parenthesis and operator
            unsigned openParenNum = eqn.find(openParenthesis);
            unsigned eqnOperatorNum = eqn.find(eqnOperator);

            biNomialFactorOne = eqn.substr(openParenNum, eqnOperatorNum - openParenNum);

            unsigned closeParenNum = eqn.find(closeParenthesis);

            biNomialFactorTwo = eqn.substr(eqnOperatorNum, closeParenthesis - eqnOperatorNum);

            unsigned eqnExponentNum = eqn.find(exponent);
            unsigned endEqnCommaNum = eqn.find(comma);

            eqnExponent = eqn.substr(eqnExponentNum, endEqnCommaNum - eqnExponentNum);

            this->setBiNomialFactorOne(biNomialFactorOne);
            this->setBiNomialFactorTwo(biNomialFactorTwo);
            this->setEqnExponent(eqnExponent);
            this->setEqnOperator(eqnOperator);

            string builtEqn = this->buildBaseEqn();
            this->setBaseEqn(builtEqn);

            return true;
        }

        void expand()
        {
            string a = "3x";
            string b = "-4y";
            double n = 5;
            string nString = this->doubleToString(n);

            string eqn = "(" + a + b + ")^" + nString;
            eqn = eqn + "=" + a + "+" + nString + "*";


            for (int i = 1; i <= n; i++)
            {
                int iPlusOne = i + 1;
                string iPlusOneString = this->intToString(iPlusOne);
                string iString = this->intToString(i);
                string numerator = this->generateNumerators(i);

                eqn = eqn + a + "^" + nString + "-" + iString;
                eqn = eqn + b + "+" + numerator + "/" + iPlusOneString + "!";
            }

            eqn = eqn + "+" + b + "^" + nString;
            
            cout << eqn << endl;

        }

        string generateNumerators(double n)// n here is not representative of n in the equation
        {
            string nString = this->doubleToString(n);
            string numerator = nString;

            for (int i = 1; i < n; i++)
            {
                string iString = this->intToString(i);
                numerator = numerator + "(" + nString + "-" + iString + ")";
            }

            return numerator;
        }

        void display()
        {

        }

        string doubleToString(double dbl)
        {
            ostringstream strs;
            strs << dbl;
            string str = strs.str();
            return str;
        }

        string intToString(int num)
        {
            ostringstream strs;
            strs << num;
            string str = strs.str();
            return str;
        }

        string getExpandedEqn()
        {
            return expandedEqn;
        }

        string buildBaseEqn()
        {
            string openBrace = "( ";
            string biFacOne = this->getBiNomialFactorOne();
            string eqnOp = this->getEqnOperator();
            string biFacTwo = this->getBiNomialFactorTwo();
            string closeAndCaret = " )^";
            string expo = this->getEqnExp();

            string eqn = openBrace + biFacOne + eqnOp +
                         biFacTwo + closeAndCaret + expo;

            return eqn;
        }

        void setBaseEqn(string eqn)
        {
            baseEqn = eqn;
        }

        void setEqnOperator(string myOperator)
        {
            eqnOperator = myOperator;
        }

        void setBiNomialFactorOne(string factor)
        {
            biNomialFactorOne = factor;
        }

        void setBiNomialFactorTwo(string factor)
        {
            biNomialFactorTwo = factor;
        }

        void setEqnExponent(string myExp)
        {
            eqnExponent = myExp;
        }

        void setExpandedEquation(string expEqn)
        {
            expandedEqn = expEqn;
        }

        string getBiNomialFactorOne()
        {
            return biNomialFactorOne;
        }

        string getBiNomialFactorTwo()
        {
            return biNomialFactorTwo;
        }

        string getEqnExp()
        {
            return eqnExponent;
        }

        string getEqnOperator()
        {
            return eqnOperator;
        }
};