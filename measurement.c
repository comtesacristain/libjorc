#include <stdlib.h>

#include "measurement.h"
// Routine to add to Measurements together. Must check units are of similar types.


Measurement newMeasurement(float q, char *u, float d, char *b) {
	Measurement measurement;
	measurement = (Measurement) malloc(sizeof(_measurement));
 	measurement->add = &add;	
	measurement->subtract = &subtract;	
	measurement->multiply = &multiply;	
	measurement->divide = &divide;	
	measurement->quantity = q;
	measurement->units = u;
	measurement->dimension=d;
	measurement->base_units=b;
	return measurement;
}

Measurement add (Measurement self, Measurement a) {
	Measurement product;
	float q;
	char *u;
	if (!strcmp(a->base_units,self->base_units)) {
		q = a->quantity + self->quantity;
		u = a->base_units;
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
	float q;
	char *u;
	if (!strcmp(a->base_units,self->base_units)) {
		q  = self->quantity - a->quantity;
		u = a->base_units;
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
	float q;
	char *u;
	if (!strcmp(a->base_units,self->base_units)) {
		q  = self->quantity * a->quantity;
		u = a->base_units;
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
	float q;
	char *u;
	if (!strcmp(a->base_units,self->base_units)) {
		if (a->quantity != 0) {
			q  = self->quantity / a->quantity;
			u = a->base_units;
		}
	}
	else {
		q=0.0;
		u="%";
	}
	product = newMeasurement(q,u,1.0,u);
	return product;
}
