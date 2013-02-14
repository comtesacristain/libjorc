#ifndef MEASUREMENT_H
#define MEASUREMENT_H


//#define MEASUREMENT 	float quantity; \
//			char *units; \
//			float dimension; \
//			char *base_units; \
			

typedef struct _measurement *Measurement;
  struct _measurement {
     //MEASUREMENT;
	float quantity;
    Unit units;
	Measurement (*add)(Measurement a, Measurement b);
	Measurement (*subtract)(Measurement a, Measurement b);
	Measurement (*multiply)(Measurement a, Measurement b);
	Measurement (*divide)(Measurement a, Measurement b);
  } _measurement;
 
  void destroy(Measurement this);
  Measurement newMeasurement(float q, char *u, float d, char *b);
  Measurement add(Measurement a, Measurement b);
  Measurement subtract(Measurement a, Measurement b);
  Measurement multiply(Measurement a, Measurement b);
  Measurement divide(Measurement a, Measurement b);
//typedef Measurement * MeasurementPtr;



//Measurement add (Measurement meas_a, Measurement meas_b);
//Measurement subtract (Measurement meas_a, Measurement meas_b);
//Measurement multiply (Measurement meas_a, Measurement meas_b);
//Measurement divide (Measurement meas_a, Measurement meas_b);
#endif 
