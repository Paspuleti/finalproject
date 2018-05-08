#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/*Defining class Person with members and
 * member functions
 */
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
/* defining function getValues
 * getValues populates the vector of doubles that
 * is a member of Person
 */
void Person::getValues(){
	for(auto in = emotions.begin(); in != emotions.end(); ++in){
		in++;
		emotionval.push_back(stod(*in));
	}	
}
/* defining fuction display
 * display lists the emotion along with its value
 */
void Person::display(){
	for(auto in = emotions.begin(); in != emotions.end(); ++in){
		cout<<*in<<endl;
	}
}
/*defining fuction temp
 * displays only the double values of each emotion in order
 */
void Person::temp(){
	for(auto in = emotionval.begin(); in != emotionval.end(); ++in){
		cout<<*in<<endl;
	}
}
/* defining function displayMax
 * displays the emotion with the highest value
 */
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
	//opens the textfile Test to read data gathered from the jpgs
	ifstream input ("Test");
	if(input.is_open()){
		while(getline(input,stuff)){
			stringstream read(stuff);
			//pushes strings into the vector of strings
			while(read >> words)
				hold.push_back(words);
			Person *insert = new Person(hold);//creates a new person for each input
			hold.clear();
			people.push_back(insert);

			
		}
		input.close();
	}
	else
		cout<<"Can't open file"<<endl;

        //Displays data by iteration through each Person object
	for(auto in = people.begin(); in != people.end(); ++in){
		(*in)->getValues();
		(*in)->temp();
		(*in)->displayMax();
	}
        return 0;
}


