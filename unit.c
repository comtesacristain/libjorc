Unit newUnit(char * u) {
	Unit unit;
	unit->units = u;
	return unit;
}

float UnitCompare(Unit self, Unit a) {
	if (!strcmp(self->units,a->units)) {
		return 1;
	}
	else if (self->base_units,a->base_units) {
		return self->dimension / a->dimension;
	}
	return 0;
}
