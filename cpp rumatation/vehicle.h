#ifndef _VEHICLE_H_
#define _VEHICLE_H_

class Vehicle
{
public:
	virtual double weight() = 0;
	virtual void start() = 0;
	virtual Vehicle* copy() const = 0;
};

class AutoVehicle:public Vehicle
{
public:
	double weight();
	void start();
	Vehicle* copy() const;
};

class Aircraft:public Vehicle
{
public:
	double weight();
	void start();
	Vehicle* copy() const;
};

#endif