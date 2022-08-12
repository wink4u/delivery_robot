#include <iostream>

#define WHEEL_RADIUS 0.17
#define PI 3.141592
#define betweenwheel 0.52

using namespace std;

typedef struct
{
    double l_wheel_vel;
    double r_wheel_vel;
}wheelvel;

class ENCODER
{
    public:
            ENCODER();
            void UpdateEncoder(int l_pulse, int r_pulse, double Tc, double PPR);
            void ThicktoRPM();
            void TimetoRPM();
            void RPMtoVelocity();
            wheelvel SubVelocity();
            wheelvel SubTmethod();
    private:
            double _Tc;
            double _PPR;
            int _lpulse, _rpulse;
            double lheel_tk_to_rpm, rheel_tk_to_rpm;
            double lheel_rpm_to_vel, rheel_rpm_to_vel;
            double lheel_time_to_rpm, rheel_time_to_rpm;  
    
            
};
