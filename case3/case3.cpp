/*Name of the program:parse the command line and dispaly the output
filename:case1.cpp
date:22-04-2020
Author:Reshma Tamma
*/

#include<iostream>
#include<string.h>

using namespace std;
int j=3; //global variable
class specific
{
	private:
		signed int q;
		 int a;
		float r;
	public:
		char s;
		string g;
		int j=10;
		mutable float b;
	void read() //function to read variables in private access specifier of the class
	{
		cout<<"give the float value accordingly to store as 'r'"<<endl;
		cin>>r;
		cout<<"give the signed in tvalue accordingy to store as 'q'"<<endl;
		cin>>q;
		cout<<"enter a string"<<endl;
		cin>>g;
		cout<<"j is ="<<j<<endl;
		cout<<"enter b value :"<<endl;
		cin>>b;
		cout<<"enter value of a :"<<endl;
		cin>>a;
	}
	void display()
	{
		cout<<"enter a character"<<endl;
		cin>>s;
		cout<<"q ="<<q<<endl;
		cout<<"r ="<<r<<endl;
		cout<<"g ="<<g<<endl;
		cout<<"s="<<s<<endl;
		cout<<"a="<<a<<endl;
		cout<<"b="<<b<<endl;
	}
	void size()
	{
		cout<<"size of g is :"<<sizeof(g)<<endl;
		cout<<"size of r is :"<<sizeof(r)<<endl;
		cout<<"size of s is :"<<sizeof(s)<<endl;
		cout<<"size of q is :"<<sizeof(q)<<endl;
	}
};
int main(int argc,char *argv[])
{
	
	if(argc>=2)
	{
    	if(strcmp(argv[1],"-h")==0) 	//For program usage through commandline argument -h
    	{
			cout<<"used for explaining variable scope,modifiers and stroage classes"<<endl; 
		}
	}
	else
	{
	specific e;
	e.read();
	e.display();
	e.size();
	}
}
