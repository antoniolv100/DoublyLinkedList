#pragma once
template<class Anytype>
struct node{
	Anytype data;
	node<Anytype>* next;
	node<Anytype>* prev;
};