/*
 * OpenMap.hpp
 *
 *This is a Hash Table interface using Linear Probing
 */

#ifndef OPENMAP_HPP_
#define OPENMAP_HPP_

#include "Dictionary.hpp"
#include "seqLinearList.hpp"

#include <iostream>
#define SIZE_DEFAULT 503

int b=0;

namespace cs202
{
template<class Key, class Value>
class OpenMap : public Dictionary<Key, Value>
{
   
private:
    LinearList< Node<Key, Value> > _list;
    int size;
    int capacity;
    LinearList<int> status;                          

    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	void rehash();
public:
    /*
     * Constructor: OpenMap
     * Creates a Open Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	OpenMap()
    {
        _list.set_capacity(SIZE_DEFAULT);
        status.set_capacity(SIZE_DEFAULT);
        capacity = SIZE_DEFAULT;
        size = 0;
    }
    /*
     * Constructor:OpenMap
     * Creates an empty Open Map with the ability to hold atleast num Key value pairs.
     */
	OpenMap(const int& num){

        _list.set_capacity(num);
        status.set_capacity(num);
        size = 0; 
        capacity = num;
    }

    /*
     * Constructor: Open Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	OpenMap(OpenMap<Key, Value>& ht){

    }
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~OpenMap(){
        
    }
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * OpenMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
   int get_index(const Key& key){
        
        int index = this->hash(key,capacity);
        while(status[index]!=0)
        {
            if((status[index]==1) &&( _list[index].get_key()==key))
                return index;

            index++;
            index = index%SIZE_DEFAULT;
        }

        return -1;
     }

    void print()
    {
        for(int i=0; i<capacity;++i)
            if(status[i]==1)
                cout<<"Index :"<< i <<" Key: "<<_list[i].get_key()<<"    "<<"Value: "<<_list[i].get_value()<<endl;
    		  // cout<<status[i]<<" ";
    }
///////////////////////////////////////////////////////////////////////////////////////	

    Value& operator[](const Key& key)
    {
         int index = this -> hash(key, capacity);
         while(status[index] != 0 ) {
         	if(status[index]==2)
         		break;
            else if(status[index] == 1) {
                if(_list[index].get_key() == key) {
                    return _list[index].ref_val();
                }
            }
            index++;
            index %= SIZE_DEFAULT;
        }

        status[index] = 1;
        _list[index].set_pair(key, Value());
        size++;
        return _list[index].ref_val();
    }
////////////////////////////////////////////////////////////////////////////////////////
    
    int get_size(){                                      //returns size of hash map
        return size;
    }
////////////////////////////////////////////////////////////////////////////////////////

    
    int get_capacity(){                                      //returns capacity of hash map
        return capacity;
    }
////////////////////////////////////////////////////////////////////////////////////////
     bool has(const Key& key){
        
        int index = this->hash(key,capacity);
        while(status[index]!=0)
        {
            if(status[index]==1 &&( _list[index].get_key()==key))
                return true;

            index++;
            index = index%SIZE_DEFAULT;
        }

        return false;
     }

////////////////////////////////////////////////////////////////////////////////////////
     void remove(const Key& key)
      {
        int index = this->hash(key,capacity);
        while(status[index]!=0)
        {
            if(status[index]==1 && _list[index].get_key()==key)
                {
                    status[index] = 2;
                    size--;
                    return;
                }

            index++;
            index = index%SIZE_DEFAULT;    

         }
       }
////////////////////////////////////////////////////////////////////////////////////////
/*
 * Get value for the given key
 */
        
////////////////////////////////////////////////////////////////////////////////////////
     Value get(const Key& key) {

        int index = this -> hash(key, capacity);
        while(status[index] != 0) {
            if(status[index] == 1) {
                if(_list[index].get_key() == key) {
                    return _list[index].get_value();
                }
            }
            index++;
            index %= SIZE_DEFAULT;
        }
        return Value();
    }
     
////////////////////////////////////////////////////////////////////////////////////////
     void put(const Key& key, const Value& value) 
     {
        int index = this -> hash(key,capacity);
        Node<Key, Value> new_node;
        new_node.set_pair(key,value);
       
        while(status[index] == 1) {
            if(_list[index].get_key() == key) {
                _list[index].set_pair(key, value);
                return;
            }
            index++;
            index %= SIZE_DEFAULT;
        }
        
        _list.insert(new_node, index);
        int a=1;
        status.insert(a, index);
        size++;
     
      }

   };
}

#endif 