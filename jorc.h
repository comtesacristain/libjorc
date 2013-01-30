#ifndef JORC_H
#define JORC_H

typedef struct _jorc {
	Measurement proven;
	Measurement probable;
	Measurement proven_probable;
	Measurement measured;
	Measurement indicated;
	Measurement measured_indicated;
	Measurement inferred;
	Measurement other;
	Measurement (*remnant_measured) (Measurement self);
	Measurement (*remnant_indicated) (Measurement self);
	Measurement (*remnant_measured_indicated) (Measurement self);
	char inclusive;
} Jorc;

#endif
