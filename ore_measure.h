#ifndef ORE_MEASURE_H
#define ORE_MEASURE_H

#include "measurement.h"

typedef struct _ore_measure *OreMeasure;
struct _ore_measure {
	Measurement ore;
	Measurement mineral;
	Measurement grade;
} _ore_measure;

OreMeasure newOreMeasure();

#endif

