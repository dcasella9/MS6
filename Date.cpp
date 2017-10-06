// Final Project Milestone 1
//
// Version 1.0
// Date: July 8 2017
// Author: Daniel Casella
// Description: Creating the Date Class
//
//
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//system files
#include <iomanip>
#include <iostream>
#include "Date.h"
#include "general.h"

//declare namespace
using namespace std;

//namespace scope
namespace sict{
    
	//return date value
	int Date::value()const
	{
		return year_ * 372 + mon_ * 31 + day_;
	}

	//return error code
  void Date::errCode(int errorCode) 
  {
    readErrorCode_ = errorCode;
  }

  // for validating format
   void Date::isValid() 
   {
    if(year_ < MIN_YEAR || year_ > MAX_YEAR) 
	{
      readErrorCode_ = YEAR_ERROR;
    } 
	else if(mon_ < 1 || mon_ > 12)
	{
      readErrorCode_ = MON_ERROR;
    } 
	else if(day_ < 1 || day_ > mdays())
	{
      readErrorCode_ = DAY_ERROR;
    } 
	else
	{
      readErrorCode_ = NO_ERROR;
    }
  }

  int Date::mdays()const{
    int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
    int mon = mon_ >= 1 && mon_ <= 12 ? mon_ : 13;
    mon--;
    return days[mon] + int((mon == 1)*((year_ % 4 == 0) && (year_ % 100 != 0)) || (year_ % 400 == 0));
  }

  // default constructor
  Date::Date()
  {
    year_ = 0;
    mon_ = 0;
    day_ = 0;
    readErrorCode_ = NO_ERROR;
  }

  //3 argument constructor
  Date::Date(int year, int mon, int day) 
  {
    year_ = year;
    mon_ = mon;
    day_ = day;
    isValid();
  }

  // member functions
  int Date::errCode() const 
  {
    return readErrorCode_;
  }

  bool Date::bad() const 
  {
    return errCode() != NO_ERROR;
  }

  // operators
  bool Date::operator==(const Date& D) const 
  {
    return value() == D.value();
  }

  bool Date::operator!=(const Date& D) const
  {
    return value() != D.value();
  }

  bool Date::operator<(const Date& D) const 
  {
    return value() < D.value();
  }

  bool Date::operator>(const Date& D) const 
  {
    return value() > D.value();
  }

  bool Date::operator<=(const Date& D) const 
  {
    return value() <= D.value();
  }

  bool Date::operator>=(const Date& D) const 
  {
    return value() >= D.value();
  }

  // Input and Output definitions
  //istream function for reading
  std::istream& Date::read(std::istream& istr) 
  {
    istr >> year_;
    if (istr.get() != '/')
	{
      readErrorCode_ = CIN_FAILED;
      return istr;
    }

    istr >> mon_;

    if (istr.get() != '/') 
	{
      readErrorCode_ = CIN_FAILED;
      return istr;
    }

    istr >> day_;
    isValid();
    return istr;
  }

  //ostream function for writing
  std::ostream& Date::write(std::ostream& ostr)const 
  {
    ostr << year_ << "/";
    if (mon_ < 10) 
	{
      ostr << "0";
    }

    ostr << mon_ << "/";
    if (day_ < 10) 
	{
      ostr << "0";
    }

    ostr << day_;

    return ostr;
  }

  // ostream operator overload
  std::ostream& operator<<(std::ostream& ostr, const Date& D)
  {
      return D.write(ostr);
  }

  //istream operator overload
  std::istream& operator>>(std::istream& istr, Date& D)
  {
      return D.read(istr);
  }
}