//============================================================================
// Name        : HardwoodSellerC.cpp
// Author      : Esteban Parra
// Version     : 1
// Copyright   : It's free
// Description : Main class for the Hardwood Seller
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <cstring>
#include "WoodItem.h"

using namespace std;

/*
Cherry $5.95
Curly Maple $6.00
Genuine Mahogany $9.60
Wenge $22.35
White Oak $6.70
Sawdust $1.5
*/
/*
Cherry 2.5
Curly Maple 1.5
Genuine Mahogany 3
Wenge 5
White Oak 2.3
Sawdust 1
*/
/*
[1, 100] = 1 ∗ base delivery time 
[101, 200] = 2 ∗ base delivery time 
[201, 300] = 3 ∗ base delivery time 
[301, 400] = 4 ∗ base delivery time 
[401, 500] = 5 ∗ base delivery time 
[501, 1000] = 5.5 ∗ base delivery time
*/

/*
output
full name of the buyer, address of delivery, list of the ordered wood, including BF purchased and its price, 
 the estimated delivery time and total price of the purchase.
*/
void readInputFile(string);

int main(int argc, char* argv[]) {
	WoodItem myitem;
	readInputFile("purchase.txt");
	return 0;
}

/*
 * Method to read the input file
 */
void readInputFile(string inputFilePath) {
	fstream infile,outfile;
	bool firstsec = true;
	infile.open(inputFilePath.c_str(),fstream::in);
	outfile.open("outfile.txt",fstream::out);

	if (infile.is_open()){
		while(!infile.eof()){
			if(firstsec){
				string buyer,address,date;
				//buyer
				getline(infile,buyer,';');
				cout<<buyer<<endl;
				//address
				getline(infile,address,';');
				cout<<address<<endl;
				//date
				getline(infile,date,'\n');
				cout<<date<<endl;
				firstsec=false;
				//print the user data to the output file
				outfile<<buyer<<endl;
				outfile<<address<<endl;

			}
				
				//process each order and print out corrasponding info
				string woodtype,amount;
				getline(infile,woodtype,':');
				cout<<woodtype<<endl;
				getline(infile,amount,';');
				cout<<amount<<endl;

		}
	}
	else{
		cout<<"file not found"<<endl;
	}
	infile.close();
/*
<Buyer full name>;<Address>;<Date> 
<WoodType>:<Amount>;<WoodType>:<Amount>; . . . ;<WoodType>:<Amount>
*/
}

/*
 * Method to compute the deliveryTime
 */
double deliveryTime() {
	double deliveryETA = 0.0;
	return deliveryETA;
}
