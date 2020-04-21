/*
Created on Mon Feb 25 2019
@author: anuragnatoo
*/
#include <iostream>
using namespace std;
class Exchange
{
	public:
	void ex(void)
	{
		int amount;
		cout<<"Enter the amount: ";
		cin>>amount;
		int temp = amount;
		int deno[] = {2000, 500, 200, 100, 50, 20, 10, 5, 2, 1};
		for(int i = 0; i < 10; i++)
		{
			int q = temp / deno[i];
			if(q != 0)
			{
				cout<<deno[i]<<" notes are "<<q<<endl;
			}
			temp = temp % deno[i];
		}
	}
	void ex1(void)
	{
		int n, ew;
		cout<<"no. of items: ";
		cin>>n;
		int w[n];
		int pr[n];
		for(int i = 0; i < n; i++)
		{
			cout<<"Enter weight: ";
			cin>>w[i];
			cout<<"Enter price: ";
			cin>>pr[i];
		}
		cout<<"Enter the expected weight: ";
		cin>>ew;
		for(int i = 0; i < n-1; i++)
		{
			int imin = i;
			int temp1 = 0;
			int temp2 = 0;
			for(int j = i + 1; j < n; j++)
			{
				if(pr[j] < pr[imin])
					imin = j;
			}
			temp1 = pr[imin];
			temp2 = w[imin];
			pr[imin] = pr[i];
			pr[i] = temp1;
			w[imin] = w[i];
			w[i] = temp2;
		}
		for(int i = 0; i < n; i++)
		{
			cout<<pr[i]<<" ";
		}
		cout<<endl;
		for(int i = 0; i < n; i++)
		{
			cout<<w[i]<<" ";
		}
		cout<<endl;
		for(int i = n - 1; i >= 0; i--)
		{
				if(ew >= w[i])
				{
					ew = ew - w[i];
					cout<<w[i]<<" weight item is given of price "<<pr[i]<<endl;
				}
		}

	}
	void ex2(void)
	{
		int n, ew;
		cout<<"no. of items: ";
		cin>>n;
		int w[n];
		int pr[n];
		float ppw[n];
		float ftemp;
		for(int i = 0; i < n; i++)
		{
			cout<<"Enter weight: ";
			cin>>w[i];
			cout<<"Enter price: ";
			cin>>pr[i];
			ftemp = (float)pr[i]/ w[i];
			ppw[i] = ftemp;
		}
		cout<<"Enter the expected weight: ";
		cin>>ew;
		for(int i = 0; i < n-1; i++)
		{
			int imin = i;
			float temp1 = 0.0;
			int temp2 = 0;
			for(int j = i + 1; j < n; j++)
			{
				if(ppw[j] < ppw[imin])
					imin = j;
			}
			temp1 = ppw[imin];
			temp2 = w[imin];
			ppw[imin] = ppw[i];
			ppw[i] = temp1;
			w[imin] = w[i];
			w[i] = temp2;
		}
		for(int i = 0; i < n; i++)
		{
			cout<<ppw[i]<<" ";
		}
		cout<<endl;
		for(int i = 0; i < n; i++)
		{
			cout<<w[i]<<" ";
		}
		cout<<endl;
		for(int i = n - 1; i >= 0; i--)
		{
				if(ew >= w[i])
				{
					ew = ew - w[i];
					cout<<w[i]<<" weight item is given of price "<<ppw[i]* w[i]<<endl;
				}
		}

	}
    void ex3(void)
	{
		int n, ew;
		cout<<"no. of items: ";
		cin>>n;
		int w[n];
		int pr[n];
		float ppw[n];
		float ftemp;
		for(int i = 0; i < n; i++)
		{
			cout<<"Enter weight: ";
			cin>>w[i];
			cout<<"Enter price: ";
			cin>>pr[i];
			ftemp = (float)pr[i]/ w[i];
			ppw[i] = ftemp;
		}
		cout<<"Enter the expected weight: ";
		cin>>ew;
		for(int i = 0; i < n-1; i++)
		{
			int imin = i;
			float temp1 = 0.0;
			int temp2 = 0;
			for(int j = i + 1; j < n; j++)
			{
				if(ppw[j] < ppw[imin])
					imin = j;
			}
			temp1 = ppw[imin];
			temp2 = w[imin];
			ppw[imin] = ppw[i];
			ppw[i] = temp1;
			w[imin] = w[i];
			w[i] = temp2;
		}
		for(int i = 0; i < n; i++)
		{
			cout<<ppw[i]<<" ";
		}
		cout<<endl;
		for(int i = 0; i < n; i++)
		{
			cout<<w[i]<<" ";
		}
		cout<<endl;
		for(int i = n - 1; i >= 0; i--)
		{
				if(ew >= w[i])
				{
					ew = ew - w[i];
					cout<<w[i]<<" weight item is given of price "<<ppw[i]*w[i]<<endl;
				}
				else
				{
					cout<<ew<<" weight is given of price "<<ppw[i]*ew<<endl;
					return;  
				}
		}

	}
};
int main(void)
{
	Exchange e;
	e.ex();
	e.ex1();
	e.ex2();
	e.ex3();
	return 0;
}