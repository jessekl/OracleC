/*
 * WoodItem.h
 *
 *  Created on: Aug 24, 2015
 *      Author: Esteban
 */


#include <string.h>
#include <iostream>
#include <fstream>
#include <sstream>

#ifndef WOODITEM_H_
#define WOODITEM_H_
using namespace std;
class WoodItem {

public:

	string type;
	double baseDeliveryTime;
	double price;
	double deliveryTime;

	// Member functions declaration
	WoodItem();
	WoodItem(string woodType, double deliveryTime, double itemPrice);
	double getDeliveryTime();
};

#endif 
/* WOODITEM_H_ */
