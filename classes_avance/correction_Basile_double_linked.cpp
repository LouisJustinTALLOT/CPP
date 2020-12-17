#include <iostream>

class Node{
    private: 
        int _value; 
        Node* _prev;
        Node* _next;

    public: 
        Node(const int& x): _value(x), _prev(nullptr), _next(nullptr){}
        
        int get(){
            return this->_value;
        }

        Node* next(){
            return this->_next;
        }

        void next(Node* n){
            this->_next = n;
        }

        Node* previous(){
            return this->_prev;
        }

        void previous(Node* n){
            this->_prev = n;
        }
};

class IntLinkedList{
    protected: 
        Node* _head;
        Node* _tail;
    public: 
        IntLinkedList(): _head(nullptr), _tail(nullptr) {}
        void append(const int& x){
            if( this->_tail == nullptr ){
                this->_tail = new Node(x);
                this->_head = this->_tail; 
            }
            else{
                Node* toAdd = new Node(x);
                toAdd->previous( this->_tail );
                this->_tail->next( toAdd );
                this->_tail = toAdd; 
            }
        }
        void prepend(const int& x){
            if( this->_head == nullptr ){
                this->_head = new Node(x);
                this->_tail = this->_head;
            }
            else{
                Node* toAdd = new Node(x);
                toAdd->next(this->_head);
                this->_head->previous( toAdd );
                this->_head = toAdd;
            }
        }
        void print(){
            Node* current=this->_head;
            std::cout << current->get() << " -> ";
            while( current->next() != nullptr ){
                current = current->next();
                std::cout << current->get() << " -> ";
            }
            std::cout << std::endl;
        }
        void print_reverse(){
            Node* current = this->_tail;
            std::cout << current->get() << " <- ";
            while( current->previous() != nullptr ){
                current = current->previous();

                std::cout << current->get() << " <- ";
            }
            std::cout << std::endl;
        }
};

int main(){
    IntLinkedList l;

    l.append( 10 );
    l.append( 20 );
    l.append( 30 );
    l.prepend( 1 );

    //l.insert(1, 100);
    l.print();

    l.print_reverse();

    return 0;
}
