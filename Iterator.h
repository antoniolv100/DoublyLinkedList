#pragma once
#include"Node.h"
template<class Anytype>
class Iterator {
private:
	node<Anytype>* n = new node<Anytype>;
	node<Anytype>* tail = new node<Anytype>;;
	node<Anytype>* now =  new node<Anytype>;
public:
	Iterator(node<Anytype>* np);
	void next();
	void back();
	Anytype data();
};