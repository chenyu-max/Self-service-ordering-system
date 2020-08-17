#pragma once
#ifndef COUSTMANAGER
#define COUSTMANAGER
#include<bits/stdc++.h>
class CoustManager
{
private:
	double insideCoust, outsideCoust;
public:
	CoustManager();
	double getInsideCoust();
	double getOutsideCoust();
	void addInsideCoust(double x);
	void addOutsideCoust(double x);

};
#endif // !COUSTMANAGER