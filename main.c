#include "measurement.h"
#include "jorc.h"
#include <stdio.h>

int main() {
	Measurement q,x,mult,div;
	Measurement m,a;
	m = newMeasurement(1.0 ,"g/t", 10,"%");
	a = newMeasurement(1.0 ,"g/t", 10,"%");

	q=m->add(m,a);
	x=m->subtract(a->add(q,a),m);
	
	mult=x->multiply(x,q);
	div=a->divide(a,mult);
	
	//x=m.subtract(m,m);
	printf("Quantity m= %5.2f %s\n",m->quantity,m->units);
	printf("Quantity a= %5.2f %s \n",a->quantity,a->units);
	printf("Quantity q= %5.2f %s \n",q->quantity,q->units);
	printf("Quantity x= %5.2f %s \n",x->quantity,x->units);
	printf("Quantity mult= %5.2f %s \n",mult->quantity,mult->units);
	printf("Quantity div= %5.2f %s \n",div->quantity,div->units);
	//printf("Quantity 3= %5.2f \n",x.quantity);
	return 0;
}
