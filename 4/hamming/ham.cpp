/*
 * ham.cpp
 *
 *  Created on: Jul 27, 2018
 *      Author: pccoe
 */
#include<iostream>
using namespace std;

class ham
{
	int d[7],r[7];
	int c1,c2,c4,c;

public:
	ham()
	{
		c1=0;
		c2=0;
		c4=0;
		c=0;
		for(int k=0;k<7;k++)
		{
			d[k]=0;
			r[k]=0;
		}
	}

	void send()
	{
		cout<<"\nEnter Data : ";
		cin>>d[0]>>d[1]>>d[2]>>d[4];

		d[6]=d[4]^d[2]^d[0];
		d[5]=d[4]^d[1]^d[0];
		d[3]=d[2]^d[1]^d[0];

		cout<<"\n Data : ";
		for(int k=0;k<7;k++)
		{
			cout<<d[k];
		}

		cout<<"\n";
	}

	void rec()
	{
		cout<<"\nEnter received data : ";
		for(int k=0;k<7;k++)
		{
			cin>>r[k];
		}

		c1=r[6]^r[4]^r[2]^r[0];
		c2=r[5]^r[4]^r[1]^r[0];
		c4=r[3]^r[2]^r[1]^r[0];
		c=(c4*4)+(c2*2)+(c1);

		if (c==0)
			cout<<"\nNo error.......!!!!!";
		else
		{
			cout<<"\nError at "<<c<<" position";

			if (r[7-c]==0)
				r[7-c]=1;
			else
				r[7-c]=0;

			cout<<"\nCorrected Data : ";
			for(int k=0;k<7;k++)
			{
				cout<<r[k];
			}
		}
		cout<<"\n";

	}
};

int main()
{
	ham h;
	int n;

	do
	{
		cout<<"\n1.send";
		cout<<"\n2.received";
		cout<<"\n3.Exit";
		cout<<"\nEnter your choice : ";
		cin>>n;

		switch(n)
		{
		case 1:
			h.send();
			break;
		case 2:
			h.rec();
			break;
		case 3:
			break;
		default:
			cout<<"\nInvalid Choice..\n";
		}
	}while(n!=3);


	return 0;
}



