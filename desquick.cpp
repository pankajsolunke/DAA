#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
void swap(int &a ,int &b)
{
int temp=a;
a=b;
b=temp;
}
int partition(int arr[] , int low, int high)
{
	int pivot=arr[high];
	int i=low-1;
	
	for(int j=low;j<high;j++)
	{
	  if(arr[j]>=pivot)
	  {
	  	i++;
	  	swap(arr[i],arr[j]);
	  }
	}
	swap(arr[i+1],arr[high]);
	return i+1;
}
void quickSort(int arr[] ,int low,int high)
{
	if(low<high)
	{
		int pivotIndex=partition(arr , low ,high);
		quickSort(arr ,pivotIndex+1 , high);
	}
}
int main()
{
	srand(time(0));
	for(int n=1000; n<=3000 ;n+=1000)
	{
		int arr[n];
		
		for(int i=0;i<n;i++)
		{
			arr[i]=rand();
		}
		clock_t start_time=clock();
		quickSort(arr,0,n-1);
		clock_t end_time=clock();
		double execution_time=double(end_time-start_time)/CLOCKS_PER_SEC;
		cout<<"Execution time for n="<<n<<":"<<execution_time<<"seconds\n";
	}
	return 0;
}











