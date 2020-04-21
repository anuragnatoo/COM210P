/*
Created on Mon March 11 2019
@author: anuragnatoo
*/
#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
class Median
{
	public:
		int partition(int a[100],int beg,int end,int x,int n);
		int select(int a[100],int beg,int end,int k);
		int med(int a[100],int n);
};
int Median :: med(int a[100],int n)
{
	sort(a,a+n);
	return a[n/2];
}

int Median :: select(int a[100],int beg,int end,int k)
{
	int i,x,y,j,g,h;
	int n=end-beg+1;
	if(k>0 && k<=n)
	{
		y=(n+4)/5;
		int b[y];
		for(j=0;j<n/5;j++)
		{
			b[j]=med(a+beg+j*5,5);
		}
		if(j*5<n)
		{
			b[j]=med(a+beg+j*5,n%5);
			j++;
		}
		
		//y=ceil(n/5);
		if(y==1)
			x=b[y-1];
		else
			x=select(b,0,y-1,y/2);
		
		i=partition(a,beg,end,x,n);
		
		if(i-beg==k-1)
			return a[i];
		else if(i-beg>k-1)
		{
			g=select(a,beg,i-1,k);
			return g;
		}
		else
		{
			h= select(a,i+1,end,k-(i-beg+1));
			return h;
		}
	}
	
}

int Median :: partition(int a[100],int beg,int end,int x,int n)
{
	int i,j,pivot;
	
	for( i=beg;i<=end;i++)
	{
		if(x==a[i])
			break;
	}
	int z;
	z=a[i];
	a[i]=a[end];
	a[end]=z;
	int l=beg-1,k;
	for( j=beg;j<end;j++)
	{
		if(a[j]<=x)
		{
			l++;
			k=a[j];
			a[j]=a[l];
			a[l]=k;
		}
	}
	k=a[l+1];
	a[l+1]=a[end];
	a[end]=k;
	
return l+1;
}

void print(int a[100],int n)
{
	int j;
	cout<<"sorted elements are:\n";
	for(j=0;j<n;j++)
		cout<<a[j]<<" ";
}


int main()
{
	int n,i,f,g;
	cout<<"enter the number of websites to check:\n";
	cin>>n;
	int a[n];
	for(i=0;i<n;i++)
	{
		cout<<"no of hits of website "<<i+1<<": ";
		cin>>a[i];
	}
	int z;
	cout<<"enter the position of website: ";
	cin>>z;
	Median y;
	f=y.select(a,0,n-1,z);
	cout<<"k th smallest is :"<<f<<endl;
	//g=y.select(a,0,n-1,n/2);
	//cout<<"median is: "<<g<<endl;
	//print(a,n);
}