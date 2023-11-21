#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    vector<int> a;
    int it;
    a.push_back(0);
    int temp;
    while(n--){
        cin >> temp;
        it = lower_bound(a.begin(), a.end(), temp) - a.begin();
        if (it == a.size()){
            a.push_back(temp);
        }
        else {
            a[it] = temp;
        }
    }
    cout << a.size()-1;
}
