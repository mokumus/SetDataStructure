#include <iostream>
#include <memory>
#include "GTUSet.h"

using namespace GTUContainers;
using std::cout;
using std::cerr;
using std::endl;
using std::shared_ptr;
using std::string;
using std::boolalpha;

template <class T>
shared_ptr<GTUSetBase <T> > setIntersection(const GTUSetBase<T>& first, const GTUSetBase<T>& second){
	shared_ptr<GTUSetBase<T> > interSet = shared_ptr<GTUSetBase<T> >(new GTUSetBase<T>());
	for(auto i = first.begin(); i != first.end(); i++){
		if(second.contains(i->getData()))
			interSet->insert(i->getData());
	}
	return interSet;
}

int main(int argc, const char * argv[]) {
	
	GTUSet<string> colors;
	GTUSet<int> perfectSquare;
	GTUSet<int> perfectSquareDivisible;
	GTUSet<char> password;
	GTUSet<string> green;
	GTUSet<string> round;
	
	try {
		cout << "Inserting 'white' " << endl;	 colors.insert("white");
		cout << "Inserting 'red' " << endl;	     colors.insert("red");
		cout << "Inserting 'blue' " << endl;	 colors.insert("blue");
		cout << "Inserting 'yellow' " << endl;	 colors.insert("yellow");
		cout << "Inserting 'green' " << endl;	 colors.insert("green");
		cout << "Inserting 'orange' " << endl;	 colors.insert("orange");
		cout << "Inserting 'black' " << endl;	 colors.insert("black");
		cout << "Inserting 'black' " << endl;	 colors.insert("black");
	}
	catch (...) {
		cerr << "Element is already in the set, each element must be unique(invalid_argument)" << endl << endl;
	}
	
	cout << "Contents of set colors: ";
	colors.output();

	
	
	cout << "Print after finding 'yellow' >> ";
	for(auto i = colors.find("yellow"); i != colors.end(); i++)
		cout << i->getData() << " ";
	
	cout << endl << endl;
	
	cout << "Filling perfectSquare set..." << endl;
	for (int i = 10; i > 0; i--)
		perfectSquare.insert(i*i);
	
	
	cout << "Contents of set perfectSquare: ";
	perfectSquare.output();
	cout << endl;
	
	
	
	cout << "Make a subset of perfectSquare which are divisible by 2." << endl;
	for (auto i = perfectSquare.begin(); i != perfectSquare.end(); i++) {
		if ((i->getData()) % 2 == 0)
			perfectSquareDivisible.insert(i->getData());
	}
	
	cout << "Contents of set perfectSquareDivisible: ";
	perfectSquareDivisible.output();
	cout << endl;
	
	cout << "Filling password set..." << endl;
	
	password.insert('h');
	password.insert('1');
	password.insert('t');
	password.insert('2');
	password.insert('i');
	password.insert('3');
	password.insert('m');
	password.insert('4');
	password.insert('s');
	password.insert('5');
	password.insert('k');
	password.insert('6');
	password.insert('c');
	password.insert('7');
	password.insert('a');
	password.insert('8');
	password.insert('l');
	password.insert('9');
	password.insert('b');
	
	password.output();
	
	cout << "Print alphabetical elements >>";
	for (auto i = password.begin(); i != password.end(); i++) {
		if (isalpha((i->getData())))
			cout << (i->getData());
	}
	
	cout << endl;
	
	cout << "Deleting some chars >>";
	password.erase('b');
	password.erase('h');
	password.erase('5');
	password.erase('k');
	password.erase('6');
	password.erase('c');
	password.erase('7');
	password.erase('a');
	
	password.output();
	cout << endl;
	
	
	password.clear();
	cout << "password.clear() >> ";
	password.output();
	cout << "password.empty() >> " << boolalpha << password.empty() << endl;
	
	cout << endl;
	
	password.insert('6');
	password.insert('W');
	password.insert('H');
	password.insert('_');
	password.insert('U');
	password.insert('T');
	password.insert('G');
	
	cout << "new password >> ";
	
	for (auto i = password.begin(); i != password.end(); i++)
		cout << (i->getData());
	
	cout << endl;
	cout << "password.empty() >> " << boolalpha << password.empty() << endl;
	cout << endl;
	
	cout << "Filling green set..." << endl;
	green.insert("money");
	green.insert("aliens");
	green.insert("leaves");
	green.insert("grass");
	
	green.output();
	cout << "auto i = green.find(grass) >> i.erase(i->getData())" << endl;
	auto i = green.find("grass");
	green.erase(i->getData());
	
	cout << "Contents of set green: ";
	green.output();
	cout << endl;
	
	
	cout << "Filling round set..." << endl;
	round.insert("coins");
	round.insert("aliens");
	round.insert("leaves");
	round.insert("balls");
	
	cout << "Contents of set round: ";
	round.output();
	cout << endl;
	
	cout << "Intersection of round and green: ";
	auto inter = setIntersection<GTUSet>(round,green);
	inter->output();
	
	
	
	
	return 0;
}
