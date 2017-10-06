// Final Project Milestone 5
// Version 1.0
// Date	2017-07-27
// Author	Daniel Casella
// File		AmaProduct.h
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//safeguards
#ifndef SICT_AMAPRODUCT_H_
#define SICT_AMAPRODUCT_H_

//system defined files
#include <fstream>

//user defined files
#include "ErrorMessage.h"
#include "Product.h"

//declare namespace
using namespace std;

namespace sict {

	//declare class
	class AmaProduct : public Product
	{
		//private member functions
	private:
		//tags records as perishable or non-perishable
		char fileTag_;
		//unit of measurement
		char unit_[11];

		//protected member function
	protected:
		//returns error message
		ErrorMessage err_;

		//public member functions
	public:

		//constructor with default 'N' value
		AmaProduct(char tag = 'N');
		//returns poitner to unit
		const char* unit() const;
		//copies incoming value into unit
		void unit(const char* value);
		//writes fileTag and comma into the file
		fstream& store(fstream& file, bool addNewLine = true) const;
		//sets member variables using setter methods
		fstream& load(fstream& file);
		//writes error or (if no err_) two different formats
		ostream& write(ostream& ostr, bool linear) const;
		//receives values		
		istream& read(istream& istr);
	};

}

#endif
// AmaProduct.h


