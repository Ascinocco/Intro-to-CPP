#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class BiNomialExpansion
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
            eqn = eqn + ','; // added comma to the end of the equation for ease of find the end
            char symbols [4] = { '+', '-', '*', '/' };
            int symbolsLength = sizeof(symbols)/sizeof(symbols[0]);
            char openParenthesis = '(';
            char closeParenthesis = ')';
            char exponent = '^';
            char comma = ',';
            char eqnOperator;

            string eqnExponent;
            string biNomialFactorOne;
            string biNomialFactorTwo;

            // find operator between binomial expressions
            for (int i = 0; i < symbolsLength; i++)
            {
                if (eqn.find(symbols[i]))
                {
                    eqnOperator = symbols[i];
                }
            }

            // convert char to string
            string eqnOperatorString = this->charToString(eqnOperator);
            this->setEqnOperator(eqnOperatorString);

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


            return true;
            

        }

        string charToString(char tempChar)
        {
            stringstream ss;
            string temp;
            ss << tempChar;
            ss >> temp;
            return temp;
        }

        string getExpandedEquation()
        {
            return expandedEqn;
        }

        string buildBaseEqn()
        {
            string eqn = '(' + this->getBiNomialFactorOne() +
                         + this->getEqnOperator() +
                         + this->getBiNomialFactorTwo() +
                         + ')' +
                         + '^' +
                         + this->getEqnExp();
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