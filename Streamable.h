// Final Project Milestone 3
// Version 1.0
// Date	2017-07-11
// Author Daniel Casella
////////////////////////////////

//safeguards
#ifndef SICT_STREAMABLE_H_
#define SICT_STREAMABLE_H_

//system files
#include <string>
#include <iostream>
#include <fstream>

//using std namespace
using namespace std; 

//declaring sict namespace
namespace sict {

	//declare class
	class Streamable {
	
	//public members
	public:

		//public member prototypes
		//Four Pure virtual member functions (methods)

		virtual fstream& store(fstream& file, bool addNewLine = true) const = 0;
		virtual fstream& load(std::fstream& file) = 0;
		virtual ostream& write(ostream& os, bool linear) const = 0;
		virtual istream& read(istream& is) = 0;
	};//end class

}
 //end safeguards
#endif 
