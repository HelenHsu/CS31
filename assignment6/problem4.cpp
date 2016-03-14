    #include <iostream>
    using namespace std;

    int* minimart(int* a, int* b)
    {
//compare the value of two return the address of the smaller one
        if (*a < *b)	
            return a;
        else
            return b;
    }
    void swap1(int* a, int *b)
    {
//trying to change two pointers, but the pointer is pass by value, so it won¡¦t work
        int* temp = a;
        a = b;
        b = temp;
    }
    void swap2(int* a, int *b)
    {
//use the pointer to change the value of two input
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    int main()
    {
        int array[6] = { 5, 3, 4, 17, 22, 19 };
        int* ptr = minimart(array, &array[2]);
//ptr is now at array[2]
        ptr[1] = 9;
//set arr[3]=9
        ptr += 2;
//move the pointer to arr[4]
        *ptr = -1;
//set arr[4] to -1
        *(array+1) = 79;
//set arr[1] to 79
        cout << "diff=" << &array[5] - ptr << endl;
//output ¡§diff=¡¨ the distance of array[5]and current pointer, which get the result 1
        swap1(&array[0], &array[1]);
//do nothing
        swap2(array, &array[2]);
//now arr[0]=4 and arr[2]=5
        for (int i = 0; i < 6; i++)
            cout << array[i] << endl;
//get 4 79 5 9 -1 19  
        cin.get();
		return( 0 );
		
    } 
	//////////real output
	//diff=1
	//4
	//79
	//5
	//9
	//-1
	//19