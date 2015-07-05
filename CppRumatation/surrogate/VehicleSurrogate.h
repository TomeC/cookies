#ifndef _VEHICLE_SURROGATE_H_
#define _VEHICLE_SURROGATE_H_

#include "vehicle.h"
class VehicleSurrogate
{
public:
	VehicleSurrogate():m_vp(0) {}
	VehicleSurrogate(const Vehicle &v):m_vp(v.copy()) {};
	VehicleSurrogate(const VehicleSurrogate &v):m_vp(v.m_vp? v.m_vp->copy():0) {};
	VehicleSurrogate &operator=(const VehicleSurrogate &v);
	~VehicleSurrogate();
	//vehicle action
	double weight() const;
	void start();
private:
	Vehicle *m_vp;
};

#endif