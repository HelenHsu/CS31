//////////////////////////////////////////////////////////////////////////
//	array.cpp			                               	//
//	CS31	proj4							//
//	YaHan Hsu							//
//	304513231							//
//////////////////////////////////////////////////////////////////////////
#include <iostream>
#include <cassert>
#include <string>
using namespace std;
//////////////////////////////////////////////////////////////////////////
int locateMinimum(const string array[],int n);
//if n<=0 return -1
//return index of the smallest item

int findLastOccurrence(const string array[],int n, string target);
//return the last index of the target
//if not found, return -1

int flipAround(string array[],int n);
//flip the array and return the number of flipping pairs

bool hasNoDuplicates(const string array[], int n);
//if every item is unique, return true
//else return false

void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize);
//combine array1 and array2 without duplicate items
//modifying the resultingSize and resultingString

int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties);
//shift the whole array right with n space, and fill those n space with place holder

bool isInIncreasingOrder(const string array[], int n);
//check if array is in increasing order, if so return true
//if size ==1 return true
//else, or if n<0 return fasle
////////////////////////////////////////////////////////////////////////////
int locateMinimum(const string array[],int n)
{
	if (n<=0) 
		return -1;
	int index=0;
	for(int i=0; i!=n; i++)
	{
		if (array[i]<array[index])	
			index=i;		//get the index of current min
	}
	return index;
}
///////////////////////////////////////////////////////////////////////////
int findLastOccurrence(const string array[],int n, string target)
{
	int index=-1;
	if (n<=0)
		return index;	
	for(int i=0;i!=n;i++)
	{
		if (array[i]==target && i>index)	//record the last index
			index = i;
	}
	return index;
}
//////////////////////////////////////////////////////////////////////////
int flipAround(string array[],int n)
{
	if (n<=0||n==1)
		return 0;
	string temp;
	int index=(n%2==0?n/2:(n-1)/2);		//if odd, get the middle; if even get the first of the second half
	for (int i=0; i!= index; i++)
	{
		temp = array[i];		//swap two items
		array[i]= array[n-i-1];
		array[n-i-1] = temp;
	}
	return index;
}

///////////////////////////////////////////////////////////////////////////
bool hasNoDuplicates(const string array[], int n)
{
	if (n<0)
		return false;
	if (n==1||n==0)
		return true;
	for(int i=0; i!=n-1;i++)
	{
		for (int j=i+1; j!=n; j++)	//compare with the rest of the string
		{
			if (array[i]==array[j])
				return false;
		}
	}
	return true;
}


//////////////////////////////////////////////////////////////////////////////
void unionWithNoDuplicates(const string array1[], int n1, const string array2[], int n2, string resultingString[], int& resultingSize)
{
	resultingSize=0;
	for(int i=0;i!=n1;i++)					//array1 first
	{
		bool isFound=false;
		for (int j=0; j!=resultingSize; j++)		//compare with current items in the result, past if notfound
		{
			if (array1[i]==resultingString[j])
			{	isFound=true;
				break;				//once found, break the first for loop
			}
		}
		if (! isFound)
		{	resultingString[resultingSize]=array1[i];		
			resultingSize++;
		}
	}
	for (int i=0; i!=n2; i++)
	{
		bool isFound=false;
		for(int j=0; j!=resultingSize; j++)
		{
			if(array2[i]==resultingString[j])
			{
				isFound=true;
				break;
			}
		}
		if(!isFound)
		{
			resultingString[resultingSize]=array2[i];
			resultingSize++;
		}
	}
}
//////////////////////////////////////////////////////////////////////////////
int shiftRight(string array[], int n, int amount, string placeholderToFillEmpties)
{	
	if(amount<0||amount>n)
		return -1;
	if(amount==0)
		return n;
	for(int i=n-amount-1; i!=-1;i--)		//move the item form the back
		array[i+amount]=array[i];		
	for(int i=0; i!=amount;i++)			//then place the holder
		array[i]=placeholderToFillEmpties;
	return n-amount;
}
//////////////////////////////////////////////////////////////////////////////
bool isInIncreasingOrder(const string array[], int n)
{
	if (n<=0)
		return false;
	if (n==1)
		return true;
	for(int i=0;i!=n-1;i++)
	{
		if(array[i]>=array[i+1])	//strictly increasing
			return false;
	}
	return true;
}

