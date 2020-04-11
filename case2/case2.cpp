/*Purpose 	:Program to find the sum of square of given number
	Language	:C++
	Author  	: Reshma Tamma
	Date    	: 10/04/2020
	*/
#include<iostream>
#include<string.h>
using namespace std;
class square
{
	private:
		int number ;
	public:
		
		 int sum (int inumber)
		{
		number=inumber;
		int sum =0 ,i=1 ;
		for(i=1;i<=inumber;i++)
		 {
		 	 sum=sum+(i*i) ;
		 }
		 cout<<"sum is"<<sum<<endl;
}
};
int main(int argc, char* argv[])
{
    if(argc>=2)
    {
	    if(strcmp(argv[1],"-h")==0)					//if loop for comparing the input string with "-h"
	    {
            cout<<"Usage: "<<endl;
            
	    }
    }
	else
	{
		int n ;
		cout<<"enter the number "<<endl ;
		cin>>n ;
		square s;
		s.sum(n);
	}	
}
