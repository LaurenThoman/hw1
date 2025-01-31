#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
  head_ = nullptr;
  tail_ = nullptr;
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
std::string* ULListStr::getValAtLoc(size_t loc) const{
  if(loc >= size_){
    return nullptr;
  }
  Item* curr = head_;
  size_t i = loc;

  while(curr != nullptr){
    size_t count = curr->last - curr->first;
    if(i < count){
      return &curr->val[curr->first + i];
    }
    i -= count;
    curr = curr->next;
  }
  return nullptr;
}

std::string const & ULListStr::front() const{
  if(empty()){
    throw std::out_of_range("empty list");
  }
  return head_->val[head_->first];

}

std::string const & ULListStr::back() const{
  if(empty()){
    throw std::out_of_range("empty list");
  }
  return tail_->val[tail_->last -1];
}

void ULListStr::push_back(const std::string& val){
  if(!tail_ || tail_->last == ARRSIZE){
    Item* newItem = new Item();
    newItem->first = 0;
    newItem->last = 0;
    newItem->next = nullptr;
    newItem->prev = tail_;
    if(tail_){
      tail_->next = newItem;
    }
    tail_ = newItem;
    if(!head_){
      head_ = newItem;
    }
  }
  tail_->val[tail_->last++] = val;
  size_++;
}


void ULListStr::push_front(const std::string& val){
  if(!head_ || head_->first == 0){
    Item* newItem = new Item();
    newItem->first = ARRSIZE;
    newItem->last = ARRSIZE;
    newItem->next = head_;
    newItem->prev = nullptr;
    if(head_) {
      head_->prev = newItem;
    }
    head_ = newItem;
    if(!tail_ ){
      tail_ = newItem;
    }
  }
  head_->val[--head_->first] = val;
  size_++;
}

void ULListStr::pop_back(){
  if(empty()){
    return;
  }
  tail_->last--;
  size_--;

  if(tail_->first == tail_->last){
    Item* temp = tail_;
    tail_ = tail_->prev;
    if(tail_){
      tail_->next = nullptr;
    } else{
      head_ = nullptr;
    }
    delete temp;
  }
}

void ULListStr::pop_front(){
  if(empty()){
    return;
  }
  head_->first++;
  size_--;

  if(head_->first == head_->last){
    Item* temp = head_;
    head_ = head_->next;
    if(head_){
      head_->prev = nullptr;
    } else{
      tail_ = nullptr;
    }
    delete temp;
  }
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
