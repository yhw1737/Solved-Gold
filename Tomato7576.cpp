#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int m, n, r = 0;
    cin >> m >> n;
    int arr[100][100];
    queue<vector<int>> q;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            arr[i][j] = -1;
            cin >> arr[i][j];
            if (arr[i][j] == 1) q.push({i,j,0});
            if (arr[i][j] == -1) r++;
        }
    }
    int x, y, d, md;
    while(!q.empty()){
        r++;
        x = q.front()[0];
        y = q.front()[1];
        d = q.front()[2];
        md = d;
        q.pop();
        if (x+1 < n && arr[x+1][y] == 0) {q.push({x+1,y,d+1}); arr[x+1][y] = 1;}
        if (x-1 > -1 && arr[x-1][y] == 0) {q.push({x-1,y,d+1}); arr[x-1][y] = 1;}
        if (y+1 < m && arr[x][y+1] == 0) {q.push({x,y+1,d+1}); arr[x][y+1] = 1;}
        if (y-1 > -1 && arr[x][y-1] == 0) {q.push({x,y-1,d+1}); arr[x][y-1] = 1;}
    }
    if (r!=n*m) cout << -1;
    else cout << md;
}