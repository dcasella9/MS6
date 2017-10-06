// Final Project Milestone 5
// Version 1.0
// Date	2017-07-27
// Author	Daniel Casella
// File		AmaPersishable.cpp
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//user defined files
#include "AmaPerishable.h"
#include "Date.h"
#include "AmaProduct.h"


//declare namespace
using namespace std;

namespace sict {
	//constructor
	AmaPerishable::AmaPerishable() : AmaProduct('P')
	{

	};

	//return constant reference to expiry
	const Date& AmaPerishable::expiry() const
	{
		return expiry_;
	}

	//sets expiry to incoming value
	void AmaPerishable::expiry(const Date& value)
	{
		expiry_ = value;
	}

	//writes comma and expiry date to file
	fstream& AmaPerishable::store(fstream& file, bool addNewLine) const
	{
		AmaProduct::store(file, false);

		file << ',' << expiry_;

		if (addNewLine)
			file << endl;
		return file;
	}

	//passes file as argument then calls the read method then dumps it
	fstream& AmaPerishable::load(fstream& file)
	{
		AmaProduct::load(file);
		expiry_.read(file);
		file.ignore();
		return file;

	}

	//if err is clear and not empty, print expiry
	ostream& AmaPerishable::write(ostream& ostr, bool linear) const
	{
		AmaProduct::write(ostr, linear);
		if (err_.isClear() && !isEmpty())
		{
			//print expiry separated by BAR "|"
			if (linear)
				ostr << expiry_;
			
			//prints expiry in a new line 
			else
				ostr << endl << "Expiry date: " << expiry_;
		}

		return ostr;

	}

	//passes istr as argument
	istream& AmaPerishable::read(istream& istr)
	{
		AmaProduct::read(istr);

		//if no errors, ask for expiry date
		if (err_.isClear())
		{
			cout << "Expiry date (YYYY/MM/DD): ";

			//reads date from console
			Date temp;
			istr >> temp;

			//if invalid entry
			if (temp.bad())
			{
				switch (temp.errCode())
				{
					//invalid date 
				case CIN_FAILED:
					err_.message("Invalid Date Entry");
					break;
					//invalid year
				case YEAR_ERROR:
					err_.message("Invalid Year in Date Entry");
					break;
					//invalid month
				case MON_ERROR:
					err_.message("Invalid Month in Date Entry");
					break;
					//invalid dayy
				case DAY_ERROR:
					err_.message("Invalid Day in Date Entry");
					break;
				}
				//set failure mode
				istr.setstate(ios::failbit);
			}
			//if nothing fails, set expiry date object to temp object
			else
			{
				err_.clear();
				istr.clear();

				expiry_ = temp;
			}
		}
		return istr;
	}
}