#include "CoustManager.h"

CoustManager::CoustManager() {
	insideCoust = 0;
	outsideCoust = 0;
}

double CoustManager::getInsideCoust() {
	return insideCoust;
}

double CoustManager::getOutsideCoust() {
	return outsideCoust;
}

void CoustManager::addInsideCoust(double x) {
	insideCoust += x;
}

void CoustManager::addOutsideCoust(double x) {
	outsideCoust += x;
}