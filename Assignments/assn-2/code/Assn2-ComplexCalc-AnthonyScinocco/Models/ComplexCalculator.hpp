using namespace std;

class ComplexCalculator
{
    private:
        double aReal;
        double bReal;
        string realOp;

        double aImaginary;
        double bImaginary;
        string imageOp;

        string placeI(string imageNum)
        {
            string op, num;

            if (imageNum.find("-") == 0)
            {
                op = "-";
                num = imageNum.substr(imageNum.find("-") + 1);
            } else
            {
                op = "+";
                num = imageNum.substr(imageNum.find("+") + 1);
            }

            string result = op + "i" + num;
            return result;
        }

        string placeJ()
        {
            return "j * ";
        }

        void display(string result)
        {
            cout << "Result is: " << endl;
            cout << result << endl;
        }

    public:
        ComplexCalculator(double ar, double ai, double br, double bi)
        {
            aReal = ar;
            aImaginary = ai;
            bReal = br;
            bImaginary = bi;
        }

        void add()
        {
            double left = aReal + bReal;
            double right = aImaginary + bImaginary;
            string c = to_string(left) + placeI(to_string(right));

            display(c);
        }

        void subtract()
        {

            double left = aReal - bReal;
            double right = aImaginary - bImaginary;
            string c = to_string(left) + placeI(to_string(right));

            display(c);
        }

        void multiply()
        {
            double left = (aReal * bReal) - (aImaginary * bImaginary);
            double right = (aReal * bReal) + (aImaginary * bImaginary);
            string c = to_string(left) + " + " + placeJ() + to_string(right);
            display(c);
        }

        void divide()
        {
            double topLeft = (aReal * bReal) + (aImaginary * bImaginary);
            double bottomLeft = (bImaginary * bImaginary) + (bReal * bReal);
            double leftSum = topLeft / bottomLeft;

            double topRight = (aReal * bReal) - (aImaginary * bImaginary);
            double bottomRight = (bImaginary * bImaginary) + (bReal * bReal);
            double rightSum = topRight / bottomRight;

            string c = to_string(leftSum) + " + " + placeJ() + to_string(rightSum);
            display(c);
        }
};