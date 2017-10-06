#define _CRT_SECURE_NO_WARNINGS
///////////////////////////////////
// Final Project Milestone 4
// Version 1.0
// Date	2017-07-17
// Author	Daniel Casella
///////////////////////////////////

//Product.cpp

//system files
#include <cstring>

//user defined files
#include "Product.h"
#include "general.h"

//using std namespace
using namespace std;

//declaring sict namespace
namespace sict {

	//constructors
	Product::Product()
	{
		sku_[0] = '\0';
		name_ = nullptr;
		price_ = 0;
		taxed_ = true;
		quantity_ = 0;
		qtyNeeded_ = 0;
	}

	Product::Product(const char* sku, const char* name, double price, bool taxed, int quantity, int qtyNeeded) 
	{
		strncpy(sku_, sku, MAX_SKU_LEN);

		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);

		quantity_ = 0;
		taxed_ = taxed;
		price_ = price;
		qtyNeeded_ = qtyNeeded;
	}

	
	Product::Product(const Product& p)
	{
		strncpy(sku_, p.sku_, MAX_SKU_LEN);

		name_ = nullptr;
		name_ = new char[strlen(p.name_) + 1];
		strcpy(name_, p.name_);

		taxed_ = p.taxed_;
		price_ = p.price_;
		quantity_ = p.quantity_;
		qtyNeeded_ = p.qtyNeeded_;
	}

	//copy constructor
	Product & Product::operator=(const Product & p) 
	{
		strncpy(sku_, p.sku_, MAX_SKU_LEN);

		name_ = new char[strlen(p.name_) + 1];
		strcpy(name_, p.name_);

		taxed_ = p.taxed_;
		price_ = p.price_;
		quantity_ = p.quantity_;
		qtyNeeded_ = p.qtyNeeded_;

		return *this;
	}

	//destructor
	Product::~Product() 
	{
		delete[] name_;
		name_ = nullptr;
	}

	//Accessors
	//Setters
	//sku setter functions
	void Product::sku(const char* sku)
	{
		strncpy(sku_, sku, MAX_SKU_LEN);
	}

	//price setter function
	void Product::price(double price)
	{
		price_ = price;
	}

	//name setter function
	void Product::name(const char* name)
	{
		delete[] name_;
		name_ = new char[strlen(name) + 1];
		strcpy(name_, name);
	}

	//taxed setter function
	void Product::taxed(bool taxed) 
	{
		taxed_ = taxed;
	}

	//quantity setter function
	void Product::quantity(int quantity)
	{
		quantity_ = quantity;
	}

	//quantity needed setter function
	void Product::qtyNeeded(int qtyNeeded)
	{
		qtyNeeded_ = qtyNeeded;
	}
	
	//Getter (Queries)
	//returns product sku
	const char* Product::sku() const 
	{
		char* sku;
		sku = new char[strlen(sku_) + 1];
		strcpy(sku, sku_);
		return sku;
	}

	//returns product name
	const char * Product::name() const 
	{
		return name_;
	}

	//returns product price
	double Product::price() const 
	{
		return price_;
	}

	//returns if product is taxed or not
	bool Product::taxed() const 
	{
		return taxed_;
	}

	//returns quantity of products
	int Product::quantity() const
	{
		return quantity_;
	}

	//returns the amount of quantity needed
	int Product::qtyNeeded() const
	{
		return qtyNeeded_;
	}

	//returns cost of product(s)
	double Product::cost() const
	{
		return taxed_ ? price_ * (1 + TAX) : price_;
	}

	//returns safe empty state
	bool Product::isEmpty() const
	{
		return sku_[0] == '\0';
	}
	
	//member operator overloads
	//comparison operator, return true/false
	bool Product::operator==(const char* cmp) 
	{
		return !strcmp(sku_, cmp);
	}

	//add to product, return sum
	int Product::operator+=(int num1)
	{
		return quantity_ += num1;
	}

	//subtract quantity of product, return sum
	int Product::operator-=(int num2)
	{
		return quantity_ -= num2;
	}

	//non-member operator overload
	//adds total cost and returns sum
	double operator+=(double & i, const Product & p)
	{
		return i += p.cost() * p.quantity();
	}

	//non-member IO operator overloads
	//input stream overload function
	std::istream & operator >> (std::istream & istr, Product & p)
	{
		return p.read(istr);
	}

	//output stream overload function
	std::ostream & operator<<(std::ostream & ostr, const Product & p)
	{
		return p.write(ostr, true);
	}
}
