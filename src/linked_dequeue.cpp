#include "linked_dequeue.hpp"

#include <stdexcept>  // logic_error

namespace itis {

void LinkedDequeue::Enqueue(Element e) {
    auto node = new DoublyNode(e, back_, nullptr);
    if (front_ == nullptr){
        front_ = node;
        back_ = node;
    }else{
        back_->next = node;
        back_ = node;
    }
    size_++;
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::EnqueueFront(Element e) {
    auto node = new DoublyNode(e, nullptr, front_);
    if(front_ == nullptr){
        front_ = node;
        back_ = node;
    } else{
        front_->previous = node;
        front_ = node;
    }
    size_++;
    // TODO: напишите здесь свой код ...
}

void LinkedDequeue::Dequeue() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  if (size_ == 1){
      auto curr = front_;
      front_ = nullptr;
      back_ = front_;
      delete [] curr;
      size_ = 0;
  }else{
      auto curr = front_;
      front_ = front_->next;
      delete [] curr;
      size_--;
  }
  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::DequeueBack() {
  if (size_ == 0) {
    throw std::logic_error("cannot not dequeue from empty queue");
  }
  if (size_ == 1){
      auto curr = front_;
      front_ = nullptr;
      back_ = front_;
      delete [] curr;
  }else{
      auto curr = back_;
      back_ = back_->previous;
      delete [] curr;
  }
  size_--;

  // TODO: напишите здесь свой код ...
}

void LinkedDequeue::Clear() {
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

LinkedDequeue::~LinkedDequeue() {
  Clear();
}

std::optional<Element> LinkedDequeue::front() const {
  return front_ == nullptr ? std::nullopt : std::make_optional(front_->data);
}

std::optional<Element> LinkedDequeue::back() const {
  return back_ == nullptr ? std::nullopt : std::make_optional(back_->data);
}

bool LinkedDequeue::IsEmpty() const {
  return size_ == 0;
}

int LinkedDequeue::size() const {
  return size_;
}

// === НЕОБХОДИМО ДЛЯ ТЕСТИРОВАНИЯ ===

std::ostream &operator<<(std::ostream &os, const LinkedDequeue &queue) {
  os << "size: " << queue.size_ << '\n';
  for (auto current_node = queue.front_; current_node != nullptr; current_node = current_node->previous) {
    if (current_node == queue.front_) os << "[FRONT] ";
    if (current_node == queue.back_) os << "[BACK] ";
    os << enum2str(current_node->data) << '\n';
  }
  return os;
}

}  // namespace itis
