// Jing Su, 6839039

#include <iostream>
#include <array>
#include <algorithm>
#include "SimpleList.h"
using namespace std;

template<class T>
void destroy(T element) {
	// do nothing
}

template <class T>
void destroy(T* element) {
	// delete the pointer type
	delete element;
}

template <class T>
SimpleList<T>::SimpleList(){
  numElements = 0;
  elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList(){
  for(int i = 0; i < numElements; i++){
	 destroy(elements[i]);
  }
  delete[] elements;
  elements = NULL;
}

template <class T>
T SimpleList<T>::at(int index) const throw(InvalidIndexException){
  if (index < 0 || index >= numElements) throw InvalidIndexException();
  return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const{
  return numElements == 0;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[0];
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[numElements-1];
}

template <class T>
int SimpleList<T>::getNumElements() const{
  return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
  if (numElements == 10) throw FullListException();
  elements[numElements] = item;
  numElements++;
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
    if (this->empty()) throw EmptyListException();
    if (index < 0 || index >= numElements) throw InvalidIndexException();
    for (int i = index+1; i < numElements; i++){
      elements[i-1] = elements[i];
    }
    numElements--;
}
