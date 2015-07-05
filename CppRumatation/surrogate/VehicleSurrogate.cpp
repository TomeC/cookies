#include "VehicleSurrogate.h"

VehicleSurrogate& VehicleSurrogate::operator=(const VehicleSurrogate &v)
{
	if (this != &v)
	{
		delete m_vp;
		m_vp = (v.m_vp? v.m_vp->copy(): 0);
	}
	return *this;
}
VehicleSurrogate::~VehicleSurrogate()
{
	delete m_vp;
}

double VehicleSurrogate::weight() const
{
	return m_vp->weight();
}
void VehicleSurrogate::start() 
{
	return m_vp->start();
}