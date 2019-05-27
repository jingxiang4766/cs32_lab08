#include <iostream>
#include <algorithm>
#include "SimpleList"
using namespace std;

SimpleList::SimpleList(){
  numElements = 0;
  elements = new T[10];
}

SimpleList::~SimpleList(){
  delete[] elements;
}

T SimpleList::at(int index) const throw(InvalidIndexException){
  if (elements[index] == 0) throw InvalidIndexException();
  return elements[index];
}

bool SimpleList::empty() const{
  for (int i = 0; i < 10; i++){
    if (elements[index] != 0) return false;
  }
  return true;
}

T SimpleList::first() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[0];
}

T SimpleList::last() const throw (EmptyListException){
  if (this->empty()) throw EmptyListException();
  return elements[9];
}

int SimpleList::getNumElements() const{
  int count = 0;
  for (int i = 0; i < 10; i++){
    if (elements[i] != 0) count++;
  }
  return count;
}

void SimpleList::insert(T item) throw (FullListException){
  bool IsFull = True;
  for (int i = 0; i < 10; i++){
    if (elements[i] == 0) {IsFull = False; elements[i] = item; break;}
  }
  if (IsFull) throw FullListException();
}

void SimpleList::remove(int index) throw (InvalidIndexException, EmptyListException){
    if (this->empty()) throw EmptyListException();
    if (elements[index] == 0) throw InvalidIndexException();
    elements[index] = 0;
    for (int i = index; i < 9; i++){
      elements[i] = elements[i+1];
    }
    elements[10] = 0;
}
