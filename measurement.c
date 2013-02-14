#include <stdlib.h>

#include "measurement.h"
// Routine to add to Measurements together. Must check units are of similar types.


Measurement newMeasurement(float q, char *u) {
	Measurement measurement;
	measurement = (Measurement) malloc(sizeof(_measurement));
 	measurement->add = &add;	
	measurement->subtract = &subtract;	
	measurement->multiply = &multiply;	
	measurement->divide = &divide;	
	measurement->quantity = q;
	measurement->units = newUnits(u);
	return measurement;
}

Measurement add (Measurement self, Measurement a) {
	Measurement product;
	float q, d;
	char *u;
	if ((d=UnitCompare(self, a)) != 0) {
		q = a->quantity + self->quantity *d;
		u = self->units;
	}
	else {
		q=0.0;
		u="%";
	}
	product = newMeasurement(q,u,1.0,u);
	return product;
}

Measurement subtract (Measurement self, Measurement a) {
	Measurement product;
	float q, d;
	char *u;
	if ((d=UnitCompare(self, a)) != 0) {
		q  = self->quantity - a->quantity * d;
		u = self->units;
	}
	else {
		q=0.0;
		u="%";
	}
	product = newMeasurement(q,u,1.0,u);
	return product;
}

/*
	Multiplication operator on Measurement. 
*/

Measurement multiply (Measurement self, Measurement a) {
	Measurement product;
	float q,d;
	char *u;
	if ((d=UnitCompare(self, a)) != 0) {
		q  = self->quantity * a->quantity;
		u = self->units;
	}
	else {
		q=0.0;
		u="%";
	}
	product = newMeasurement(q,u,1.0,u);
	return product;
}

/*
	Division operator on Measurement. Check divisor is not zero
*/

Measurement divide (Measurement self, Measurement a) {
	Measurement product;
	float q,d;
	char *u;
	if ((d=UnitCompare(self, a)) != 0) {
		if (a->quantity != 0) {
			q  = self->quantity / a->quantity;
			u = self->units;
		}
	}
	else {
		q=0.0;
		u="%";
	}
	product = newMeasurement(q,u,1.0,u);
	return product;
}
