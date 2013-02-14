#ifndef JORC_H
#define JORC_H

#include "ore_measure.h"

typedef struct _jorc {
	OreMeasure proven;
	OreMeasure probable;
	OreMeasure proven_probable;
	OreMeasure measured;
	OreMeasure indicated;
	OreMeasure measured_indicated;
	OreMeasure inferred;
	OreMeasure other;
	OreMeasure (*remnant_measured) (OreMeasure self);
	OreMeasure (*remnant_indicated) (OreMeasure self);
	OreMeasure (*remnant_measured_indicated) (OreMeasure self);
	char inclusive;
} Jorc;

#endif
