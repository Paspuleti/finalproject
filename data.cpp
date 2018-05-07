#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Person{
        public:
		vector<string> emotions;
		vector<double> emotionval;
                Person(vector<string> data):emotions(data){}
                ~Person(){}
                void getValues();
		void display();
		void displayMax();
		void temp();
};

void Person::getValues(){
	for(auto in = emotions.begin(); in != emotions.end(); ++in){
		in++;
		emotionval.push_back(stod(*in));
	}	
}

void Person::display(){
	for(auto in = emotions.begin(); in != emotions.end(); ++in){
		cout<<*in<<endl;
	}
}

void Person::temp(){
	for(auto in = emotionval.begin(); in != emotionval.end(); ++in){
		cout<<*in<<endl;
	}
}

void Person::displayMax(){
	double compare = emotionval[0];
	int index = 0;
	for(auto in = emotionval.begin(); in != emotionval.end(); ++in){
		if(compare < (*in)){
			compare = *in;
			index++;
		}
	}
	cout<<"Highest emotion: "<< emotions[(index*2)]<<compare<<endl;
}

int main(){
	cout<<"C++ File executing"<<endl;
	vector<Person *> people;
	string stuff;
	string words;
	vector<string> hold;

	ifstream input ("Test");
	if(input.is_open()){
		while(getline(input,stuff)){
			stringstream read(stuff);
			while(read >> words)
				hold.push_back(words);
			Person *insert = new Person(hold);
			hold.clear();
			people.push_back(insert);

			
		}
		input.close();
	}
	else
		cout<<"Can't open file"<<endl;

        for(auto in = people.begin(); in != people.end(); ++in){
		//(*in)->display();
		(*in)->getValues();
		(*in)->temp();
		(*in)->displayMax();
	}
        return 0;
}


