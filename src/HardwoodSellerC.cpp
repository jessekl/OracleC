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
	double total;
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
				double bf = atof(amount.c_str());
				double dTime;
				double price;

				if(woodtype.compare("Cherry")){
					//2.5 base delivery time 
					dTime = 2.5 * bf;
					price = 5.95;
				}
				if(woodtype.compare("Curly Maple")){
					//1.5 base delivery time 
					dTime = 1.5 * bf;
					price = 6.00;
				}
				
				if(woodtype.compare("Genuine Mahogany")){
					//1.5 base delivery time 
					dTime = 3 * bf;
					price = 6.00;
				}
				if(woodtype.compare("Wenge")){
					//5 base delivery time 
					dTime = 5 * bf;
					price = 22.35;
				}
				if(woodtype.compare("White Oak")){
					//2.3 base delivery time 
					dTime = 2.3 * bf;
					price = 6.70;
				}
				if(woodtype.compare("Sawdust")){
					//1 base delivery time 
					dTime = 1 * bf;
					price = 1.5;
				}
				total = total + dTime;
				outfile<<"woodtype: "<<woodtype<<"\tbf: "<<bf<<"\tprice: "<<price<<endl;
		}
	}
	else{
		cout<<"file not found"<<endl;
	}
	outfile<<" total purchase price: "<<total<<endl;
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


