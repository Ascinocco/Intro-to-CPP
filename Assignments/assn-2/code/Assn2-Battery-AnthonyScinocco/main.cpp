#include "./loader.hpp"

using namespace std;

int main()
{
    Battery myBattery(1000, 1000);
    
    // power 4 amp light for 15 min
    myBattery.powerDevice(4, 900); // 900s in 15 min
    cout << "I just powered a lamp for 15min" << endl;

    // how long can I run my 8 amp device
    double mt = myBattery.maxTime(8);
    cout << "I can power an 8 amp device for " + to_string(mt) + " seconds with my remaining energy" << endl;

    myBattery.recharge();
    cout << "I just recharged!" << endl;

    mt = myBattery.maxTime(8);
    cout << "I can power an 8 amp device for " + to_string(mt) + " seconds with a full charge" << endl;

    return 0;
}