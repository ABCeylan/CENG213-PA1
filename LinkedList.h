#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getDummyHead() const;
    Node<T> *getDummyTail() const;
    Node<T> *getActualHead() const;
    Node<T> *getActualTail() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheBeginning(const T &data);
    void insertAtTheEnd(const T &data);
    void insertBeforeGivenNode(const T &data, Node<T> *node);

    void deleteNode(Node<T> *node);
    void deleteNode(const T &data);
    void deleteAllNodes();

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void traverse() const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
    

private: // DO NOT CHANGE THIS PART.
    Node<T> *dummyHead;
    Node<T> *dummyTail;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    
    this->dummyHead = new Node<T>();
    this->dummyTail = new Node<T>();
    this->dummyHead->next = dummyTail;
    this->dummyTail->prev = dummyHead;
    
    
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    /* TODO */ 
    
    
    this->dummyHead = new Node<T>();
    this->dummyTail = new Node<T>();
    this->dummyHead->next = dummyTail;
    this->dummyTail->prev = dummyHead;
    Node<T> * current = this->getDummyHead();
    Node<T> * objP = obj.getDummyHead();
    Node<T> * objT = obj.getDummyTail();
    if(objP->next != objT){
        while (objP->next != objT){
            Node<T>* newNode = new Node<T>( objP->next->data);
            current->next = newNode;
            current->next->prev = current;
            current = current->next;
            objP = objP->next;
        
        }
        current->next = this->getDummyTail();
        this->getDummyTail()->prev = current;
    }
   
}
template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    this->deleteAllNodes();
    delete this->getDummyHead();
    delete this->getDummyTail();
    
}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    int size = 0;
    if(this->isEmpty()){
        return size;
    }
    else{
        Node<T> * current = this->getDummyHead()->next;
        Node<T> * last = this->getDummyTail();
        while (current != last){
            size ++;
            current = current->next;
        }
        return size;
    }
    
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    
    return (this->getDummyHead()->next == this->getDummyTail());
    
    
}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    bool value;
    if(node == NULL){
        return false;
    }
    Node<T> * current = this->getDummyHead();
    if(this->isEmpty()){
        return false;
    }
    else{
        while(current != this->getDummyTail()){
            if(current->next == node->next && current->prev == node->prev && current->data == node->data ){
                value = true;
                break;
            }
            else{
                value = false;
            }
            current = current->next;
        }
    }    
    return value;
}

template<class T>
Node<T> *LinkedList<T>::getDummyHead() const {
    /* TODO */
    return this->dummyHead;
    
}

template<class T>
Node<T> *LinkedList<T>::getDummyTail() const {
    /* TODO */
    return this->dummyTail;
}

template<class T>
Node<T> *LinkedList<T>::getActualHead() const {
    /* TODO */
    if(this->isEmpty()){
        return NULL;
    }
    return this->dummyHead->next;
}

template<class T>
Node<T> *LinkedList<T>::getActualTail() const {
    /* TODO */
    if(this->isEmpty()){
        return NULL;
    }
    return this->dummyTail->prev;
    
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    
    Node<T> * current = this->getDummyHead();
    Node<T> * tmp;
    if(this->isEmpty()){
        return NULL;
    }
    else{
        current = current->next;
        while(current != this->getDummyTail()){
            if(current->data == data){
                 tmp = current;
                 break;
            }
            else{
                tmp = NULL;
            }
            current = current->next;
        }
    }    
    return tmp;
    
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
    if(index < 0) return NULL;
    int i = 0;
    Node<T> * current = this->getDummyHead();
    if(this->isEmpty()){
        return NULL;
    }
    else{
        if(index >= this->getSize()){
            return NULL;
        }
        else{
            
            while(i <(index+1)){
                current = current->next;
                i++;
                
                
            }
            return current;
        }
    }   
    
}

