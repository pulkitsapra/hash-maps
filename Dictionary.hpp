/*
 * Dictionary.hpp
 */

#ifndef DICTIONARY_HPP_
#define DICTIONARY_HPP_
#include <sstream>
#include <string>
#include <iostream>

template<class Key, class Value>
class Dictionary;

namespace cs202{

template<class Key, class Value>
class Node
{
    friend Dictionary<Key,Value>;

    private:
        Key _key;
        Value _value;

    public:

        void set_pair(Key key, Value val)
        {
            _key = key;
            _value   = val;
        }

        Key get_key()
        {
            return _key;
        }

        Value get_value()
        {
            return _value;
        }

        Value& ref_val(){

            return _value;
        }

};


template<class Key, class Value>
class Dictionary
{
            
    public:
        int hash(Key key, int size){
            // stringstream stream;
            // stream << key;
            // string t = stream.str();
            // int seed = 251;
            // unsigned long hash = 0;
            // for(int i = 0; i < t.size(); ++i) {
            //     hash = hash * seed + t[i];
            // }
            
            return (key % size);
          }

         int double_hash(int key){
             return (key % 263) + 1;
         } 
        


      
    /*
     * Destructor. Should release all the memory acquired by the dictionary.
     */
	   virtual ~Dictionary(){

        };
    /*
     * Function : has
     * Returns true if the dictionay contains the key
     * false otherwise. It is search operation
     */
	   virtual bool has(const Key& key) = 0;
    /*
     * Function : remove
     * Removes the given key and the corresponding value from the Dictionary if the key is in the dictionary.
     * Does nothing otherwise.
     */
	   virtual void remove(const Key& key) = 0;
    /*
     * Function : get
     * Returns the value associated with the given key.
     * Raises an exception if the key does'nt exist in the dictionary.
     */
	   virtual Value get(const Key& key) = 0;
    /*
     * Function : put
     * If the key does'nt exist in the dictionary, then insert the given key and value in the dictionary.
     * Otherwise change the value associated with the key to the given value.
     */
	   virtual void put(const Key& key, const Value& value) = 0;

};

}
#endif /* DICTIONARY_HPP_ */
