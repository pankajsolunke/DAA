#include<iostream>
#include<cstdlib>
#include<ctime>
void merge(int arr[],int left,int mid,int right)
{
	int n1=mid-left+1;
	int n2=right-mid;
	
	int *leftArr=new int[n1];
	int *rightArr=new int[n2];
	
	for(int i=0;i<n1;i++)
	leftArr[i]=arr[left+i];
	for(int j=0;j<n2;j++)
	rightArr[j]=arr[mid+1+j];
	
	int i=0,j=0,k=left;
	while(i<n1 && j<n2)
	{
		if(leftArr[i]>=rightArr[j])
		{
			arr[k]=leftArr[i];
			i++;
		}
		else
		{
			arr[k]=rightArr[j];
			j++;
		}
		k++;
	}
	while(i<n1)
	{
		arr[k]=leftArr[i];
		i++;
		k++;
		
	}
	while(j<n2)
	{
		arr[k]=rightArr[j];
		j++;
		k++;
	}
	delete[]leftArr;
	delete[]rightArr;
}
void mergeSort(int arr[],int left,int right)
{
	if(left<right)
	{
		int mid=left+(right-left)/2;
		mergeSort(arr,left,mid);
		mergeSort(arr,mid+1,right);
		merge(arr,left,mid,right);
	}
}
int main()
{
	const int sizes[]={1000,2000,3000};
	for(int i=0;i<sizeof(sizes)/sizeof(sizes[0]);i++)
	{
		int size=sizes[i];
		int *arr=new int[size];
		for(int j=0;j<size;j++)
		{
			arr[j]=rand()%10000;
		}
		clock_t start=clock();
		mergeSort(arr,0,size-1);
		clock_t end=clock();
		
		double executionTime=double(end-start)/CLOCKS_PER_SEC;
		std::cout<<"Array of size"<<size<<"sorted in descending order:"<<executionTime<<"seconds"<<std::endl;
		std::cout<<"Sorted Array in descending order:";
		for(int j=0;j<size;j++)
		{
		  std::cout<<arr[j]<<"";
		}
			std::cout<<std::endl;
			delete[]arr;
	}
	return 0;
}











