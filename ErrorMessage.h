// Final Project Milestone 2
// Version 1.0
// Date	 July 11 2017
// Author	Daniel Casella
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason

//safe guards
#define _CRT_SECURE_NO_WARNINGS

#ifndef _SICT_ERROR_H
#define _SICT_ERROR_H

//system files
#include <iostream>

namespace sict {

	class ErrorMessage {

		char* message_;

	public:

		//Constructors
		ErrorMessage();
		ErrorMessage(const char* errorMessage);
		ErrorMessage(const ErrorMessage& em) = delete;

		//Public member functions and operator overloads
		ErrorMessage& operator=(const ErrorMessage& em) = delete;
		ErrorMessage& operator=(const char* errorMessage);
		virtual ~ErrorMessage();
		void clear();
		bool isClear()const;
		void message(const char* value);
		const char* message()const;

	};

	//Helper operator overload
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage& em);

}



#endif

//End of headerfile
