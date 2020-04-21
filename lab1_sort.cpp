/*
Created on Mon Jan 7 2019
@author: anuragnatoo
*/
#include<iostream>
#include<stdlib.h>
using namespace std;
class Sort
{
	public:
		int bubblesort(int a[])
		{
			int i,j,k;
			int swap;
			int num=0;
			for(i=1;i<50;i++)
			{
				for(j=0;j<50-i;j++)
				{
					if(a[j]>a[j+1])
					{
						swap=a[j];
						a[j]=a[j+1];	
						a[j+1]=swap;
					}
					num++;
				}
			}
			return num;
		}
		int isort(int a[])
		{
			int i,j,k;
			int num=0;
			int swap;
			for(i=1;i<50;i++)
			{
				for(j=i;j>0;j--)
				{
					num++;
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
			return num;
		}
		int selsort(int a[])
		{
			int i,j,k;
			int swap;
			int num=0;
			for(i=0;i<50;i++)
			{
				k=i;
				for(j=i+1;j<50;j++)
				{
					if(a[k]>a[j])
					{
						k=j;
					}
					num++;
				}
				if(k!=i)
				{
					swap=a[i];
					a[i]=a[k];
					a[k]=swap;
				}
			}
			return num;
		}
};
int main()
{
	Sort var;
	int t;
	cout<<"Enter the number of testcases....\n";
	cin>>t;
	int a[50];
	int x[50];
	int y[50];
	int input;
	int isize=0,icount=0;
	for(int j=0;j<t;j++)
	{
	//cout<<"Enter the input....\n";
	//cin>>input;
	for(int i=0;i<50;i++){
		a[i]=rand()%5000;
		x[i]=a[i];
		y[i]=a[i];
	}
	int num1=var.isort(a);
	int num2=var.selsort(x);
	int num0=var.bubblesort(y);
	for(int i=0;i<50;i++){
		cout<<a[i]<<"\n";
	}
	cout<<"The number of comparisons in bubble sort "<<num0<<"\n";
	cout<<"The number of comparisons in insertion sort "<<num1<<"\n";
	cout<<"The number of comparisons in selection sort "<<num2<<"\n";
	}
	return 0;
}