#define _CRT_SECURE_NO_WARINGS
/////////////////////////////////////////////////////////////////
// Final Project Milestone 6
// Version 1.0
// Date	2017-08-06
// Author	Daniel Casella
// File		AidApp.h
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//safeguards
#ifndef SICT_AIDAPP_H_
#define SICT_AIDAPP_H_

//system defined files
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
//user defined files
#include "Product.h"

//declare namespace
namespace sict

{
	//declare class
	class AidApp

	{
		//holds name of text
		char filename_[256];
		//array of products
		Product* product_[MAX_NO_RECS];
		//used to create and access a file
		fstream datafile_;
		//number of product pointed to array
		int noOfProducts_;
		//pauses and waits for user to press <ENTER>
		void pause() const;
		//displays menu
		int menu();
		//opens data for reading
		void loadRecs();
		//opens data for writing
		void saveRecs();
		//lists products in specific format
		void listProducts()const;
		//searches for products based off SKU entered
		int SearchProducts(const char* sku)const;
		//updates the quantity on hand
		void addQty(const char* sku);
		//add product to end of array
		void addProduct(bool isPerishable);
		
		//public data members
	public:

		//constructor
		AidApp(const char* );
		//display menu and receives user selection
		int run();
	};

}

#endif