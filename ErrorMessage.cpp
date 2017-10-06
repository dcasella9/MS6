// Final Project Milestone 2
// Version 1.0
// Date	July 11 2017
// Author Daniel Casella	
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason

#define _CRT_SECURE_NO_WARNINGS


//system files
#include <cstring>
#include "ErrorMessage.h"

//declare namespaces
using namespace std;

namespace sict{


	//constructor definitions
	ErrorMessage::ErrorMessage()
	{
		message_ = nullptr;
	}

	ErrorMessage::ErrorMessage(const char* errorMessage)
	{
		message_ = nullptr;
		message(errorMessage);
	}

	//Public member functions
	//Operator overloads
	ErrorMessage& ErrorMessage::operator=(const char* errorMessage)
	{
		message(errorMessage);
		return *this;
	}

	//Destructor
	ErrorMessage::~ErrorMessage()
	{
		clear();
	}

	//De-allocates memory
	void ErrorMessage::clear()
	{
		delete[] message_;
		message_ = nullptr;
	}

	//returns true if message is nullptr
	bool ErrorMessage::isClear() const
	{
		return (message_ == nullptr);
	}

	//sets object to new value by de-allocating, allocating, then copying value
	void ErrorMessage::message(const char* value)
	{
		clear();
		message_ = new char[strlen(value) + 1];
		strcpy(message_, value);
	}

	//returns the address kept in variable message_
	const char* ErrorMessage::message() const
	{
		return message_;
	}

	//Helper operator (ostream) overload
	std::ostream& operator<<(std::ostream& ostr, const ErrorMessage & em)
	{
		if (!em.isClear())
		{
			ostr << em.message();
		}

		return ostr;
	}

	//end ErrorMessage class definitions

	}