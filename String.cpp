#include "String.h"

String::String() {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */
}

String::String(char *str) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    // str is a null terminated C string.
    // (e.g. ['h','e','l','l','o','\0'])

    char *temp = str;

    while (*temp != '\0') {
        this->characters.insertAtTheEnd(*temp);
        temp++;
    }
}

int String::getLength() const {
    /* TODO */
    return this->characters.getSize();
}

bool String::isEmpty() const {
    /* TODO */
    return this->characters.isEmpty();
}

void String::appendCharacter(char character) {
    /* TODO */
    this->characters.insertAtTheEnd(character);
}

void String::insertCharacter(char character, int pos) {
    /* TODO */
    if(pos > this->characters.getSize()){
        return; 
        
    }
    if(this->characters.getSize() == 0){
        this->characters.insertAtTheBeginning(character);
    }
    else{
        this->characters.insertBeforeGivenNode(character,this->characters.getNodeAtIndex(pos));
    }
    
    
}

void String::eraseCharacters(int pos, int len) {
    /* TODO */
    
    if((pos < 0) || (len < 0) || (pos >= this->characters.getSize()) || ((pos+len) > this->characters.getSize())) {
        return;
    }
    else{
        for(int i = 0; i < len; i++){
            this->characters.deleteNode(this->characters.getNodeAtIndex(pos));
        }
    }
}

void String::eraseAllCharacters() {
    /* TODO */
    this->characters.deleteAllNodes();
}

String String::substring(int pos, int len) {
    /* TODO */
    
    String  sub ;
    if((pos < 0) || (len < 0) || (pos >= this->characters.getSize()) || ((pos+len) > this->characters.getSize())) {
        
        return sub;
    }
    else{
        for(int i = 0; i < len; i++,pos++){
            sub.appendCharacter(this->characters.getNodeAtIndex(pos)->data);
            
        }
        return sub;
    }
    
    
    
}

LinkedList<String> String::split(char separator) {
    /* TODO */
    LinkedList<String> ls;
    
    if(this->characters.isEmpty()){
        ls.insertAtTheEnd("");
    }
    else{
        Node<char> * current = this->characters.getActualHead();
        Node<char> * last = this->characters.getDummyTail();
        int pos = 0;
        int len = 0;
        while(current !=  last){
            if(current->data == separator){
                ls.insertAtTheEnd(this->substring(pos, len));
                
                pos = pos + len +1;
                len = 0;
                
            }
            else{
                len++;
                if(current == last->prev){
                    ls.insertAtTheEnd(this->substring(pos , len));
                }
            }
            
            current = current->next;
            
        }
        
    }
    return ls;
    
}

bool String::isPalindrome() const {
    /* TODO */
    if(this->characters.isEmpty()){
        return true;
    }
    else{
        Node<char> * head = this->characters.getActualHead();
        Node<char> * tail = this->characters.getActualTail();
        for(int i = 0; i <= this->characters.getSize()/2; i++,head = head->next,tail = tail->prev){
            if(head->data != tail->data){
                return false;
            }
            else{
                return true;
            }
            
        }
    }
    
}

bool String::operator<(const String &rhs) const {
    /* TODO */
    int size = this->characters.getSize();
    int sizer = rhs.characters.getSize(); 
    if(this->characters.isEmpty() || rhs.isEmpty()){
        if(this->characters.isEmpty()){
            return true;
        }
        else{
            return false;
        }
    }
    else{
        Node<char> * head = this->characters.getActualHead();
        Node<char> * headr = rhs.characters.getActualHead();
        for(int i = 0; i < size +sizer; i++){
            if(head->data < headr->data){
                return true;
            }
            else if(head->data == headr->data){
                head = head->next;
                headr = headr->next;
                if(head->next == NULL || headr->next == NULL){
                    if(size < sizer){
                        return true;
                    }        
                }
                
            }
            else{
                return false;
            }
        }
            
        
    }
}

void String::print(bool verbose) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = this->characters.getActualHead();
    Node<char> *actualTailNode = this->characters.getActualTail();

    if (verbose) {
        std::cout << "[";
    }

    while (node && node->next) {
        if (verbose) {
            std::cout << "'" << node->data << "'";
            if (node != actualTailNode) {
                std::cout << ",";
            }
        } else {
            std::cout << node->data;
        }

        node = node->next;
    }

    if (verbose) {
        std::cout << "]";
    }

    std::cout << std::endl;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    Node<char> *node = string.characters.getActualHead();

    while (node && node->next) {
        os << node->data;
        node = node->next;
    }

    return os;
}
