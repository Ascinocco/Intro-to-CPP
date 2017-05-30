/**
 * I became super tired of string conversions
   and I could not find an easy way to convert strings on the
   fly so here's my set of overloaded toString functionals
 */

 // I might move this to separate wrapper classes for primitive
 // types to allow myself more flexibility
using namespace std;

class MyUtils
{
    public:
        static string toString(int val)
        {
            ostringstream strs;
            strs << val;
            string str = strs.str();
            return str;
        }

        static string toString(double val)
        {
            ostringstream strs;
            strs << val;
            string str = strs.str();
            return str;
        }

        static string floatToString(float val)
        {
            ostringstream strs;
            strs << val;
            string str = strs.str();
            return str;
        }

        static string charToString(char val)
        {
            ostringstream strs;
            strs << val;
            string str = strs.str();
            return str;
        }
};