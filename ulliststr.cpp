#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0;
}

ULListStr::~ULListStr()
{
  clear();
}

bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

// WRITE YOUR CODE HERE
void ULListStr::push_front(const std::string& val)
{ 

  //If the list is empty, create new node 
  if (size_ == 0)
  { 
    Item* newItem = new ULListStr::Item; 
    newItem->first = 9; 
    newItem->last = 10;
    newItem->val[9] = val; 
    newItem->prev = nullptr; 
    newItem->next = nullptr; 
    head_ = newItem; 
    tail_ = newItem; 
  }

  //If the current node has space at the front
  else if (head_->first > 0) { 
    --head_->first; 
    head_->val[head_->first] = val;  
  }

  //If the current node is full, create a new head node
  else if (head_->first == 0) {
    Item* newItem = new ULListStr::Item; 
    newItem->first = 9; 
    newItem->last = 10;
    newItem->next = head_;  
    newItem->prev = nullptr; 
    head_->prev = newItem; 
    head_ = newItem; 
    head_->val[9] = val; 
  
  }

  size_++;
  
}

void ULListStr::push_back(const std::string& val) 
{
  // If list is empty, create a new node
 if (size_ == 0)
  { 
    Item* newItem = new ULListStr::Item; 
    newItem->first = 0; 
    newItem->last = 1;
    newItem->val[0] = val; 
    newItem->prev = nullptr; 
    newItem->next = nullptr; 
    head_ = newItem; 
    tail_ = newItem; 
  }

  // If the current node has space at the end, add the value to the list
  else if (tail_->last < 10) { 
    tail_->val[tail_->last] = val;  
    tail_->last++;  
  }

  //If the current node is full, create a new tail node 
  else if (tail_->last == 10) {
    Item* newItem = new ULListStr::Item; 
    newItem->first = 0; 
    newItem->last = 1;
    newItem->prev = tail_;  
    newItem->next = nullptr; 
    tail_->next = newItem; 
    tail_ = newItem; 
    tail_->val[0] = val;  
     
  }
  size_++;

}

void ULListStr::pop_back()
{
  if (size_ == 0) { 
    return; 
  }
  --tail_->last; 
  --size_; 

  if (tail_->first == tail_->last) { 
    Item* temp = tail_; 
    tail_ = tail_->prev; 
    if (tail_ != nullptr) { 
      tail_->next = nullptr; 
    }
    else { 
      head_ = nullptr; 
    }
    delete temp; 
  }

}

void ULListStr::pop_front()
{
  if (size_ == 0) { 
    return; 
  }
  ++head_->first; 
  --size_; 

  if (head_->first == head_->last) { 
    Item* temp = head_; 
    head_ = head_->next; 
    if (head_ != nullptr) { 
      head_->prev = nullptr; 
    }
    else {
      tail_ = nullptr; 
    }
     delete temp; 
  }

}

std::string const & ULListStr::back() const{
  if (size_ == 0) {
    return nullptr; 
  }

  return tail_->val[tail_->last-1]; 
}

  
std::string const & ULListStr::front() const {
  if (size_ == 0) {
    return nullptr; 
  }

  return head_->val[head_->first]; 
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
  Item* currItem = head_; 
  
  if (size_ == 0 || loc >= size_) { 
    return nullptr; 
  }
  
  while (currItem != nullptr) {
    size_t count = currItem->last - currItem->first; 

    if (loc < count) { 
      return &currItem->val[currItem->first + loc]; 
    }

    loc -= count; 
    currItem = currItem->next; 
  }

  return nullptr; 
}



void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}
