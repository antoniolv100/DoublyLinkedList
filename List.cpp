#include<iostream>
#include<stdexcept>
#include "List.h"
#include "Node.h"
template<class Anytype>
List<Anytype>::List(){
	head = nullptr;
	tail = nullptr;
};
template<class Anytype>
List<Anytype>::~List(){
	std::cout << "List has been destoryed." << std::endl;
};
template<class Anytype>
void List<Anytype>::add(Anytype data) {
	node<Anytype>* temp = new node<Anytype>;
	node<Anytype>* curr = new node<Anytype>;
	temp->data = data;
	temp->next = nullptr;
	temp->prev = nullptr;
	if (head != nullptr) {
		curr = head;
		while (curr->next != nullptr) {
			curr = curr->next;
		}
		curr->next = temp;
		temp->prev = curr;
		tail = temp;
	}
	else {
		head = temp;
		tail = temp;
	}
	size++;
};
template<class Anytype>
void List<Anytype>::addHead(Anytype data) {
	node<Anytype>* temp = new node<Anytype>;
	temp->data = data;
	temp->next = head;
	temp->prev = nullptr;
	head->prev = temp;
	head = temp;
	size++;
};
 template<class Anytype>
 void List<Anytype>::addPos(Anytype pos, Anytype data) {
	 node<Anytype>* temp = new node<Anytype>;
	 node<Anytype>* cur = new node<Anytype>;
	 node<Anytype>* behind = new node<Anytype>;
	 if (BoundCheck(pos) == false) {
		 std::cout << "Cant add from out of range." << std::endl;
		 return;
	 }
	 if (pos == 0) {
		 addHead(data);
		 return;
	 }
	 if (pos == size){
		 addTail(data);
		 return;
	 }
	 cur = head;
	 for (int x = 0; x < pos; x++) {
		 behind = cur;
		 cur = cur->next;
	 }
	 temp->next = cur;
	 cur->prev = temp;
	 behind->next = temp;
	 temp->prev = behind;
	 temp->data = data;
	 size++;
 };
 template<class Anytype>
 void List<Anytype>::addTail(Anytype data) {
	 node<Anytype>* temp = new node<Anytype>;
	 temp->data = data;
	 temp->prev = tail;
	 tail->next = temp;
	 temp->next = nullptr;
	 tail = temp;
	 size++;
 }
 template<class Anytype>
 void List<Anytype>::replacedata(Anytype pos, Anytype data) {
	 node<Anytype>* curr = head;
	 for (int x = 0; x < pos; x++) {
		 curr = curr->next;
	 }
	 curr->data = data;
 }
 template<class Anytype>
 void List<Anytype>::delHead() {
	 node<Anytype>* temp = new node<Anytype>;
	 if (size == 0) {
		 std::cout << "Out of bound! From head." << std::endl;
		 return;
	 }
	if (head->next == nullptr) {
		head = nullptr;
		size--;
	}
	else {
		temp = head->next;
		temp->prev = nullptr;
		delete head;
		head = temp;
		size--;
	}

 };
 template<class Anytype>
 void List<Anytype>::delTail() {
	 node<Anytype>* temp = new node<Anytype>;
	 if (size == 0) {
		 std::cout << "Out of bound! From tail." << std::endl;
		 return;
	 }
	
	if (tail->prev == nullptr) {
		tail = nullptr;
		size--;
	}
	else {
		temp = tail->prev;
		temp->next = nullptr;
		delete tail;
		tail = temp;
		size--;
	}
	 
 }
 template<class Anytype>
 void List<Anytype>::delPos(Anytype pos) {
	 node<Anytype>* behind = new node<Anytype>;
	 node<Anytype>* curr = new node<Anytype>;
	 if (BoundCheck(pos) == false) {
		 std::cout << "Cant del, out of range." << std::endl;
		 return;
	 }
	 if (pos == size-1) {
		 delTail();
		 return;
	 }
	 if (pos == 0) {
		 delHead();
		 return;
	 }
	 curr = head;
	 for (int x = 0; x < pos; x++) {
		 behind = curr;
		 curr = curr->next;
	 }
	 behind->next= curr->next;
	 curr->next->prev= behind;
	 delete curr;
	 size--;
 };
 template<class Anytype>
 void List<Anytype>::Display() {
	 node<Anytype>* curr = head;
	 while (curr != nullptr) {
		 std::cout << curr->data << " ";
		 curr = curr->next;
	 }
 };
 template<class Anytype>
 void List<Anytype>::RevDisplay() {
	 node<Anytype>* curr = tail;
	 while (curr != nullptr) {
		 std::cout << curr->data << " ";
		 curr = curr->prev;
	 }
 };
 template<class Anytype>
 int List<Anytype>::Size() {
	 return size;
 };
 template<class Anytype>
 bool List<Anytype>::isEmpty() {
	 if (size == 0) return true;
	 else
		 return false;
 };
 template<class Anytype>
 void List<Anytype>::CheckHead() {
	 std::cout << head->data << std::endl;
 };
 template<class Anytype>
 void List<Anytype>::CheckTail(){
	 std::cout << tail->data << std::endl;
 };
 template<class Anytype>
 bool List<Anytype>::BoundCheck(Anytype pos) {
	 node<Anytype>* now = head;
	 for (int x = 0; x < pos; x++) {
		 if (now == NULL) {
			 return false;
		 }
		 now = now->next;
	 }
	 return true;
 }

 template<class Anytype>
 Iterator<Anytype> List<Anytype>::loc() {
	 return Iterator<Anytype>(head);
 }