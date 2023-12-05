#include <bits/stdc++.h>
using namespace std;
int arr[1001][1001];
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    string a, b;
    cin >> a >> b;
    int al, bl;
    al = a.length();
    bl = b.length();
    for(int i=0;i<=al;i++){
        for(int j=0;j<=bl;j++){
            if (i==0 || j==0) {arr[i][j] = 0;}
            else{
                if (a[i-1] == b[j-1]){
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                else{
                    if (arr[i][j-1] > arr[i-1][j]) arr[i][j] = arr[i][j-1];
                    else arr[i][j] = arr[i-1][j];
                }
            }
        }
    }
    cout << arr[al][bl];
}