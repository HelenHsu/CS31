/////////////////////////////////////////////
//
//	CS31 proj2
//	bill.cpp
//	Ya Han Hsu
//	304513231
//
/////////////////////////////////////////////
#include <iostream>

#include <string>

#include <iomanip>	//for setposition

using namespace std;


int main()

{
	
	string name,type;
	
	double energy;
	
	double bill;
	
	
	cout << "Customer Name: ";
	
	getline(cin,name);		//name could be a long string
							//cin.get will only get the first string before a space
	
	if (name=="")
							//if no input 
	{	
		
		cout<< "---"<<endl;
		
		cout<<"You must enter a customer name."<<endl;
		
		return 1;			//end the program
	
	}
	
	cout<<"Energy Used (in kilowatt hours): ";
	
	cin>> energy;
	
	if (energy<0)			//if negative usage
	
	{	
		
		cout<<"---"<<endl;
		
		cout<<"The energy usage reading must be nonnegative."<<endl;
		
		return 1;
	
	}
	
	cout << "Customer Type: ";	
	cin.ignore(1000,'\n');	//to ignore the last input
	getline(cin,type);		//read new line
	if (type != "Residential" && type != "Business") 	//if input is neither residential nor business
	{
		cout<<"---"<<endl;
		cout<<"The customer type is not valid."<<endl;
		return 1 ;
	}
	
	if (type=="Residential")
	{
		if (energy<=10)
			bill = energy*4.5;

		else if (energy<=20)
			bill = 45+(energy-10)*9.00;

		else
			bill = 45+90+(energy-20)*15.00;

		bill += 14.95;		//service charge
	}

	if (type=="Business")
	{
		if (energy<=10)
			bill = energy*7.5;

		else if (energy<=20)
			bill = 75+(energy-10)*15.00;

		else
			bill = 75+150+(energy-20)*20.00;

		bill += 19.95;		//service charge
	}

	cout<<"---"<<endl;
	cout<<fixed<<showpoint;
	cout<<setprecision(2);	//show two digits after float point
	cout<<"The bill for "<<name<<" is $"<<bill<<endl;
	return 0;
}
