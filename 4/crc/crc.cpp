#include <iostream>
using namespace std;
int main()
{
	int fs,gs,rs,f[20],g[10],temp[20],crc[10];
	cout<<"\nEnter size of dataword (fs)";
	cin>>fs; 
	
	cout<<"\nEnter size of divisor (gs)";
	cin>>gs; 
	
	rs=gs-1;
	
	cout<<"\nEnter Data word : ";
	for(int i=0;i<fs;i++)
		cin>>f[i];
	cout<<"\nDATA WORD : ";	
	for(int i=0;i<fs;i++)
		cout<<f[i];
		
	cout<<"\nEnter Divisor : ";
	for(int i=0;i<gs;i++)
		cin>>g[i];
	cout<<"\nDIVISOR : ";	
	for(int i=0;i<gs;i++)
		cout<<g[i];
	
	for(int i=fs;i<fs+rs;i++)
		f[i]=0;
			
	for(int i=0;i<fs+rs;i++)
		temp[i]=f[i];
		
	for(int i=0;i<fs;i++)
	{
		int k=i,j=0;
		if(g[j]>temp[k])
		{
			for(k=i,j=0;j<gs;k++,j++)
			{
				if((temp[k]&&g[j]==1)||(temp[k]&&g[j]==0))
				{
					temp[k]=0;
				}
				else
				{
					temp[k]=1;
				}
			}
		}
	}
	for(int i=0,k=fs;i<rs;i++,k++)
	{
		crc[i]=temp[k];
	}
	
	cout<<"\n\n";
	cout<<"\nCRC : ";
	for(int i=0;i<rs;i++)
		cout<<crc[i];
	cout<<"\n\n";
	cout<<"CODE GENERATED : ";
	for(int i=0;i<fs;i++)
	{
		cout<<f[i];
	}
	for(int i=0;i<gs-1;i++)
		cout<<crc[i];
	
	
	//RECEIVER	
	int rec[20];
	cout<<"\n\nEnter received data";
	for(int i=0;i<fs+rs;i++)
		cin>>rec[i];
		
	for(int i=0;i<fs;i++)
	{
		int k=i,j=0;
		if(g[j]>rec[k])
		{
			for(k=i,j=0;j<gs;k++,j++)
			{
				if((rec[k]&&g[j]==1)||(rec[k]&&g[j]==0))
				{
					rec[k]=0;
				}
				else
				{
					rec[k]=1;
				}
			}
		}
	}
	for(int i=0,k=fs;i<rs;i++,k++)
	{
		crc[i]=rec[k];
	}
	
	cout<<"\n\n";
	cout<<"\nREMAINDER :";
	for(int i=0;i<rs;i++)
		cout<<crc[i];
	int flag=1;
	for(int i=0;i<rs;i++)
	{
		if(crc[i]!=0)
			flag=0;
	}
	if (flag==1)
		cout<<"\nTHE RECEVIED CODE IS CORRECT\n";
	else
		cout<<"\nTHE RECEVIED CODE IS INCORRECT\n";
	
		
	
	
}
