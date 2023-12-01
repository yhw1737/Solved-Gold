#include <bits/stdc++.h>
using namespace std;
int n;
int solve(vector<string> &a,int i,int j){
    char c=a[i][j];
    if(c=='1'){
        return 0;
    }
    a[i][j]='1';
    if(i>0) if(c==a[i-1][j]) solve(a,i-1,j);
    if(j>0) if(c==a[i][j-1]) solve(a,i,j-1);
    if(i<n-1) if(c==a[i+1][j]) solve(a,i+1,j);
    if(j<n-1) if(c==a[i][j+1]) solve(a,i,j+1);
    return 1;
}
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int i,j,r,a=0,b=0;
    vector<string> arr,arr2;
    cin>>n;
    for(i=0;i<n;i++){
        string temp;
        cin>>temp;
        arr.push_back(temp);
        for(j=0;j<temp.length();j++){
            if(temp[j]=='R') temp[j]='G';
        }
        arr2.push_back(temp);
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(solve(arr,i,j)) a++;
            if(solve(arr2,i,j)) b++;
        }
    }
    cout<<a<<' '<<b;
}