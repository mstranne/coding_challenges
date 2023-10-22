#include "DataStructures/include/linear/linked_list.h"


void LinkedList::Add(int val){
    Node* curr = m_head;
    while(curr->next != nullptr){
        curr = curr->next;
    }

    Node* newNode = new Node();
    newNode->value = val;
    curr->next = newNode;
    size++; 
}

// removes all with val
bool LinkedList::Remove(int val){
    if(m_head == nullptr)
        return false;

    Node* curr = m_head;
    while(curr->next != nullptr){
        if(curr->value == val){
            Node* tmp = curr->next;
            if(curr == m_head)
                m_head = tmp;
            delete curr;
            size--;
            curr = tmp;                    
        } else {
            curr = curr->next;
        }
    }
}

bool LinkedList::RemoveIdx(int idx){
    
}

int LinkedList::Get(int idx){
    Node* curr = m_head;
    while(idx > 0 && curr->next != nullptr){
        curr = curr->next;
        idx--;
    }

    if(idx == 0) {
        return curr->value;
    }
    return -1;
}