/*
 * DoubleHashMap.hpp
 *
 * This is an interface for a hash table using Double Hashing.
 */

#ifndef DOUBLEHASHMAP_HPP_
#define DOUBLEHASHMAP_HPP_

#include "Dictionary.hpp"
#include "seqLinearList.hpp"

#include <iostream>
#define SIZE_DEFAULT 503



namespace cs202
{
template<class Key, class Value>
class DoubleHashMap  : public Dictionary<Key,Value>
{
    void rehash();

private:
    LinearList< Node<Key, Value> > _list;
    int size;
    LinearList<int> status; 
    /*
     * Function rehash:
     * Resizes the has table to the next convenient size.
     * Called when all the slots are full and a new element needs to be inserted.
     */
	
public:
    /*
     * Constructor: DoubleHashMap
     * Creates a Double Hash Hash Table with some default size.
     * NOTE: Please try to ensure that the size is a prime number for better performance.
     */
	DoubleHashMap(){
        _list.set_capacity(SIZE_DEFAULT);
        status.set_capacity(SIZE_DEFAULT);
        size = 0; 

    }
    /*
     * Constructor:DoubleHashMap
     * Creates an empty Double Hash Map with the ability to hold atleast num Key value pairs.
     */
	DoubleHashMap(const int& num);
    /*
     * Constructor: Double Hash Map
     * Creates a new Hash Table which is the exact copy of the given hash table.
     **/
	DoubleHashMap(DoubleHashMap<Key, Value>& ht);
    /*
     * Destructor
     * Deletes the memory acquired by the given Hash Map.
     */
	~DoubleHashMap(){
        
    }
    /*
     * A convenience wrapper operator.
     * Returns a reference to the value corresponding to the given key.
     * If the key does'nt exist, then inserts the key in the table,
     * with the default value of the Value type.
     * This should enable you to write code like this:
     * DoubleHashMap<int,int> ht;
     * ht[1] = 2;
     * ht[1] = 4;
     * ht[2] = 3;
     */
     void print()
    {
        for(int i=0; i<SIZE_DEFAULT;++i)
            if(status[i]==1)
                cout<<"Index :"<< i <<" Key: "<<_list[i].get_key()<<"    "<<"Value: "<<_list[i].get_value()<<endl;
              
    }


	Value& operator[](const Key& key)
    {
         int index = this -> hash(key, SIZE_DEFAULT);
          int offset = this -> double_hash(index);
         while(status[index] != 0) {
            if(status[index]==2)
                break;
            if(status[index] == 1) {
                if(_list[index].get_key() == key) {
                    return _list[index].ref_val();
                }
            }
            index=index+offset;
            index %= SIZE_DEFAULT;
        }

        status[index] = 1;
        _list[index].set_pair(key, Value());
        size++;
        return _list[index].ref_val();
    }

    int get_size(){                                      //returns size of hash map
        return size;
    }

    bool has(const Key& key){
        
        int index = this->hash(key,SIZE_DEFAULT);
         int offset = this -> double_hash(index);
        while(status[index]!=0)
        {
            if(status[index]==1 &&( _list[index].get_key()==key))
                return true;

            index=index+offset;
            index = index%SIZE_DEFAULT;
        }

        return false;
     }


    void remove(const Key& key)
      {
        int index = this->hash(key,SIZE_DEFAULT);
         int offset = this -> double_hash(index);
        while(status[index]!=0)
        {
            if(status[index]==1 && _list[index].get_key()==key)
                {
                    status[index] = 2;
                    size--;
                    return;
                }

            index=index+offset;
            index = index%SIZE_DEFAULT;    

         }
       }

    Value get(const Key& key) {

        int index = this -> hash(key, SIZE_DEFAULT);
         int offset = this -> double_hash(index);
        while(status[index] != 0) {
            if(status[index] == 1) {
                if(_list[index].get_key() == key) {
                    return _list[index].get_value();
                }
            }
            index=index+offset;
            index %= SIZE_DEFAULT;
        }
        return Value();
    }

    void put(const Key& key, const Value& value) 
    {
        int index = this -> hash(key, SIZE_DEFAULT);
         int offset = this -> double_hash(index);
        cout<<index<<endl;
        Node<Key, Value> new_node;
        new_node.set_pair(key,value);
        while(status[index] == 1) {
            if(_list[index].get_key() == key) {
                _list[index].set_pair(key, value);
                return;
            }
            index=index+offset;
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