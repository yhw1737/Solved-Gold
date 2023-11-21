#include <iostream>
using namespace std;

int main() {
    int N, A[50], S;
    cin >> N;
    
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cin >> S;

    for(int j = 0; j < N; j++) { 
        int m = -1, index = -1;
        for (int i = j; i <= j + S && i < N; i++) {
            if (A[i] > m) {
                m = A[i];
                index = i;
            }
        }
        for (int i = index; i > j; i--) {
            swap(A[i], A[i - 1]);
            S--;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << A[i] << ' ';
    }

    return 0;
}