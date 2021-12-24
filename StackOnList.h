//
// Created by Ivan on 16.11.21.
//

#ifndef LABA7__STACKONLIST_H_
#define LABA7__STACKONLIST_H_
#include <cstdlib>
#include <initializer_list>

template<typename T>
class StackOnList{

    NodeStack<T>* top;
 public:

    StackOnList();
    StackOnList(std::initializer_list<T> list);
    StackOnList(StackOnList<T> & orig_st);
    StackOnList(StackOnList<T>&& orig_st);
    StackOnList<T>& operator=(StackOnList<T> const& orig_st);
    StackOnList<T>& operator=(StackOnList<T>&& orig_st);
    size_t Size();
    bool IsEmpty();
    void Push( T value);
    NodeStack<T>* Top();
    T TopValue();
    const NodeStack<T>* Top() const;
    friend bool operator== ( StackOnList<T> st1, StackOnList<T> st2);
    friend bool operator!= ( StackOnList<T> st1, StackOnList<T> st2);
    void Pop();
    void Clear();

};

template<typename T>
void StackOnList<T>::Clear(){

    NodeStack<T> *to_delete;
    while (this->Size() != 0) {
        to_delete = top;
        top = top->next;
        delete to_delete;
    }

}

template<typename T>
void ClearBeforeStack(){

}

template<typename T>
StackOnList<T>::StackOnList() {
    top = nullptr;
}

template<typename T>
StackOnList<T>::StackOnList(std::initializer_list<T> list) {
    top = nullptr;
    size_t n = list.size();
    for (auto& tmp : list) {
        Push(tmp);
    }
}

template<typename T>
bool StackOnList<T>::IsEmpty(){
    if(top == nullptr) {
        return true;
    } else{
        return false;
    }
}

template<typename T>
size_t StackOnList<T>::Size() {
  NodeStack<T>* tmp = top;
  size_t size = 0;
  while (tmp != nullptr){
    size++;
    tmp = tmp -> next;
  }
  return size;
}

template<typename T>
T StackOnList<T>::TopValue(){
    if(top == nullptr){
        return NULL;
    }
    return  top->value;
}

template<typename T>
NodeStack<T>* StackOnList<T>::Top() {
  return  top;
}

template<typename T>
const NodeStack<T>* StackOnList<T>::Top() const {
    const NodeStack<T> *tmp = top;
    return  tmp;
}

template <typename T>
void StackOnList<T>::Push( T value){
  auto* tmp = new NodeStack<T>();
  tmp -> value = value;
  tmp -> next = top;
  top = tmp;
}
template <typename T>
void StackOnList<T>::Pop(){
    if(top == nullptr){
        return;
    }
    NodeStack<T>* to_delete = top;
    top = top->next;
    delete to_delete;
}
template<typename T>
bool operator== (StackOnList<T> st1, StackOnList<T> st2){
    if(st1.Size() != st2.Size()){
        return false;
    }
    NodeStack<T>* tmp1 = st1.top;
    NodeStack<T>* tmp2 = st2.top;
    while (tmp1 != nullptr){
        if(tmp1->value != tmp2->value){
            return false;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }
    return true;
}

template<typename T>
bool operator!= (StackOnList<T> st1, StackOnList<T> st2){
    return !(st1 == st2);
}
template<typename T>
StackOnList<T>::StackOnList(StackOnList<T>& orig_st) {
    StackOnList<T> tmp_st = StackOnList<T>();
    StackOnList<T> copy_st = StackOnList<T>();
    NodeStack<T>* current_node;
    current_node = orig_st.Top();

    while (current_node != nullptr){
        tmp_st.Push(current_node->value);
        current_node = current_node->next;
    }

    current_node = tmp_st.Top();
    while (current_node != nullptr) {
        copy_st.Push(current_node->value);
        current_node = current_node->next;
    }
    top = copy_st.Top();

}

template<typename T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList<T> const& orig_st) {

    StackOnList<T> tmp_st = StackOnList<T>();
    StackOnList<T> copy_st = StackOnList<T>();
    NodeStack<T>* current_node;
    current_node = orig_st.Top();
    //reversed original stack:
    while (current_node != nullptr) {
        tmp_st.Push(current_node->value);
        current_node = current_node->next;
    }
    //coped original stack with tmp reversed stack:
    current_node = tmp_st.Top();
    while (current_node != nullptr) {
        copy_st.Push(current_node->value);
        current_node = current_node->next;
    }
    top = copy_st.Top();
    tmp_st.Clear();
    delete tmp_st.top;
    copy_st.Clear();
    delete copy_st.top;
    return *this;
}

template<typename T>
StackOnList<T>::StackOnList(StackOnList<T>&& orig_st){
    StackOnList<T> tmp_st = StackOnList<T>();
    StackOnList<T> copy_st = StackOnList<T>();
    NodeStack<T>* current_node;
    current_node = orig_st.Top();

    while (current_node != nullptr){
        tmp_st.Push(current_node->value);
        current_node = current_node->next;
    }

    current_node = tmp_st.Top();
    while (current_node != nullptr) {
        copy_st.Push(current_node->value);
        current_node = current_node->next;
    }
    orig_st.Clear();
    top = copy_st.Top();
}

template<typename T>
StackOnList<T>& StackOnList<T>::operator=(StackOnList<T>&& orig_st){
    StackOnList<T> tmp_st = StackOnList<T>();
    StackOnList<T> copy_st = StackOnList<T>();
    NodeStack<T>* current_node;
    current_node = orig_st.Top();

    while (current_node != nullptr){
        tmp_st.Push(current_node->value);
        current_node = current_node->next;
    }

    current_node = tmp_st.Top();
    while (current_node != nullptr) {
        copy_st.Push(current_node->value);
        current_node = current_node->next;
    }
    orig_st.Clear();
    top = copy_st.Top();
    return *this;
}


#endif //LABA7__STACKONLIST_H_
