using namespace std;

class BiNomial
{    
    public:
        int numExponents(int x)
        {
            return x;
        }

        void display(int n)
        {
            int i, j, x, y, maxlen;
            string len;
            for(i = 0; i < n; i++) {
                x = 1;
                len = string((n-i-1)*(n/2), ' ');
                cout << len;
                for(j = 0; j <= i; j++) {
                    y = x;
                    x = x * (i - j) / (j + 1);
                    maxlen = numExponents(x) - 1;
                    if(n % 2 == 0)
                        cout << y << string(n - 1 - maxlen, ' ');
                    else {
                        cout << y << string(n - 2 - maxlen, ' ');
                    }
                }
                cout << endl;
            }
        }
};