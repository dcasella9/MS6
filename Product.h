// Final Project Milestone 4
// Version 1.0
// Date	2017-07-17
// Author	Daniel Casella
//////////////////////////////////////////

// Product.h

//safeguards
#ifndef SICT_PRODUCT_H_
#define SICT_PRODUCT_H_

//system files
#include <iostream>

//user defined files
#include "general.h"
#include "Streamable.h"

//declare namespace sict
namespace sict {

	//declare derived class
	class Product : public Streamable {
		char sku_[MAX_SKU_LEN + 1];
		char* name_;
		double price_;
		bool taxed_;
		int quantity_;
		int qtyNeeded_;
	
		//public member functions
	public:

		//constructors
		Product();
		Product(const char* sku, const char* name, double price = 0, bool taxed = true, int quantity = 0, int qtyNeeded = 0);
		Product(const Product&);

		//copy constructor
		Product& operator=(const Product&);
		
		//destructor
		~Product();

		//Accessors
		//
		//setters
		void sku(const char*);
		void price(double);
		void name(const char*);
		void taxed(bool);
		void quantity(int);
		void qtyNeeded(int);

		//getters(queries)
		const char* sku() const;
		double price() const;
		const char* name() const;
		bool taxed() const;
		int quantity() const;
		int qtyNeeded() const;
		double cost() const;
		bool isEmpty() const;

		//member operator overloads
		bool operator==(const char*);
		int operator+=(int);
		int operator-=(int);

	};//end derived class

	//non-member operator overload
	double operator+=(double&, const Product&);
	
	//non-member IO operator overloads
	std::istream& operator>>(std::istream& istr, Product& p);
	std::ostream& operator<<(std::ostream& ostr, const Product&);

}//end namespace

#endif //end safeguard