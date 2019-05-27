#include <iostream>
#include <algorithm>
#include "SimpleList.h"
using namespace std;

template <class T>
SimpleList<T>::SimpleList(){
  numElements = 0;
  elements = new T[10];
}

template <class T>
SimpleList<T>::~SimpleList(){
  delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw(InvalidIndexException){
  if (!elements[index]) throw InvalidIndexException();
  return elements[index];
}

template <class T>
bool SimpleList<T>::empty() const{
  for (int i = 0; i < 10; i++){
    if (elements[i]) return false;
  }
  return true;
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[0];
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[9];
}

template <class T>
int SimpleList<T>::getNumElements() const{
  // int count = 0;
  // for (int i = 0; i < 10; i++){
  //   if (elements[i]) count++;
  // }
  // return count;
  return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException){
  bool IsFull = true;
  for (int i = 0; i < 10; i++){
    if (!elements[i]) {IsFull = false; elements[i] = item; break;}
  }
  if (IsFull) throw FullListException();
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException){
    if (this->empty()) throw EmptyListException();
    if (!elements[index]) throw InvalidIndexException();
    elements[index] = 0;
    for (int i = index; i < 9; i++){
      elements[i] = elements[i+1];
    }
    elements[10] = 0;
}
