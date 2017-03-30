/*
 * ChainedMap.hpp
 *
 */

#ifndef CHAINEDMAP_HPP_
#define CHAINEDMAP_HPP_
#define SIZE 503
#include "LinkedList.hpp"
#include "Dictionary.hpp"
#include <string>
#include <sstream>
using namespace std;

namespace cs202
{
    template<class Key, class Value>
    class ChainedMap  : public Dictionary<Key,Value>
    {
        /*
         * Function rehash:
         * Resizes the hash table to the next convenient size.
         * Called when all the slots are full and a new element needs to be inserted.
         */
    	void rehash();
    private:
        LinkedList< Node<Key, Value> > *_list;
        int _size;

    public:
        void put(const Key& key, const Value& value);
        Value get(const Key& key);
        void remove(const Key& key);
        bool has(const Key& key);
        int get_size();
        /*
         * Constructor: ChainedMap
         * Creates a Chained Hash Table with some default size.
         * NOTE: Please try to ensure that the size is a prime number for better performance.
         */
    	ChainedMap();
        /*
         * Constructor:ChainedMap
         * Creates an empty Chained Map with the ability to hold atleast num Key value pairs.
         */
    	//ChainedMap(const int& num);
        /*
         * Constructor: Chained Map
         * Creates a new Hash Table which is the exact copy of the given hash table.
         **/
    	//ChainedMap(ChainedMap<Key, Value>& ht);
        /*
         * Destructor
         * Deletes the memory acquired by the given Hash Map.
         */
    	//~ChainedMap();
        /*
         * A convenience wrapper operator.
         * Returns a reference to the value corresponding to the given key.
         * If the key does'nt exist, then inserts the key in the table,
         * with the default value of the Value type.
         * This should enable you to write code like this:
         * ChainedHashMap<int,int> ht;
         * ht[1] = 2;
         * ht[1] = 4;
         * ht[2] = 3;
         */
    	Value& operator[](const Key& key);
    };

    template<class Key, class Value>
    ChainedMap<Key, Value>::ChainedMap() {
        _list = new LinkedList< Node<Key, Value> >[SIZE];
        _size = 0;
    }

    template<class Key, class Value>
    void ChainedMap<Key, Value>::put(const Key& key, const Value& value) {
        int idx = this -> hash(key, SIZE);
        Node<Key, Value> n;
        n.set_pair(key, value);
        Node_linkedList< Node<Key, Value> > *trav;
        trav = _list[idx].get_head();
        while(trav != NULL) {
            if((trav -> data()).get_key() == key) {
                (trav -> data()).set_pair(key, value);
                return;
            }
            trav = trav -> link();
        }
        _list[idx].cons(n);
        _size++;
    }

    template<class Key, class Value>
    Value ChainedMap<Key, Value>::get(const Key& key) {
        int idx = this -> hash(key, SIZE);
        Node_linkedList< Node<Key, Value> >* trav;
        trav = _list[idx].get_head();
        while(trav != NULL) {
            if((trav -> data()).get_key() == key) {
                return (trav -> data()).get_value();
            }
            trav = trav -> link();
        }
        return Value();
    }

    template<class Key, class Value>
    bool ChainedMap<Key, Value>::has(const Key& key) {
        int idx = this -> hash(key, SIZE);
        Node_linkedList< Node<Key, Value> >* trav;
        trav = _list[idx].get_head();
        while(trav != NULL) {
            if((trav -> data()).get_key() == key) {
                return true;
            }
            trav = trav -> link();
        }
        return false;
    }

    template<class Key, class Value>
    void ChainedMap<Key, Value>::remove(const Key& key) {
        if(this -> has(key)) {
            int idx = this -> hash(key, SIZE);
            Node_linkedList< Node<Key, Value> >* trav;
            trav = _list[idx].get_head();
            if((trav -> data()).get_key() == key) {
                _list[idx].set_head(trav -> link());
                delete trav;
                _size--;
                return;
            }
            while(trav -> link() != NULL) {
                if(((trav -> link()) -> data()).get_key() == key) {
                    trav -> set_link(trav -> link() -> link());
                }
                trav = trav -> link();
            }
        }
    }

    template<class Key, class Value>
    int ChainedMap<Key, Value>::get_size() {
        return _size;
    }

}

#endif /* CHAINEDMAP_HPP_ */