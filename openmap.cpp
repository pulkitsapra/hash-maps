#include <iostream>
#include <stdlib.h>
#include "seqLinearList.hpp"
#include "OpenMap.hpp"
#include "DoubleHashMap.hpp"
#include "Dictionary.hpp"

using namespace std; 
using namespace cs202;

int main()
{
	OpenMap<int,int> ht;
	
	// ht.put(7,98);
	// ht.put(2,56);
	// ht.put(3,500);
	// ht.put(505,0);
	// ht.put(7,92);
	// ht.put(10,57);
	// ht.print();
 	// ht.remove(7);
	// ht.print();
	// cout<<ht[7];
	//  ht.print();


	

	while(1)
	{
		cout<<"\n1: Insert into hash table "<<endl;
		cout<<"2: Delete from hash table "<<endl;
		cout<<"3: Get value for a given key"<<endl;
		cout<<"4: Check availability of a key"<<endl;
		cout<<"5: Size of hash map"<<endl;
		cout<<"6: Print hash table"<<endl;
        cout<<"7: Exit"<<endl;
   
        int choice,key,value;
        
        cin>>choice;


        switch(choice)
        {
        	case 1: cout<<"\nEnter Key:  ";
        			cin>>key;
        			cout<<"Enter Value:  ";
        			cin>>value;
        			ht.put(key,value);
        			break;

        	case 2: cout<<"\nEnter Key:  ";
        			cin>>key;
        			ht.remove(key);
        			break;

        	case 3: cout<<"\nEnter Key:  ";
        			cin>>key;
        			cout<<"The value for given key is :"<<ht.get(key);	
        			break;

        	case 4: cout<<"\nEnter Key:  ";
        			cin>>key;
        			ht.has(key);
        			break;

        	case 5: cout<<"\nSize is :"<<ht.get_size();
        			break;

        	
            case 6: ht.print();
                    break;

        	case 7: exit(0);


        	default: cout<<"\nWrong input! Enter again."<<endl;  
        }
	
	}



	return 0;
}