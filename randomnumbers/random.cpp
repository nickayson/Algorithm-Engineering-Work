// 1.	Given array : int a[10];  Write a program to generate 15 random numbers between 1 and 6 and store them in array a. 
// Display array a, compute and display Mean, Median, and the Mode of data in array a.
// It is possible the set of data have more than one mode ( two or more numbers have the same high frequency), display all modes

#include <bits/stdc++.h>
using namespace std;
 
// Function for calculating mean
double findMean(int a[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += a[i];
 
    return (double)sum / (double)n;
}
 
// Function for calculating median
double findMedian(int a[], int n)
{
    // check for even case
    if (n % 2 != 0){
        return (double)a[n / 2];
    }
 
    return (double)(a[(n - 1) / 2] + a[n / 2]) / 2.0;
}

//function to calculate mode and print itself
void findMode(int a[], int n)
{
    int y[10]={};
    int i, j, k, m, cnt, count, max=0;
    int mode_cnt=0;
    int num;
    int v;
    vector<int> results;
    vector<int>::iterator pos;

    //loop to count an array from left to right
    for(k=0; k < 10; k++) {
      cnt=0;
      num=a[k]; //num will equal the value of x[k]
      for(i=k; i<10; i++) {   
         if(num==a[i])
            cnt++;              
      }
      y[k]=cnt; 
    }

    //find highest number in array
    for(j=0; j<10; j++) 
    {
      if(y[j]>max)
         max=y[j];
    }

    //find how many modes there are
    for(m=0; m<10; m++) 
    {
      if(max==y[m])
         mode_cnt++;
    }

    //push results to vector
    for (m=0; m < 10; m++) 
    {
      if(max == y[m]) 
      {
        //after taking out this line the code works properly
        //      std::cin >> x[m]; 
        results.push_back(a[m]);    
      }
    } 
    //sort vector and print
   std::sort(results.begin(), results.end());
   cout << "The mode(s) is/are: ";
   for (pos=results.begin(); pos!=results.end(); ++pos) {
         cout << *pos << " ";
   }
}
 
// Driver code
int main()
{   
    //given
    int a[10];
    int n = sizeof(a) / sizeof(a[0]);

    srand(time(0));//help with rand function

    for(int i=0; i < n; i++){
        a[i]= rand() % 6 + 1;  //Generate number between 1 to 6
    }
  
    cout<<"\nElements of the array:"<<endl;
    for(int i=0; i < n; i++){
        cout<<"Elements no "<<i+1<<":"<<a[i]<<endl;
    }
   
    // Function call
    cout << "Mean = " << findMean(a, n) << endl;
    cout << "Median = " << findMedian(a, n) << endl;
    findMode(a , n);
    return 0;
}