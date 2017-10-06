// Final Project Milestone 5
// Version 1.0
// Date	2017-07-27
// Author	Daniel Casella
// File		AmaPerishable.h
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//safeguards
#ifndef SICT_AMAPERISHABLE_H
#define SICT_AMAPERISHABLE_H

//user defined file
#include "AmaProduct.h"
#include "Date.h"

//declare namespace
namespace sict {

	//declare (derived) class
	class AmaPerishable : public AmaProduct
	{
		Date expiry_;

		//public member functions
	public:
		//constructor
		AmaPerishable();

		//Public accessors (setters and getters)
		//
		//returns constant reference to expiry
		const Date& expiry() const;
		//sets expiry to incoming value
		void expiry(const Date& value);

		//virtual method implementations
		//
		//writes comma and expiry date
		fstream& store(fstream& file, bool addNewLine = true) const;
		//loads and passes file (as argument)
		fstream& load(fstream& file);
		//returns expiry date
		ostream& write(ostream& ostr, bool linear) const;
		//sets expiry date or returns error
		istream& read(istream& istr);
	
	};

}
#endif //end safeguard