template<class T>
void LinkedList<T>::insertAtTheBeginning(const T &data) {
    /* TODO */
    Node<T>* newNode = new Node<T>(data);
    Node<T>* current = this->getDummyHead();
    Node<T>* last = this->getDummyTail();
    if(this->isEmpty()){
        current->next = newNode;
        newNode->prev = current;
        newNode->next = last;
        last->prev = newNode;
    }
    else{
        
        newNode->next = current->next;
        newNode->prev = current;
        current->next->prev = newNode;
        current->next = newNode;
    }
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    Node<T>* newNode = new Node<T>(data);
    Node<T>* current = this->getDummyHead();
    Node<T>* last = this->getDummyTail();
    if(this->isEmpty()){
        last->prev = newNode;
        newNode->next = last;
        newNode->prev = current;
        current->next = newNode;
    }
    else{
        
        newNode->prev = last->prev;
        newNode->next = last;
        last->prev->next = newNode;
        last->prev = newNode;
    }
}

template<class T>
void LinkedList<T>::insertBeforeGivenNode(const T &data, Node<T> *node) {
    /* TODO */
    
    
    if(this->contains(node)){
        Node<T>* newNode = new Node<T>(data);
        newNode->next = node;
        newNode->prev = node->prev;
        node->prev->next = newNode;
        node->prev = newNode;
    }
    
}

template<class T>
void LinkedList<T>::deleteNode(Node<T> *node) {
    /* TODO */
    if(this->contains(node)){
        
        node->prev->next = node->next;
        node->next->prev = node->prev;
        delete node;
    }
    
    
}

template<class T>
void LinkedList<T>::deleteNode(const T &data) {
    /* TODO */
    
    Node<T> * tmp = this->getNode(data);
    if(tmp != NULL){
        deleteNode(tmp);
    }
    
}

template<class T>
void LinkedList<T>::deleteAllNodes() {
    /* TODO */
    if(!(this->isEmpty())){
        Node<T>* current = this->getDummyHead()->next;
        while(current != this->getDummyTail()){
            Node<T> * tmp = current;
            current = current->next;
            delete tmp;
        }
        this->getDummyHead()->next = this->getDummyTail();
        this->getDummyTail()->prev = this->getDummyHead();
    }
     
    
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    /* TODO */
    if(this->contains(node1) && this->contains(node2)){
        Node<T> * tmp;
        Node<T> * left1;
        Node<T> * left2;
        Node<T> * right1;
        Node<T> * right2;
        if(node1->next = node2){
            left1 = node1->prev;
            right2 = node2->next;
            node2->prev = left1;
            left1->next = node2;
            node2->next = node1;
            node1->prev = node2;
            node1->next = right2;
            right2->prev = node1;
            
        }
        else if(node2->next = node1){
            left1 = node2->prev;
            right2 = node1->next;
            node1->prev = left1;
            left1->next = node1;
            node1->next = node2;
            node2->prev = node1;
            node2->next = right2;
            right2->prev = node2;
            
        }
        else{
            left1 = node1->prev;
            right1 = node1->next;
            left2 = node2->prev;
            right2 = node2->next;
            left1->next = node2;
            node2->prev = left1;
            node2->next = right1;
            right1->prev = node2;
            node1->next = right2;
            right2->prev = node1;
            node1->prev = left2;
            left2->next = node1;
        }
        
    }
    

}

template<class T>
void LinkedList<T>::traverse() const {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getActualHead();

    while (node && node->next) {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    /* TODO */
    this->deleteAllNodes();
    Node<T> * current = this->getDummyHead();
    Node<T> * objP = rhs.getDummyHead();
    Node<T> * objT = rhs.getDummyTail();
    if(objP->next != objT){
        while (objP->next != objT){
            Node<T>* newNode = new Node<T>( objP->next->data);
            current->next = newNode;
            current->next->prev = current;
            current = current->next;
            objP = objP->next;
        
        }
        current->next = this->getDummyTail();
        this->getDummyTail()->prev = current;
    }
}

#endif //LINKEDLIST_H
