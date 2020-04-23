/*Name of the program:parse the command line and dispaly the output
filename:case1.cpp
date:12-04-2020
Author:Reshma Tamma
*/
#include<iostream>
#include<stdlib.h>
#include<typeinfo>
#include<bits/stdc++.h>
using namespace std;

//function to check length of string is '1' 0r not
bool length(string s1)
{
int iA;
for(iA=0;s1.length()==1;iA++)
{
return true;	//if the condition satisfifies it return '1'.
}
}
//main usig command line arguments.
int main(int argc,char *argv[])
{
	int iB,iC;		//declaring integer variables
	float fH;		//declaring float variable
	if(argc==2)
	{
		cout<<"used for finding type and size of given argument"<<endl; 
	}
	else
	{
	cout<<"type"<<"\t"<<"value"<<"\t"<<"sizeof"<<endl;
	for(iB=1;iB<argc;iB++)
	{
		iC=atoi(argv[iB]);		//atoi convert ascii to int
		fH=atof(argv[iB]);		//atof convert ascii to float
   		if(iC==0)
		{
			if(check(argv[iB]))	//if condition satisfies means it will print char
			{
				cout<<"char";
				cout<<"\t"<<argv[iB]<< "\t"<<strlen(argv[iB])<<endl;
			}
			else		//it will print string
			{
				cout<<"string";
				cout<<"\t"<<argv[iB]<< "\t"<<sizeof(argv[iB])<<endl;
			}		
		}
		else
		{
			if(iC==fH)	//if condition  that stisfied means it will print int 
			cout<<"int"<< "\t"<<iC<<"\t"<<sizeof(iC)<<endl;
			else		//else it will print float
			cout<<"float"<< "\t"<<fH<<"\t"<<sizeof(fH)<<endl;
		}
	}
		return 0;
	}
}
