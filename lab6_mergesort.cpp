/*
Created on Mon Feb 18 2019
@author: anuragnatoo
*/
#include<iostream>
#include <string.h>
using namespace std;
struct node
{
    char w[10];
    char sy[10];
};
struct node d[5];
struct node z[5];
class Sort
{
    public:
    void mergesort(struct node a[], int beg, int end)
    {
        if(beg < end)
        {
            int mid = beg + (end - beg) / 2;
            mergesort(a, beg, mid);
            mergesort(a, mid +1, end);
            merge(a, beg, mid, end);
        }
    }
    void merge(struct node a[], int beg, int mid, int end)
    {
        int i , j, k;
        int n1 = mid - beg + 1;
        int n2 = end - mid;
        struct node b[n1];
        struct node c[n1];
        for(i = 0; i < n1; i++)
        {
            strcpy(b[i].w ,a[beg + i].w);
            strcpy(c[i].w ,a[beg + i].sy);
        }
        for(j = 0; j < n2; j++)
        {
            strcpy(b[j].sy ,a[mid + 1 + j].w);
            strcpy(c[j].sy ,a[mid + 1 + j].sy);
        }
        i = 0;
        j = 0;
        k = beg;
        while(i < n1 && j < n2)
        {
            if(strcmp(b[i].w, b[j].sy) < 0)
            {
                strcpy(a[k].w , b[i].w);
                strcpy(a[k].sy , c[i].w);
                i++;
                k++;
            }
            else
            {
                strcpy(a[k].w , b[j].sy);
                strcpy(a[k].sy , c[j].sy);
                j++;
                k++;
            }
        }
        while(i < n1)
        {
            strcpy(a[k].w , b[i].w);
            strcpy(a[k].sy , c[i].w);
            i++;
            k++;
        }
        while(j < n2)
        {
            strcpy(a[k].w , b[j].sy);
            strcpy(a[k].sy , c[j].sy);
            j++;
            k++;
        }

    }
    void isort(struct node a[], int n)
    {
        int i, j;
        char temp[10];
        char syn[10];
        for(int i = 1; i < n; i++)
        {
            for(int j = i; j > 0; j--)
            {
                if(strcmp(a[j].w, a[j - 1].w) < 0)
                {
                    strcpy(temp , a[j].w);
                    strcpy(syn , a[j].sy);
                    strcpy(a[j].w , a[j - 1].w);
                    strcpy(a[j].sy , a[j - 1].sy);
                    strcpy(a[j - 1].w , temp);
                    strcpy(a[j - 1].sy , syn);
                }
                else
                break;
            } 
        }
    }
};
int main(void)
{
    Sort s;
    int n;
    cin>>n;
    int q;
    for(q = 0; q < n; q++)
    {
        cin>>d[q].w;
        cin>>d[q].sy;
    }
    s.mergesort(d, 0, n-1);
    for(int r = 0; r < n; r++)
    cout<<d[r].w<<" ";
    cout<<endl;
    for(int x = 0; x < n; x++)
    cout<<d[x].sy<<" ";
    cout<<endl;
    cin>>d[q].w;
    cin>>d[q].sy;
    s.isort(d, n + 1);
    for(int r = 0; r < n + 1; r++)
    cout<<d[r].w<<" ";
    cout<<endl;
    for(int x = 0; x < n + 1; x++)
    cout<<d[x].sy<<" ";
    cout<<endl;
    return 0;
}