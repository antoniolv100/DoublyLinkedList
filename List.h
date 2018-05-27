#pragma once
#include"Node.h"
#include"Iterator.h"
template<class Anytype>
class List{
private: 
	node<Anytype> *head, *tail;
	int size = 0;
public:
	 List();
	 ~List();
	void add(Anytype data);
	void addPos(Anytype pos ,Anytype data);
	void addHead(Anytype data);
	void addTail(Anytype data);
	void replacedata(Anytype pos ,Anytype data);
	void delHead();
	void delTail();
	void delPos(Anytype Pos);
	int Size();
	bool isEmpty();
	void Display();
	void RevDisplay();
	void CheckHead();
	void CheckTail();
	bool BoundCheck(Anytype Pos);
	Iterator<Anytype> loc();
};


