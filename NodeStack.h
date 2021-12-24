//
// Created by Ivan on 16.11.21.
//

#ifndef LABA7__NODESTACK_H_
#define LABA7__NODESTACK_H_

template<typename T>
class StackOnList;

template<typename T>
struct NodeStack{
public:
    T value;
    NodeStack(){}
    NodeStack(const T& new_value){
        value = new_value;
        next = nullptr;
    }

private:
    NodeStack* next;
    friend class StackOnList<T>;
};



#endif //LABA7__NODESTACK_H_
