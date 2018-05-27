#include"Iterator.h"
#include"Node.h"
#include<stdexcept>
template<class Anytype>
Iterator<Anytype>::Iterator(node<Anytype>* head) {
    n = head;
};
template<class Anytype>
void Iterator<Anytype>::next(){
	if (n->next == nullptr) {
		std::cout << "Can move forward. " << std::endl;
		return;
	}
	n = n->next;
};
template<class Anytype>
void Iterator<Anytype>::back(){
	if (n->prev == nullptr) {
		std::cout << "Cant move back. " << std::endl;
		return;
	}
	n = n->prev;
};
template<class Anytype>
Anytype Iterator<Anytype>::data(){
	return (n->data);
};
