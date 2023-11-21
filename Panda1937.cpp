#include <iostream>

using namespace std;

int n, m = 1;
int a[502][502];
int dp[502][502];

void check(int i, int j){
    if (dp[i][j] == 1){
        if (a[max(1, i-1)][j] > a[i][j]){
            check(max(1, i-1), j);
            dp[i][j] = max(dp[i][j], dp[max(1, i-1)][j] + 1);
        }
        if (a[i][max(1, j-1)] > a[i][j]){
            check(i, max(1, j-1));
            dp[i][j] = max(dp[i][j], dp[i][max(1, j-1)] + 1);
        }
        if (a[min(n, i+1)][j] > a[i][j]){
            check(min(n, i+1), j);
            dp[i][j] = max(dp[i][j], dp[min(n, i+1)][j] + 1);
        }
        if (a[i][min(n, j+1)] > a[i][j]){
            check(i, min(n, j+1));
            dp[i][j] = max(dp[i][j], dp[i][min(n, j+1)] + 1);
        }
        m = max(m, dp[i][j]);
    }
}

int main(){
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> a[i][j];
            dp[i][j] = 1;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            check(i,j);
        }
    }
    cout << m;
}