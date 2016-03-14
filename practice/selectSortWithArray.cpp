#include <iostream>

using namespace std;

int main()
{   
    //declear the function
    void select_sort(int array[], int n); 
    int a[5], i;
    cout<<"input 5 numbers: "<< endl;
    for (i=0;i<5;i++)
    cin>> a[i];
    cout<<endl;

    select_sort(a,5); 
    cout<<"the sorted array is: "<<endl;
    for (i=0; i<5;i++)
    cout<<a[i]<< " ";
    cout<<endl;
    return 0;
}

void select_sort(int array[], int n){ //use pointer variable to get the address of the array
    int i,j,k,t;
    for (i=0;i<n-1;i++){        //pointer k visit from a[0]
        k=i;                    //k represents the pointer who should point to a smaller address
        for (j=i+1;j<n;j++){    //pointer j visit form a[1]
            if(array[j]<array[k]){  //if the address pointed by k has a larger value, change the address k points to j              
                k=j;
            }
        t= array[k];      
        array[k]= array[i];        //exchange the value of a[k] (that is the a[j]) and a[i] (the old a[k])
        array[i]=t;
            
        }
        
    }
}

