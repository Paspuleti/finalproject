#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

class Block{
	public:
	string emotion;
	double value;
	Block(string e, double val):emotion(e), value(val){}
	~Block(){};
	string getString(){return emotion;};
	double getValue(){return value;};
};


/*void extract(string po){
	stringstream ss;
	ss << po;
	string total; 
	int find;
*/	

int main(){
	cout<<"C++ File executing"<<endl;
	string stuff;
	string comp;
	ifstream input ("Test");
	if(input.is_open()){
		while(getline(input,stuff)){
			comp += stuff;
		}
		input.close();
	}
	else
		cout<<"Can't open file"<<endl;

	cout<<comp<<endl;
	//extract(comp);
	return 0;
}


