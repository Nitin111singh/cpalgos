#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll p= 1000000007;
vector<vector<ll>>I={{1,0},{0,1}};
vector<vector<ll>> multiply(vector<vector<ll>>&A,vector<vector<ll>>&B)
{
    vector<vector<ll>>ans(2,vector<ll>(2,0));
    for(ll i=0;i<2;i++)
    {                 
        for(ll j=0;j<2;j++)
        {
             for(ll k=0;k<2;k++)
             {
                ans[i][j]+=((A[i][k])%p)*((B[k][j])%p)%p;
             }
        }
    }
    return ans;
}
vector<vector<ll>> power(vector<vector<ll>>&A,ll m)
{    if(m==0)
    return I;
     if(m==1)
     return A;
    vector<vector<ll>>res=power(A,m/2);
    vector<vector<ll>>ans=multiply(res,res);
     if(m%2!=0)
     {
      ans=multiply(ans,A);
     }
    return ans;

}
int main(){
    ll n;
    cin>>n;
vector<vector<ll>>A;
for(ll i=0;i<2;i++)
{   vector<ll>v;
    for(ll j=0;j<2;j++)
    {
        v.push_back(i&j?0:1);
    }
    A.push_back(v);
}
A=power(A,n);
cout<<(A[0][1])%p<<endl;
}