//////////////////////////////////////////////////////////////////////////////
int main()
{
	string a[6]={"alpha","beta","gamma","gamma","alpha","delta"};
	string b[6]={"delta","gamma","beta","alpha","beta","omega"};
	string c[5]={"a","b","b","c","d"};
	string d[5]={"a","b","c","d","e"};
	string h[7]={"samwell","jon","margaery","daenerys","","tyrion","margaery"};
	int answer;
	string output[12] = { " "," "," "," "," "," "};
	int outputSize =12;
      //test locateMinimum
	assert(locateMinimum(a,0)==-1);			//test n=0 case
	assert(locateMinimum(b,1)==0);			//test n=1 case
	assert(locateMinimum(a,3)==0);			
	assert(locateMinimum(a,5)==0);			//test if it returns the first minimun when duplicates are found
	assert(locateMinimum(b,3)==2);			//test the mini that is not at the front of the list
      //test findLastOccurrence
	assert(findLastOccurrence(a,0,"alpha")==-1);	//test n=0 case
	assert(findLastOccurrence(a,4,"theta")==-1);	//test non found case
	assert(findLastOccurrence(a,5,"alpha")==4);	//test normal function
	assert(findLastOccurrence(b,3,"beta")==2);
      //test hasNoDuplicates
	assert(hasNoDuplicates(a,-1)==false);		//test n=-1
	assert(hasNoDuplicates(a,3)==true);		//test true case
	assert(hasNoDuplicates(a,4)==false);		//test false case
      //test isInIncreasingOrder	
	assert(isInIncreasingOrder(a,3)==true);		//test true case
	assert(isInIncreasingOrder(a,6)==false);	//test false case
	assert(isInIncreasingOrder(c,5)==false);	//test array with duplicate items
	assert(isInIncreasingOrder(d,5)==true);		//test true case
      //test uncionWithNoDuplicates
	unionWithNoDuplicates(a,6,b,2,output,outputSize);
	assert(outputSize==4);				//check ouputSize
	assert(output[0]=="alpha");			//test normal function
	for(int i=0; i!=outputSize;i++)
		cerr<<output[i]<<endl;
	outputSize=12;
	output={""};			
	unionWithNoDuplicates(a,6,b,6,output,outputSize);	//with extra items in array2
	assert(outputSize==5);				
	assert(output[4]=="omega");
	cerr<<endl;
	for(int i=0; i!=outputSize;i++)
		cerr<<output[i]<<endl;
      //test shiftRight
	answer = shiftRight(h,6,1,"foobar");	
	assert(answer==5);				//check return value
	assert(h[0]=="foobar");				//check holder
	assert(h[1]=="samwell");			//check moved items
	assert(shiftRight(h,6,10,"foobar")==-1);	//test amount>n case
	assert(shiftRight(h,6,0,"foobar")==6);		//test amount=0 case
	assert(shiftRight(h,6,-3,"foobar")==-1);	//test amount<0 case
      //test flipAround
	assert(flipAround(b,1)==0);			//test n=1 case
	assert(flipAround(b,-1)==0);			//test n<0 case
	assert(flipAround(b,3)==1);			//test n is odd case
	assert(b[0]=="beta");				
	assert(b[1]=="gamma");
	assert(flipAround(b,4)==2);			//test n is even case
	assert(b[0]=="alpha");
	assert(b[1]=="delta");				

	cout<<"All test succeed"<<endl; return(0);
}
