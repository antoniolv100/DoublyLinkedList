#include <iostream>
#include<stdexcept>
#include<string>
#include"List.h"
#include"List.cpp"
#include"Iterator.h"
#include"Iteratormethod.cpp"
int main() {
	List<int> antonio;
	std::cout << "Testing LinkList" << std::endl;
	antonio.add(1);
	antonio.add(2);
	antonio.add(4);
	antonio.addTail(5);
	antonio.addHead(0);	
	antonio.addPos(6, 6);
	antonio.Display();
	std::cout << std::endl;
	std::cout <<"Testing rev method"<< std::endl;
	antonio.RevDisplay();
	std::cout << std::endl;
	std::cout << "Check del method" << std::endl;
	antonio.delHead();
	antonio.delTail();
	antonio.delPos(2);
	antonio.Display();
	std::cout << std::endl;
	std::cout << "Testing rev method" << std::endl;
	antonio.RevDisplay();
	std::cout << std::endl;
	std::cout << "Checking size , isempty, checktail and checkhead method" << std::endl;
	std::cout << antonio.Size() << std::endl;
	std::cout << antonio.isEmpty() << std::endl;
	antonio.CheckHead();
	antonio.CheckTail();
	std::cout << "Checking replace" << std::endl;
	antonio.replacedata(0, 9);
	antonio.Display();
	std::cout << std::endl;
	std::cout << "Testing bounds range || error " << std::endl;
	std::cout << "Calling delete Head when list is empty ." << std::endl;
	antonio.delHead();
	antonio.delHead();
	antonio.delHead();
	antonio.delHead();
	std::cout << "Calling delete Tail when list is empty.  " << std::endl;
	antonio.add(5);
	antonio.delTail();
	antonio.delTail();
	std::cout << "Adding postion that not on the list. " << std::endl;
	antonio.addPos(10, 27);
	std::cout << "Deleting a postion that does not exist. " << std::endl;
	antonio.delPos(1000);
	antonio.add(1);
	antonio.add(2);
	antonio.addHead(0);
	antonio.addTail(6);
	std::cout << "Checking list. " << std::endl;
	antonio.Display();
	std::cout << std::endl;
	std::cout << "Creating iterator and moving forward. " << std::endl;
	Iterator<int> i = antonio.loc();
	std::cout << i.data() << std::endl;
	i.next();
	std::cout << i.data() << std::endl;
	i.next();
	std::cout << i.data() << std::endl;
	i.next();
	std::cout << i.data() << std::endl;
	std::cout << "Moving backward. " << std::endl;
	i.back();
	std::cout << i.data() << std::endl;
	i.back();
	std::cout << i.data() << std::endl;
	i.back();
	std::cout << i.data() << std::endl;
	i.back();
	i.back();
	system("pause");
	return 0;
}