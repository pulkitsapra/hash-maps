/*
 * list.hpp
 *
 * functionality of a singly linked-list
 *
 * define your methods in coherence with the following
 * function signatures
 * 
 * 
 */

#ifndef LIST_HPP
#define LIST_HPP 1

#include <iostream>

using namespace std;

namespace cs202
{
  template<class T>
  class LinkedList;

  template<class T>
  class Node_linkedList {
    friend class LinkedList<T>;
    
    private:
      T _data;
      Node_linkedList* _link;

    public:
      /*
       * Primary constructor.
       * creates an empty node.
       * creates Link to NULL.
       */
      Node_linkedList();

      /*
       * Secondary constructor.
       * sets the value of node to val.
       * links to NULL.
       */
      Node_linkedList(T val);

      /*
       * Secondary constructor.
       * sets value of node to val.
       * links to link.
       */
      Node_linkedList(T val, Node_linkedList* link);

      /*
       * Returns value stored in node.
       */
      T& data();

      /*
       * Returns link to the next element stored.
       */
      Node_linkedList* link();

      /*
       * Sets link to the link.
       */
      void set_link(Node_linkedList* link);

      /*
       * Sets data to the val.
       */
      void set_data(T val);
  };

  template<class T>
  Node_linkedList<T>::Node_linkedList() {
    _link = NULL;
  }

  template<class T>
  Node_linkedList<T>::Node_linkedList(T val) {
    _data = val;
    _link = NULL;
  }

  template<class T>
  Node_linkedList<T>::Node_linkedList(T val, Node_linkedList* link) {
    _data = val;
    _link = link;
  }

  template<class T>
  T& Node_linkedList<T>::data() {
    return _data;
  }

  template<class T>
  Node_linkedList<T>* Node_linkedList<T>::link() {
    return _link;
  }

  template<class T>
  void Node_linkedList<T>::set_link(Node_linkedList* link) {
    _link = link;
  }

  template<class T>
  void Node_linkedList<T>::set_data(T val) {
    _data = val;
  }

  template<class T>
  class LinkedList
    {
      private:
        Node_linkedList<T>* _head;
        Node_linkedList<T>* _tail;
        int _size;

      public:
        /*
         * Primary contructor.
         * Should construct an empty list.
         * Size of the created list should be zero.
         */
        LinkedList();
        /*
         * Seondary constructor.
         * Creates a new list which is a copy of the provided list.
         */
        LinkedList(LinkedList<T> & x);
        /*
         * Destructor.
         * Frees all the memory acquired by the list.
         */
        ~LinkedList();
        /*
         * adds value at the end of the list.
         */
        void append(const T& value);
        /*
         * Returns the length of the list.
         */
        inline int length();
        /*
         * Returns a boolean indicating whether the list is empty.
         */
        inline bool empty();
        /*
         * Adds a value to the front of the list.
         */
        void cons(const T& value);
        /*
         * Removes the first occurence of the value from list.
         */
        void remove(const T& x);
        /*
         * Appends the given list x at the end of the current list.
         */
        void append(LinkedList<T>& x);

        /*
         * Returns starting pointer of the list
         */
        Node_linkedList<T>* get_head();

        /*
         * Returns ending pointer of the list
         */
        Node_linkedList<T>* get_tail();

        /*
         * 
         */
        void set_head(Node_linkedList<T>* temp);
    };

    template<class T>
    LinkedList<T>::LinkedList() {
        _head = NULL;
        _tail = NULL;
        _size = 0;
    }

    template<class T>
    LinkedList<T>::LinkedList(LinkedList<T> & x) {
        Node_linkedList<T>* traverse = x.get_head();
        _head = new Node_linkedList<T>;
        _head -> set_data(traverse -> data());
        _tail = _head;
        traverse = traverse -> link();
        _size++;
        while(traverse != NULL) {
            Node_linkedList<T>* ptr = new Node_linkedList<T>;
            ptr -> set_data(traverse -> data());
            _tail -> set_link(ptr);
            _tail = _tail -> link();
            traverse = traverse -> link();
            _size++;
        }
    }

    template<class T>
    void LinkedList<T>::append(const T& value) {
        _size++;
        Node_linkedList<T>* new_node = new Node_linkedList<T>;
        new_node -> _data = value;
        if(_tail == NULL) {
            _tail = new_node;
            _head = new_node;
            return;
        }
        _tail -> _link = new_node;
        _tail = new_node;
    }

    template<class T>
    inline int LinkedList<T>::length() {
        return _size;
    }

    template<class T>
    inline bool LinkedList<T>::empty() {
        return (_size == 0);
    }

    template<class T>
    void LinkedList<T>::cons(const T& value) {
        _size++;
        Node_linkedList<T>* new_node = new Node_linkedList<T>;
        new_node -> _data = value;
        new_node -> _link = _head;
        _head = new_node;
        if(_tail == NULL)
            _tail = _head;
    }

    template<class T>
    void LinkedList<T>::remove(const T& x) {
        Node_linkedList<T>* trav = _head;
        if(_head -> _data == x) {
            _head = _head -> _link;
            delete trav;
            _size--;
            return;
        }
        while(trav -> _link != NULL) {
            if(trav -> _link -> _data == x) {
                Node_linkedList<T>* pos = trav -> _link;
                trav -> _link = trav -> _link -> _link;
                delete pos;
                _size--;
                return;
            }
        }
    }

    template<class T>
    void LinkedList<T>::append(LinkedList<T>& x) {
        _size += x.length();
        _tail -> _link = x.get_head();
        _tail = x.get_tail();
        _tail -> _link = NULL;
    }

    template<class T>
    Node_linkedList<T>* LinkedList<T>::get_head() {
        return _head;
    }

    template<class T>
    Node_linkedList<T>* LinkedList<T>::get_tail() {
        return _tail;
    }

    template<class T>
    LinkedList<T>::~LinkedList() {
        Node_linkedList<T>* trav = _head;
        while(_head != NULL) {
            _head = _head -> _link;
            delete trav;
            trav = _head;
        }
    }

    template<class T>
    void LinkedList<T>::set_head(Node_linkedList<T>* temp) {
      _head = temp;
    }
}

#endif