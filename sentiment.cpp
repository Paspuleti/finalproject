#include <iostream>

using namespace std;

//Creating a Person class with variables mood and diagnosis
class Person{
	public:
	string mood;
	
	Person(string m, string d)
		:mood(m) {}
	~Person(){}
	
};
