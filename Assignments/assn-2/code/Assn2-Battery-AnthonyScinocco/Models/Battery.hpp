using namespace std;

class Battery
{
    private:
        double voltage; // V 
        double joules; // J
        double maxPower; // power in whats
        double currentPower; // power in watts
    public:
        Battery(double max, double curr)
        {
            maxPower = max;
            currentPower = curr;
            voltage = 12;
            joules = 5000000;
        }
        
        bool powerDevice(double deviceAmps, double timeToBePoweredInSeconds)
        {
            // power required for device
            double devicePowerReqd = deviceAmps * voltage;
            double deviceJoulesReqd = devicePowerReqd * timeToBePoweredInSeconds;

            if ((joules - deviceJoulesReqd) >= 0)
            {
                // update energy supply
                joules = joules - deviceJoulesReqd;
                return 1;
            } else {
                return 0;
            }
        }

        // not sure what you meant, the wording was kind of confusing
        void recharge()
        {
            currentPower = maxPower;
            joules = 5000000;
        }

        double maxTime(double deviceAmps)
        {
            double P = deviceAmps * voltage;
            double t = joules / P;
            return t;
        }
};