#include <iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N, K, M = 0;
	cin >> N >> K;

	int dp[100001] = { 0 };

	while (N--) {
		int W, V;
		cin >> W >> V;
		for (int i = K; i >= W; i--) {
			dp[i] = max(dp[i], dp[i - W] + V);
		}
	}

	int m = 0;

	for (int i = 0; i <= K; i++) {
		m = max(m, dp[i]);
	}

	cout << m;

	return 0;
}