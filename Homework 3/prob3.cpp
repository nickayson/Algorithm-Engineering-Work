// 3. Given two sets with at most 10 elements each, write a program to enter the elements of each set in an ordered list. Find and display both sets and their intersection set ( set of their common elements )

//     Sample I/O
//            Enter the elements of setA with -1 at the end: 3  9 5 8  2  -1
//            Enter the elements of setB with -1 at the end: 7 2 10 3 -1
//            setA: 23589>>NULL
//            setB: 23710NULL
//            setAIB: 237NULL

#include <iostream>

using namespace std;

//function to sort an list
void sortList(int a[], int size)
{
    //outer for loop
    for(int i=0;i<size;i++)
    {
        //inner for loop
        for (int j=0;j<size;j++)
        {
            if(a[i]<a[j])
            {
                //swap the values
                int temp = *(a+i);
                *(a+i)=*(a+j);
                *(a+j) = temp;
            }
        }
    }
}

int main()
{
    //array declaration
    int setA[11], setB[11], setAB[11];
  
    //variable declaration
    int sizeA, sizeB, element, i;
  
    //get the setA from the user
    cout<<"Enter the elements of setA with -1 at the end: ";
    sizeA=0;
    while(true)
    {
        cin>>element;
        if(element == -1)
        {
            setA[sizeA] = -1;
            break;
        }
        else
        setA[sizeA++] = element;
    }
  
    //function calling
    sortList(setA, sizeA);
  
    //get the setB from user
    cout<<"Enter the elements of setB with -1 at the end: ";
    sizeB=0;
  
    while(true)
    {
        cin>>element;
        if(element == -1)
        {
            setB[sizeB] = -1;
            break;
        }
        else
        setB[sizeB++] = element;
    }
  
    //function calling
    sortList(setB, sizeB);
    i = 0;
  
    //display the setA
    cout<<"setA: ";
    while(true)
    {
        if(setA[i]==-1)
        {
            cout<<"NULL";
            break;
        }
    cout << setA[i++] <<"->";
    }
  
    i = 0;
  
    //display the setB
    cout<<endl<<"setB: ";
    while(true)
    {
        if(setB[i]==-1)
        {
            cout<<"NULL";
            break;
        }
    cout << setB[i++] << "->";
    }
  
    //display the intersection set
    cout<<endl<<"setA|B: ";
    for(int k=0; k<sizeA; k++)
    {
        for(int j=0; j<sizeB; j++)
        {
            if(setA[k] == setB[j]){
                cout << setB[k] << "->";
            }
        }   
    }
    cout << "NULL";
    return 0;
}