#include "linked_queue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedQueue::Enqueue(Element e) {
    auto node = new SinglyNode(e, nullptr);
    if(front_ == nullptr){
        front_ =node;
        back_ = node;
    } else{
        back_->next = node;
        back_ = node;
    }
    size_++;

  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("could not dequeue from empty queue");
  }
  if (size_ == 1){
      auto curr = front_;
      front_ = nullptr;
      back_ = nullptr;
      delete [] curr;
  }else{
      auto curr = front_;
      front_ = front_->next;
      delete [] curr;
  }
    size_--;

  // TODO: напишите здесь свой код ...
}

void LinkedQueue::Clear() {
    if (size_ == 0){
        return;
    }
    auto curr = front_;
    for(int i = 0; i < size_; i++){
        front_ = front_->next;
        curr->next = nullptr;
        delete [] curr;
        curr = front_;
    }
    back_ = front_;
    size_ = 0;
  // TODO: напишите здесь свой код ...
}

// === РЕАЛИЗОВАНО ===

LinkedQueue::~LinkedQueue() {
  Clear();
}

std::optional<Element> LinkedQueue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedQueue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedQueue::IsEmpty() const {
  return size_ == 0;
}
int LinkedQueue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedQueue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->next) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis