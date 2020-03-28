/*Repeated Squaring Algorithm to calculate a^b(mod n)*/
//Reads testcases from testcases.txt and outputs d
#include<iostream>
#include<math.h>
#include <fstream>
#include <cstdlib>

using namespace std;

int getnumbits(long num)
{
	float lognumbase2 = log(num)/log(2);
	return ceil(lognumbase2);
}

int getBit(long num, int index)
{
	long x=num;
	x = x>>index;
	return x&1;
}

unsigned long doRepeatedSquares(long a, long b, long n)
{
	long long d = 0x1;
	int k=getnumbits(b);
	for(int i=k;i>=1;i--)
	{
		//cout<<"\n d:"<<d;
		
		/*square d = (d*d)%n */
		//(a*b)%n = ((a%n)*(b%n))%n
		long long z = d%n;
		z = z*z;   
		d = z%n;  
		
		int bi = getBit(b, i-1);  //Getting bit value at index i
		//cout<<dec<<" bi: "<<bi<<" i"<<i<<" d:"<<d;
		if(bi == 1)
		{
			long long x = d%n;
			long long y = a%n;
			//cout<<" n:"<<n<<" a:"<<a;
			/*step2*/
			//(a*b)%n = ((a%n)*(b%n))%n
			x = x*y;
			d = x%n;   
		}	
	//cout<<" d: "<<d<<"\n \n \n";
	}
	return d;
}

int main()
{
	ifstream myfile;
	myfile.open("testcases.txt", ios::in);
	std::string line;
	unsigned long obtained_output[8];
	while(!myfile.eof())
	{
		for(int i=0;i<8;i++)
		{
			getline(myfile,line,'\t');
			obtained_output[i]=0;
			long a = strtol(line.c_str(),NULL,16);
			getline(myfile,line,'\t');
			long b = strtol(line.c_str(),NULL,16);
			getline(myfile,line,'\t');
			long n = strtol(line.c_str(),NULL,16);
			getline(myfile,line,'\n');
			long given_output = strtol(line.c_str(),NULL,16);
			obtained_output[i] = doRepeatedSquares(a, b, n);
			
		}
	}
	myfile.close();
	for(int i=0;i<8;i++)
		cout<<hex<<obtained_output[i]<<"\n";
}
