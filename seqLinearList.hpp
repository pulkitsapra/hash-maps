//PULKIT SAPRA
//B15123
#ifndef SEQLINEARLIST_HPP
#define SEQLINEARLIST_HPP
#include <iostream>

using namespace std;

template<class Item>
class LinearList{
	private:
		int MaxSize;
		Item *element;    // 1D dynamic array
        int len;
	public:
		/* Default constructor. 
		 * Should create an empty list that not contain any elements*/
		LinearList()
		{
			MaxSize = 0;
			element = new Item[MaxSize];
		}

		void set_capacity(int cap)
		{
			MaxSize = cap ;
			element = new Item[MaxSize];
			for(int i=0; i<cap;++i){
				element[i]=Item();
			}
			
		}

		/* This constructor should create a list containing MaxSize elements. You can intialize the elements with any values.*/
		LinearList(const int& MaxListSize)
		{
			MaxSize = MaxListSize;
			element = new Item[MaxSize]; 
			len = 0;
		}

		/* Destructor. 
		 * Must free all the memory contained by the list */
		~LinearList()
		{
			delete[] element; 
		}

		/* Indexing operator.
     		 * It should behave the same way array indexing does. i.e,
     		 * LinearList L;
     		 * L[0] should refer to the first element;
     		 * L[1] to the second element and so on.
     		 * */
		Item& operator[](const int& i) //return i'th element of list
		{
			return element[i];
		}
		
		/* Returns true if the list is empty, false otherwise.
     		 * */
		bool isEmpty()
		{
			if(len==0)
				return true;
		
			return false;
		}

		/* Returns the actual length (number of elements) in the list.
     		 * */
		int  length()
		{
            return len;
		}

		/* Returns the maximum size of the list.
     		 * */
		int  maxSize()
		{
			return MaxSize;
		}

		/* Returns the k-th element of the list. 
		 * */
		Item  returnListElement(const int k)
		{
		   return element[k];
		}

		/* Set x to the k-th element and 
		 * return true if k-th element is present otherwise return false.
		 * */
		bool find(const int k, Item& x)
		{
            if(k>=len || k<0)
            	return false;
            else
            {	
            	x = element[k-1];
            	return true;
            }	
		}

		/* Search for x and 
		 * return the position if found, else return 0.
		 * */
		int  search(Item& x)
		{
			for(int i=0;i<len;++i){
				if(element[i]==x)
					return i+1;
			}
           
            return 0;
		}

		/* Set x to the k-th element and delete that k-th element.
		 * */
		void  deleteElement(const int  k, Item& x)
		{
			x = element[k-1];
			for(int i=k-1; i<len-1;++i)
				element[i] = element[i+1];

			len--;
				
		}

		/*
		 *  Resizing the list
		 */ 
		LinearList resize(LinearList old)
		{
			LinearList<int>L;
			L.set_capacity(2*old.length());

		}

		/* Insert x after k-th element.
		 * */
		void insert( Item& x,const int  k)
		{
			
			element[k] = x;
			len++;

		}
};


#endif