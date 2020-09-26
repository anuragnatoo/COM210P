#include<bits/stdc++.h>
#define vi vector<int>
#define vl vector<ll>
#define vpl vector<pair<ll,ll>>
#define mii map<int,int>
#define pii pair<int,int>
#define pb push_back
#define mpf(a,r) a.find(r)!=a.end()
#define _for(i,n) for(int i=0;i<n;i++)
#define _for_(i,a,n) for(int i=a;i<n;i++)
#define ll long long
#define mod 1000000007
using namespace std;
void coin_change(vi& coins,int n){
//upto particular denomination
// 1st method
//    int dp[n+1][coins.size()];
//    _for(i,coins.size()) dp[0][i]=1;
//    _for_(i,1,n+1){
//        _for_(j,0,coins.size()){
//            int p1,p2;
//            p1=(i-coins[j]>=0)?dp[i-coins[j]][j]:0;
//            p2=(j>0)?dp[i][j-1]:0;
//            dp[i][j]=p1+p2;}}
//        cout<<"number of ways without repeating case:"<<dp[n][coins.size()-1];
//2nd Method
int dp[n+1];
memset(dp,0,(n+1)*sizeof(int));
dp[0]=1;
_for(i,coins.size()) _for_(j,coins[i],n+1) dp[j]+=dp[j-coins[i]];
cout<<"number of ways without repeating case:"<<dp[n];}

int main(){
    vi a={2,3,5};
    coin_change(a,11);
    return(0);
}
