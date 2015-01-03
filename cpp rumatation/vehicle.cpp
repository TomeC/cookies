#include "vehicle.h"
#include <iostream>
double AutoVehicle::weight()
{
	return 100.0;
}

void AutoVehicle::start()
{
	std::cout<<"AutoVehicle start"<<std::endl;
}
Vehicle* AutoVehicle::copy() const
{
	return new AutoVehicle(*this);
}
double Aircraft::weight()
{
	return 200.0;
}

void Aircraft::start()
{
	std::cout<<"Aircraft start"<<std::endl;
}

Vehicle* Aircraft::copy() const
{
	return new Aircraft(*this);
}