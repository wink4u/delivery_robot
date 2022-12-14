#include <iostream>
#include "delivery_encoder.h"

ENCODER::ENCODER()
{
    _lpulse = 0;
    _rpulse = 0;
    _Tc = 0;
    _PPR = 0;
    lheel_rpm_to_vel = 0;
    rheel_rpm_to_vel = 0;
    lheel_tk_to_rpm = 0;
    rheel_tk_to_rpm = 0;
    lheel_time_to_rpm = 0;
    rheel_time_to_rpm = 0;
}

void ENCODER::UpdateEncoder(int l_pulse, int r_pulse, double Tc, double PPR)
{
    _lpulse = l_pulse;
    _rpulse = r_pulse;
    _Tc = Tc;
    _PPR = PPR;

}

void ENCODER::ThicktoRPM()
{

    lheel_tk_to_rpm = ( 60 *  _lpulse) / ( _Tc * _PPR );
    rheel_tk_to_rpm = ( 60 *  _rpulse) / ( _Tc * _PPR );   
}

void ENCODER::TimetoRPM()
{
    lheel_time_to_rpm = 60 / ( _PPR * _lpulse * 0.0001);
    rheel_time_to_rpm = 60 / ( _PPR * _rpulse * 0.0001);   
}


void ENCODER::RPMtoVelocity()
{  
    
    lheel_rpm_to_vel = WHEEL_RADIUS*((2*PI)/60)*(lheel_tk_to_rpm);
    rheel_rpm_to_vel = WHEEL_RADIUS*((2*PI)/60)*(rheel_tk_to_rpm);

}

wheelvel ENCODER::SubVelocity()
{
    wheelvel dv;
    ThicktoRPM();
    RPMtoVelocity();
    
    dv.l_wheel_vel = lheel_rpm_to_vel;
    dv.r_wheel_vel = rheel_rpm_to_vel;

    return dv;
}
