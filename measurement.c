#include <stdlib.h>

#include "measurement.h"
// Routine to add to Measurements together. Must check units are of similar types.


Measurement newMeasurement(float q, char *u, float d, char *b) {
	Measurement measurement;
	measurement = (Measurement) malloc(sizeof(_measurement));
 	measurement->add = add;	
	measurement->quantity = q;
	measurement->units = u;
	measurement->dimension=d;
	measurement->base_units=b;
	return measurement;
}

Measurement add (Measurement this, Measurement a) {
	Measurement x;
	float q;
	char *u;
	if (!strcmp(a->base_units,this->base_units)) {
		q = a->quantity + this->quantity;
		u = a->base_units;
	}
	else {
	q=0.0;
	u="%";
	}
	x = newMeasurement(q,u,1.0,u);
	return x;
}
/*
// Measurement subtract (Measurement meas_a, Measurement meas_b) {
	// Measurement x;
	
	// x.quantity = meas_a.quantity - meas_b.quantity;
	// return x;
// }

static Measurement subtract(Measurement *self, Measurement b) {
	Measurement result;
	result.quantity  = self->quantity - b.quantity;
	return result;
}

Measurement  multiply (Measurement meas_a, Measurement meas_b) {
	Measurement x;
	
	x.quantity = meas_a.quantity * meas_b.quantity;
	return x;
}
Measurement  divide (Measurement meas_a, Measurement meas_b) {
	Measurement x;
	
	x.quantity = meas_a.quantity / meas_b.quantity;
	return x;
}*/
