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

//safeguards
#ifndef __SICT_DATE_H__
#define __SICT_DATE_H__
// header file includes
#include <iostream>


namespace sict{
  // general defined values
  //Error codes
  #define NO_ERROR 0
  #define CIN_FAILED 1
  #define YEAR_ERROR 2
  #define MON_ERROR 3
  #define DAY_ERROR 4
  class Date{
  private:

	  //private member variables and functions
    int year_;
    int mon_;
    int day_;
    int readErrorCode_;
    int value() const;
    void errCode(int);
    void isValid();
 
  public:
	  //public member functions
      // constructors
    Date();
    Date(int, int, int);

    // logic comparison operators
    bool operator==(const Date& D)const;
    bool operator!=(const Date& D)const;
    bool operator<(const Date& D)const;
    bool operator>(const Date& D)const;
    bool operator<=(const Date& D)const;
    bool operator>=(const Date& D)const;

    // Input and Output member funcions
    std::istream& read(std::istream& istr);
    std::ostream& write(std::ostream& ostr)const;

    // Accessors/Getters
    int mdays()const;
    int errCode()const;
    bool bad()const;
  };
 
  //istream and ostream operartor overloads
  std::ostream& operator<<(std::ostream& ostr, const Date& D);
  std::istream& operator>>(std::istream& istr, Date& D);
}
#endif