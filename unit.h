#ifndef UNIT_H
#define UNIT_H

typedef struct _unit * Unit;

struct _unit {
    char *units;
    float dimension;
    char *base_units;
} _unit;

Unit newUnit(char *u);

float UnitCompare(Unit self,Unit a);

#endif

