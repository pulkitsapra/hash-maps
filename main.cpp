#include <cstdlib>
#include <iostream>
#include <exception>
#include <limits>
#include "OpenMap.hpp"
#include "Dictionary.hpp"

using namespace std;

int find_max(int *array, int size){
	int max = 0;
	for(int i = 0; i < size; ++i){
		if(array[max] < array[i]){
			max = i;
		}

		return max;
	}	
}



int main(int argc, char const *argv[])
{
	int n,m,k;
	cout<<"Enter the size of each memory block : ";
	cin>>k;
	cout<<"Enter the number of memory blocks in the main memory : ";
	cin>>m;
	cout<<"Enter the number of memory blocks in the cache memory : ";
	cin>>n;

	cs202::OpenMap<int,int> A(n);
	cout<<A.get_capacity();

	int counter[n];
	bool flag[n];                                                  //1: element present   0: element not present
	
	for (int i = 0; i < n; ++i)                                    //Initializing count of all elements in main memory to  0
	{
		counter[i] = 0;
		flag[i] = 0;
	}

	int numofOp;
	
	cout<<"Enter the number of operations you want to do : ";
	
	cin>>numofOp;
	
	for (int j = 0; j < numofOp; ++j)
	{
		cout<<"Enter the location to be read : ";
		int addr;
		cin>>addr;
		int memblock = addr/k;
				
		if(A.get_size()==n)
		{
			int max_key = find_max(counter,n);
			A.remove(max_key);
			A.print();
			counter[max_key]=0;
			flag[max_key] =1;
			A.put(memblock,addr);
		}

		else
		  {
			A.put(memblock,addr);
			flag[A.get_index(memblock)] =1;
		  }        

		
		
		for (int i = 0; i< n; ++i)
		{
			if(flag[i]!=0) 
			   counter[i]++;
 		}

 		counter[A.get_index(memblock)] = 0;
		
		A.print();

		cout<<"Counter list : "<<endl;
		cout<<"Cacheblock \t Counter"<<endl;
		for (int i = 0; i <n; ++i)
		{
			cout<<i<<"\t\t"<<counter[i]<<endl;
		}
	}
	return 0;
}