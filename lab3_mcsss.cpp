/*
Created on Mon Jan 21 2019
@author: anuragnatoo
*/
#include<iostream>
#include<string.h>
using namespace std;
class dna
{	
	public:
		char s[100];
		char f[100];
		int st[100];
		int fa[100];
		int begin,end;
		void read();
		int bruteForce(int x[]);
		int incDesign(int x[]);
		int dc(int beg,int end,int a[]);
		int pr(int x[]);
		void print();
};
int dna::bruteForce(int x[])
{
	int msum=0;
	int sum;
	int i,j,k;
	for(i=0;i<strlen(s);i++)
	{
		for(j=i;j<strlen(s);j++)
		{
			sum=0;
			for(k=i;k<=j;k++)
			{
				sum=sum+x[k];
			}
			if(msum<sum)
			{
				msum=sum;
				begin=i;
				end=j;
			}
		}
	}
	return msum;
}
int dna::incDesign(int x[])
{
	int msum=0;
	int sum;
	int i,j,k;
	for(i=0;i<strlen(s);i++)
	{
		sum=0;
		for(j=i;j<strlen(s);j++)
		{
			sum=sum+x[j];
			if(msum<sum)
				msum=sum;
		}
	}
	return msum;
}
int dna::pr(int x[])
{
	int msum=0;
	int csum=0;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		csum=csum+x[i];
		if(csum<0)
			csum=0;
		if(csum>msum)
			msum=csum;
	}
	return msum;
}
void dna::read()
{
	cin>>s;
	cin>>f;
	int i;
	for(i=0;i<strlen(s);i++)
	{
		if(s[i]=='a')
			st[i]=2;
		else if(s[i]=='g')
			st[i]=-1;
		else if(s[i]=='c')
			st[i]=1;
		else if(s[i]=='t')
			st[i]=-2;
	}
	for(i=0;i<strlen(f);i++)
	{
		if(f[i]=='a')
			fa[i]=2;
		else if(f[i]=='g')
			fa[i]=-1;
		else if(f[i]=='c')
			fa[i]=1;
		else if(f[i]=='t')
			fa[i]=-2;
	}
}
int dna::dc(int beg,int end,int a[])
{
	int i,j,k;
	int mid;
	int ls,rs;
	int arr[3];
	int losum,rosum;
	int rsum,lsum;
	int msum;
	if(beg==end)
	{
		if(a[beg]<0)
			return 0;
		else
			return a[beg];
	}
	mid=(beg+end)/2;
	ls=dc(beg,mid,a);
	rs=dc(mid+1,end,a);
	rosum=0;
	losum=0;
	rsum=0;
	for(i=mid;i<=end;i++)
	{
		rsum=rsum+a[i];
		if(rsum>rosum)
			rosum=rsum;
	}
	lsum=0;
	for(i=mid-1;i>=beg;i--)
	{
		lsum=lsum+a[i];
		if(lsum>losum)
			losum=lsum;
	}
	msum=losum+rosum;
	arr[0]=msum;
	arr[1]=ls;
	arr[2]=rs;
	int max=arr[0];
	for(i=0;i<3;i++)
	{
		if(max<arr[i])
			max=arr[i];
	}
	return max;
}
int main()
{
	int pr1,bf1,id1,dc1;
	int pr2,bf2,id2,dc2;
	int i,j;
	dna var;
	cout<<"Enter Son's DNA sequence first and fathers next\n";
	var.read();
	bf1=var.bruteForce(var.st);
	pr1=var.pr(var.st);
	id1=var.incDesign(var.st);
	dc1=var.dc(0,(strlen(var.s)-1),var.st);
	cout<<"*******Son*******\n";
	cout<<"BruteForce-"<<bf1<<"\n";
	cout<<"Incremental Design-"<<id1<<"\n";
	cout<<"Pruning-"<<pr1<<"\n";
	cout<<"Divide and Conquer-"<<dc1<<"\n";
	for(i=var.begin;i<=var.end;i++)
	{
		cout<<var.s[i];
	}
	cout<<"\n\n";
	bf2=var.bruteForce(var.fa);
	pr2=var.pr(var.fa);
	id2=var.incDesign(var.fa);
	dc2=var.dc(0,(strlen(var.s)-1),var.fa);
	cout<<"*******Father*******\n";
	cout<<"BruteForce-"<<bf2<<"\n";
	cout<<"Incremental Design-"<<id2<<"\n";
	cout<<"Pruning-"<<pr2<<"\n";
	cout<<"Divide and Conquer-"<<dc2<<"\n";
	for(i=var.begin;i<=var.end;i++)
	{
		cout<<var.f[i];
	}
	cout<<"\n\n";
	int diff=bf1-bf2;
	if(diff<0)
		diff=diff*-1;
	if(diff<10)
		cout<<"Test is Positive\n";
	else
		cout<<"Test is Negative\n";
	return 0;
}