#include <cstdlib>
#include <iostream>
#include "LinkedList.hpp"
#include "Dictionary.hpp"
#include "ChainedMap.hpp"
#include "LinkedList.hpp"
#include <limits>
#include <exception>

using namespace std;

int main()
{

	int no;
  //  cout<<"Enter the size of the dictionary : ";
  //  cin>>no;
    cs202::ChainedMap<int,int> A;
   	int key, value;
    int choice;

    while (1)
    {
        cout<<"Enter your choice: "<<endl;
        cout<<"----------------------"<<endl;
        cout<<"1.Insert element into the table"<<endl;
        cout<<"2.Search element from the key"<<endl;
        cout<<"3.Delete element of a key"<<endl;
        cout<<"4.Print the table"<<endl;
        cout<<"5.Current length of the table"<<endl;
        cout<<"6.Exit"<<endl;
        
        cin>>choice;
        switch(choice)
        {
        	case 1:    {cout<<"Enter element to be inserted: ";
	                   cin>>value;
    	               cout<<"Enter key at which element to be inserted";
        	           cin>>key;
            	       A.put(key,value);
            	       break;}
                      
            case 2:    {cout<<"Enter key of the element to be searched: ";
            	       cin>>key;
                	   cout<<"Element at key "<<key<<" : ";
                       try
                    	 {value = A.get(key);}
                    	
                    	catch(int error)
                    	 {cout<<"there is no element on such key"<<endl;}
                    	
                    	cout<<value<<endl;
                    	break;}
		        	   

            case 3:    {cout<<"Enter key of the element to be deleted: ";
        	           cin>>key;
            	       A.remove(key);
                       break;}
        	

        	case 4:    {A.print();
        		       break;}
        	
            case 5:    {cout<<"The current length of the table : "<<A.get_size()<<endl;
        		       break;}
        	
            case 6:   { exit(0);
                       break;}
         
        }
    }
     

	return 0;
}

