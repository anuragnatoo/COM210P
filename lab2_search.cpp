/*
Created on Mon Jan 14 2019
@author: anuragnatoo
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class search
{
	private:
		int a[100];
	public:
		void isort();
		int lsearch(int x);
		int bsearch(int x);
		//int avg(int a[]);
		void buildarray();
};
void search :: isort()
{
	int i,j,k;
	//int num=0;
	int swap;
	for(i=1;i<100;i++)
	{
		for(j=i;j>0;j--)
		{
			if(a[j]<a[j-1])
			{
				swap=a[j];
				a[j]=a[j-1];	
				a[j-1]=swap;
			}
			else
				break;
		}
	}
}
int search :: lsearch(int x)
{
	int i;
	int count=0;
	for(i=0;i<100;i++){
		if(x==a[i]){
			count++;
			break;
		}
		else
			count++;
	}
	return(count);
}
int search :: bsearch(int x)
{
	int mid;
	int beg=0;
	int end=99;
	int count=0;
	while(beg<=end)
	{
		mid=(beg+end)/2;
		if(x==a[mid]){
			count=1;
			break;
		}
		else if(x<a[mid]){
			end=mid-1;
			count++;
		}
		else if(x>a[mid]){
			beg=mid+1;
			count++;
		}
	}
	return(count);
}
void search::buildarray(){
	int i;
	for(i=0;i<100;i++){
		a[i]=rand()%10000;
	}
}
int main()
{
	search var;
	int i;
	int sum1=0;
	int sum2=0;
	for(i=0;i<100;i++)
	{
		int x=rand()%10000;
		var.buildarray();
		sum1=sum1+var.lsearch(x);
		//cout<<"Linear Search-Number of Comparisons="<<var.lsearch(x)<<"\n";
		var.isort();
		sum2=sum2+var.bsearch(x);
		//cout<<"Binary Search-Number of Comparisons="<<var.bsearch(x)<<"\n";
		//cout<<"\n";
	}
	cout<<"Linear Search-Number of Comparisons="<<sum1/100<<"\n";
	cout<<"Binary Search-Number of Comparisons="<<sum2/100<<"\n";
	return(0);
}