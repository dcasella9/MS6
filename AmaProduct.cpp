#define _CRT_SECURE_NO_WARNINGS
/////////////////////////////////////////////////////////////////
// Final Project Milestone 5
// Version 1.0
// Date	2017-07-27
// Author	Daniel Casella
// File		AmaProduct.cpp
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//system files
#include <cstring>
#include <iomanip>

//user defined file
#include "AmaProduct.h"

//declare namespace
using namespace std;

namespace sict {
	
	//constructor:recieves 'N' as default
	AmaProduct::AmaProduct(char tag)
	{
		fileTag_ = tag;
	}

	//returns constan pointer to unit
	const char* AmaProduct::unit() const 
	{
		return unit_;
	}

	//Copies the incoming value string into the unit_ string
	void AmaProduct::unit(const char * value)
	{
		strcpy(unit_, value);
	}

	//virtual member functions
	//
	//writes all the member variables of Product separated by comma
	fstream& AmaProduct::store(fstream& file, bool addNewLine) const
	{
		file << fileTag_ << "," << sku() << "," << name() << "," << price() << "," << taxed()<< "," << quantity() << "," << unit_ << "," << qtyNeeded();
		if (addNewLine)
			file << endl;

		return file;
	}

	//reads current record in file and 
	//sets the member variables using the setter methods
	fstream& AmaProduct::load(fstream& file)
	{
		char sku_[MAX_SKU_LEN], name_[500];
		int taxed_, quantity_, qtyNeeded_;
		double price_;

		file.getline(sku_, MAX_SKU_LEN, ',');
		file.getline(name_, 500, ',');
		file >> price_;
		file.ignore(500, ',');
		file >> taxed_;
		file.ignore(500, ',');
		file >> quantity_;
		file.ignore(500, ',');
		file.getline(unit_, 1000, ',');
		file >> qtyNeeded_;
		file.ignore(500, ',');

		sku(sku_);
		name(name_);
		price(price_);
		if (taxed_ == 1)
		taxed(true);
		else
			taxed(false);
		quantity(quantity_);
		qtyNeeded(qtyNeeded_);

		return file;
	}

	//prints err_ if member variable is not clear
	//if it is clear, it prints the Product in different formats
	ostream& AmaProduct::write(ostream& ostr, bool linear) const
	{
		if (!err_.isClear())
			ostr << err_.message();

		else 
		{
			//separated by Bar "|"
			if (linear)
			{
				ostr<<setfill(' ')<<left<<setw(MAX_SKU_LEN)<<sku()<<'|'
				<< left << setw(20) << name() << '|'
				<< right << fixed << setw(7) << setprecision(2) << cost() << '|'
				<< right << setw(4) << quantity() << '|'
				<< left << setw(10) << unit_ << '|'
				<< right << setw(4) << qtyNeeded() << '|';
			}
			else //prints member variable per line
			{
				ostr << "Sku: " << sku() << endl
				<< "Name: " << name() << endl
				<< "Price: " << price() << endl
				<< "Price after tax: ";
				taxed() ? ostr << cost() : ostr << "N/A";
				ostr << endl
				<< "Quantity On Hand: " << quantity() << " " << unit_ << endl
				<< "Quantity Needed: " << qtyNeeded();
			}
		}
		return ostr;
	}

	//receives values using istream
	istream & AmaProduct::read(istream & istr) 
	{
		
		//member variables
		char rSku[MAX_SKU_LEN], rName[500], rTaxed;
		int rQuantity, rQtyNeeded;
		double rPrice;

		//ask for sku
		cout << "Sku: ";
		istr >> rSku;
		istr.ignore(500, '\n');

		//ask for product name
		cout << "Name: ";
		istr >> rName;
		istr.ignore(500, '\n');

		//ask for unit of measurment
		cout << "Unit: ";
		istr >> unit_;
		istr.ignore(500, '\n');

		//ask if item is taxed
		cout << "Taxed? (y/n): ";
		istr >> rTaxed;

		//user enters correct character ELSE goes to error
		if (rTaxed == 'Y' || rTaxed == 'y' || rTaxed == 'n' || rTaxed == 'N')
		{
			
			//if no errors then
			//ask for price
			err_.clear();

			
			//ask for price
			cout << "Price: ";
			istr >> rPrice;
			istr.ignore(500, '\n');

			//error checking
			//if no error, ask for quantity on hand
			if (!istr.fail() && !istr.bad()) 
			{
				istr.clear();
				err_.clear();

				cout << "Quantity On hand: ";
				istr >> rQuantity;
				istr.ignore(500, '\n');

				//if no error, ask for quantity needed
				if (!istr.fail() && !istr.bad()) 
				{
					istr.clear();
					err_.clear();

					cout << "Quantity Needed: ";
					istr >> rQtyNeeded;

					//invalid entries
					//invalid quantity needed
					if (istr.fail() || istr.bad()) 
					{
						err_ = "Invalid Quantity Needed Entry";
						istr.setstate(ios::failbit);
					}
				}
				else //prints invalid quantity entry 
				{
					err_ = "Invalid Quantity Entry";
					istr.setstate(ios::failbit);
				}
			}
			else //invalid price entry
			{
				err_ = "Invalid Price Entry";
				istr.setstate(ios::failbit);
			}
		}
		else //invalid character y/n
		{
			err_ = "Only (Y)es or (N)o are acceptable";
			istr.setstate(ios::failbit);
		}

		//if no errors
		if (!istr.fail() && !istr.bad()) 
		{
			sku(rSku);
			name(rName);
			tolower(rTaxed) == 'y' ? taxed(true) : taxed(false);
			price(rPrice);
			quantity(rQuantity);
			qtyNeeded(rQtyNeeded);
		}

		return istr;
	}
}