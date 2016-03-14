#include <iostream>
#include <cassert>
#include <string>
#include <cctype>
using namespace std;

int readSign(int& i , string commands);
int readDigits(int& i, string commands);
bool readDirection(int& i,string commands,int& dx, int& dy);

bool isWellFormedCommandString(string commands);
bool crossedOriginOnItsPath(string commands);

int main()
{
	//well-formed cases
	string test1 = "4N-3S+12NE6W";
	string test2 = "4e-3sw+12se7s";
	string test3 = "+4nw1e3w";
	string test4 = "1Nw-2sE7nE6Sw";
	string test5 = "3N";
	string test6 = "-3e";
	string test7 = "90S33w";
	string test8 = "333s-34N";
	//well-formed cases that passed the origion
	string test9 = "+1N-1N";
	string test10 = "1n1s";
	string test11 = "3ne+3w-1N+2S-10e";
	string test12 = "1ne+2nw+1sw-4se6S6E-1s";
	assert(isWellFormedCommandString(test1));
	assert(isWellFormedCommandString(test2));
	assert(isWellFormedCommandString(test3));
	assert(isWellFormedCommandString(test4));
	assert(isWellFormedCommandString(test5));
	assert(isWellFormedCommandString(test6));
	assert(isWellFormedCommandString(test7));
	assert(isWellFormedCommandString(test8));
	cerr<<"Passed test 1"<<endl;

	//not well-formed test cases
	string test01 = "7q+8A";
	string test02 = "+-12s";
	string test03 = "s12e-3";
	string test04 = "1000s-2000N";
	assert(!isWellFormedCommandString(test01));
	assert(!isWellFormedCommandString(test02));
	assert(!isWellFormedCommandString(test03));
	assert(!isWellFormedCommandString(test04));
	assert(!isWellFormedCommandString("++++"));
	assert(!isWellFormedCommandString("N"));
	assert(!isWellFormedCommandString("0e"));
	assert(!isWellFormedCommandString("EE"));
	assert(!isWellFormedCommandString("1000s"));
	assert(!isWellFormedCommandString(""));
	assert(!isWellFormedCommandString("  "));
	cerr<<"Passed test 2"<<endl;

	//crossed origin test
	assert(!crossedOriginOnItsPath(test5));
	assert(!crossedOriginOnItsPath(test6));
	assert(!crossedOriginOnItsPath(test7));
	assert(!crossedOriginOnItsPath(test8));
	assert(crossedOriginOnItsPath(test9));
	assert(crossedOriginOnItsPath(test10));
	assert(crossedOriginOnItsPath(test11));
	assert(crossedOriginOnItsPath(test12));
	cerr<<"Passed test 3"<<endl;

}

int readSign(int& i , string commands)
{
	int sign=1,nSign=0;
	// read connected signs +-- 
	while (i<commands.size()&& (commands[i]=='+'||commands[i]=='-'))
	{	
		if(commands[i]=='+')
		{	sign=1;
			nSign++;
			i++;
		}	
	
		if (commands[i]=='-')
		{	sign=-1;
			nSign++;
			i++;
		}
		if (nSign>1)		//if more than one sign connected		
			return 0;
	}
	return sign;
}

int readDigits(int& i, string commands) 	//read digits from command[i], the same time move i when taking a digit 
{
	string read="";
	while(i<commands.size() && isdigit(commands[i]))
	{
		read += commands[i];
		i++;		
	}
	
	if(read == "")				//not digit, not valid
		return 0;
	else
		return std::stoi(read);		//return the read digits as int	
}

bool readDirection(int& i,string commands,int& dx, int& dy)
{
	string read="";
	while(i<commands.size()&& isalpha(commands[i]))
	{
		read += tolower(commands[i]);
		i++;
	}
/*	//the first method to compare strings
	if (read.compare("n")==0)	{dy = 1;} 
	else if (read.compare("w")==0)	{dx = -1;}
	else if (read.compare("e")==0)	{dx = 1;}
	else if (read.compare("s")==0)	{dy = -1;}
	else if (read.compare("ne")==0)	{dx = 1; dy = 1;}
	else if (read.compare("nw")==0)	{dx = -1; dy = 1;}
	else if (read.compare("sw")==0)	{dx = -1; dy = -1;}
	else if (read.compare("se")==0)	{dx = 1; dy = -1;}
	else 
		return false;
	return true;
*/
	//the second method to compare strings
	if (read=="n")	{dy = 1;} 
	else if (read=="w")	{dx = -1;}
	else if (read=="e")	{dx = 1;}
	else if (read=="s")	{dy = -1;}
	else if (read=="ne")	{dx = 1; dy = 1;}
	else if (read=="nw")	{dx = -1; dy = 1;}
	else if (read=="sw")	{dx = -1; dy = -1;}
	else if (read=="se")	{dx = 1; dy = -1;}
	else 
		return false;
	return true;

}

bool isWellFormedCommandString(string commands)
{
	//the valid code should be [+/-]?[0-9]?[0-9]?[0-9][s|e|n|w|nw|ne|sw|se]
	//1n1w is the same as nw

	//if the command is empty
	if(commands.size()==0)
		return false;
	
	int i=0;
	
	while (i<commands.size())
	{
		int steps=0, dx=0, dy=0, sign=1;
		string dir;
		// 1. read signs
		//	if no sign, sign = 1; 	
		// 	if '+', sign = 1;
		// 	if '-', sign = -1;
		//	if invalid sign, eq.'++-', sign =0
		sign = readSign(i,commands);
		if (sign ==0)			
			return false;

		// 2. read number, false if 0 or more than three digits
		steps = readDigits(i,commands);
		if (steps ==0 || steps>999)
			return false;		

		// 3. read direction, false if not a valid direction
		if (!readDirection(i,commands,dx,dy))
			return false;
	}	
	return true;
}

bool crossedOriginOnItsPath(string commands)
{
	if(!isWellFormedCommandString(commands))
		return false;
	int x=0, y=0,i=0;
	while (i<commands.size())
	{
		int steps=0, dx=0, dy=0, sign=1;

		sign = readSign(i,commands);
		steps = readDigits(i,commands);
		readDirection(i,commands,dx,dy);

		// 4. move and add to total, return false if cross (0,0)	
		x += sign*steps*dx;
		y += sign*steps*dy;
		if (x==0 && y==0)
			return true;
	}
	return false;

}
