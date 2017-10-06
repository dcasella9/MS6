/////////////////////////////////////////////////////////////////
// Final Project Milestone 6
// Version 1.0
// Date	2017-08-06
// Author	Daniel Casella
// File		AidApp.cpp
//
//
// Revision History
// -----------------------------------------------------------
// Name               Date                 Reason
/////////////////////////////////////////////////////////////////

//user defined files
#include "AidApp.h"
#include "AmaProduct.h"
#include "AmaPerishable.h"

//declare namespace
using namespace std;

namespace sict
{
	//constructor copies, sets to null, sets noOfProducts to 0, loads recs
	AidApp::AidApp(const char* filename)
	{
			strcpy(filename_, filename);
			AidApp::product_[0] = nullptr;
			AidApp::loadRecs();
	}


	//pauses and waits for user to press <ENTER>
	void AidApp::pause() const
	{
		cout << "Press Enter to continue..." << endl;
		cin.ignore(1000, '\n');
	}
	
	//display the menu and wait for user input, then return user input option
	int AidApp::menu() 
	{
		int choice;
		cin.ignore().clear();
		cout << "Disaster Aid Supply Management Program" << endl;
		cout << "1- List products" << endl;
		cout << "2- Display product" << endl;
		cout << "3- Add non-perishable product" << endl;
		cout << "4- Add perishable product" << endl;
		cout << "5- Add to quantity of purchase products" << endl;
		cout << "0- Exit program" << endl;
		cout << "> ";
		cin >> choice;
		cin.clear();
		return (choice<0 || choice>5) ? -1 : choice;
	}

	//opens data file for reading (loads the records)
	void AidApp::loadRecs()
	{
		char tag;
	fstream file(filename_, ios::in);
	if (!file)
	{
		file.clear();
		file.close();
		file.open(filename_, ios::out);
		file.close();
	}
	else 
	{
		noOfProducts_ = 0;
		while (file.good())
		{
			file >> tag;
			file.clear();
			file.ignore();

			if (tag == 'P')
			{
				product_[noOfProducts_] = new AmaPerishable();
				product_[noOfProducts_]->load(file);
				noOfProducts_++;
			}
			else
				if (tag == 'N')
				{
					product_[noOfProducts_] = new AmaProduct();
					product_[noOfProducts_]->load(file);
					noOfProducts_++;
				}
				else if (!tag) 
				{
					product_[noOfProducts_]->load(file);
					noOfProducts_++;
				}

		}
		file.close();
	}

}

	// opens data for writing loops through array up to noOfProducts (saves the records)
	void AidApp::saveRecs() 
	{
		fstream file(filename_, ios::out);

		for (int i = 0; i< noOfProducts_; i++)
		{
			if (product_[i]->quantity() > 0)
			{
				product_[i]->store(file);
			}
		}
		file.close();
		loadRecs();
	}
	
	//display products in organized format
	void AidApp::listProducts()const
	{
		double support = 0.0;

	cout << " Row | SKU    | Product Name       | Cost  | Qty| Unit     |Need| Expiry" << endl;
	cout << "-----|--------|--------------------|-------|----|----------|----|----------" << endl;

	for (int i = 0; i < noOfProducts_; i++) 
	{

		cout << setw(4) << right << setfill(' ') << i + 1 << " | ";
		product_[i]->write(cout, true);
		cout << endl;
		support += product_[i]->cost() * product_[i]->quantity();

	}

	cout << "---------------------------------------------------------------------------" << endl;
	cout << "Total cost of support: $" << setw(1) << right << fixed << setprecision(2) << support << "" << endl;

	}

	// searches sku provided by user the returns product or error
	int AidApp::SearchProducts(const char *sku)const
	{
		int index = -1;
		for (int i = 0; i < noOfProducts_; i++)
		{
			if (*product_[i] == sku)
			{
				index = i;
			}
		}
			return index;
	}
	
	// adds quantity for the given sku if the product is found, else, returns errors
	void AidApp::addQty(const char *sku) {

		string sku_;
		int purchased;

		cout << "Please enter the SKU: ";
		cin >> sku_;

		noOfProducts_ = SearchProducts(sku_.c_str());

		if (noOfProducts_ == -1)
		{
			cout << "Not found!" << endl;
		}

		else if (noOfProducts_ != -1)
		{
			product_[noOfProducts_]->write(cout, 0);
			cout << endl;
			cout << "Please enter the number of purchased items: ";
			cin >> purchased;
			*product_[noOfProducts_] += purchased;

			saveRecs();
			cout << "Updated!" << "\n" << endl;

		}

	}
	//creates a perishable/non-perishable based of user option and saves records to file
	void AidApp::addProduct(bool isPerishable)
	{
		if (isPerishable)
		{
			product_[noOfProducts_] = new AmaPerishable();
		}
		else
		{
			product_[noOfProducts_] = new AmaProduct();
		}
		product_[noOfProducts_]->read(cin);
		if (!cin.fail())
		{
			noOfProducts_++;
			saveRecs();

			cout << endl << "Product added" << endl << endl;
		}
		else 
			if (cin.fail())
		{
			cin.clear();
			cout << *product_[noOfProducts_] << endl << endl;
			delete product_[noOfProducts_];
		}
	}
	
	//corresponding menu selected functions (case runs off users choice)
	int AidApp::run()
	{
		int choice;
		int exit = 1;
		char sku_[MAX_SKU_LEN + 1];
		int found;

		while (exit != 0)
		{
			choice = menu();
			switch (choice)
			{
			case 1:
				AidApp::listProducts();
				pause();
				break;
			case 2:
				cout << "Please enter the SKU: ";
				cin >> sku_;
				cout << endl;
				found = SearchProducts(sku_);
				if (found != -1)
				{
					product_[found]->write(cout, 0);
					cout << endl << endl;
				}
				else
				{
					cout << "Not found!" << endl;
				}

				pause();
				break;
			case 3:
				AidApp::addProduct(0);
				pause();
				break;
			case 4:
				AidApp::addProduct(1);
				pause();
				break;
			case 5:
				cout << "Please enter the SKU: ";
				cin >> sku_;
				found = SearchProducts(sku_);
				if (found != -1)
				{
					product_[found]->write(cout, 0);
					cout << endl << endl;
				}
				else
				{
					cout << "Not found!" << endl;
				}
				pause();
				break;
			case 0:
				cout << "Goodbye!!" << endl;
				exit = 0;
				break;
			default:
				cout << "===Invalid Selection, try again.===" << endl;
				pause();
			}
		}
		return 0;
	}
}