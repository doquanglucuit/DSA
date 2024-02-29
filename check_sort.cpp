#include<bits/stdc++.h>

using namespace std;
using namespace chrono;

high_resolution_clock::time_point tBegin, tEnd;
duration<double> exec_time;

int rd (int L, int R) {
    return 1LL * rand() * rand() % (R - L + 1) + L;
}

const int MAXN = 1e6 + 5;

int N;
int arr[MAXN];
int clone_arr[MAXN];
vector<int> z;

void input () {
    N = rd(3000, 3000);
    z.clear();
    for (int i = 0; i < N; i++) {
        int x = rd(1, 30);
        z.emplace_back(x);
        arr[i] = x;
    }
}

void quick_sort (int left, int right) {
    if (left >= right) return ;
    int tmp = rd(left, right);
    int L = left, R = right;

    while (R - L + 1 >= 3) {
        while (L < tmp and arr[L] <= arr[tmp]) L++;
        while (tmp < R and arr[tmp] < arr[R]) R--;

        if (L < tmp and tmp < R) {
            swap(arr[L], arr[R]);
            L++;
            R--;
        }
        else {
            int pos = (R + L) >> 1;
            swap(arr[pos], arr[tmp]);
            swap(pos, tmp);
        }
    }
    assert(L == tmp or R == tmp);
    assert(L <= R);
    if (arr[L] > arr[R]) {
        if (L == tmp) tmp++;
        else tmp--;
        swap(arr[L], arr[R]);
    }
    quick_sort(left, tmp - 1);
    quick_sort(tmp + 1, right);
}

void heapify(int n, int i) {
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    if (l < n && arr[l] > arr[largest])
        largest = l;

    if (r < n && arr[r] > arr[largest])
        largest = r;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(n, largest);
    }
}

void heap_sort (int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(n, i);

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        heapify(i, 0);
    }
}

void merge_sort (int L, int R) {
    if (L == R) return ;

    int M = (L + R) >> 1;
    merge_sort(L, M);
    merge_sort(M + 1, R);

    int i = L, j = M + 1;

    int pos = 0;

    while (i <= M and j <= R) {
        if (arr[i] <= arr[j]) clone_arr[pos++] = arr[i++];
        else if (arr[i] > arr[j]) clone_arr[pos++] = arr[j++];
    }

    while (i <= M) clone_arr[pos++] = arr[i++];
    while (j <= R) clone_arr[pos++] = arr[j++];

    for (int i = L; i <= R; i++) arr[i] = clone_arr[i - L];
}

void solve () {
    sort(z.begin(), z.end());
    // heap_sort(N);
    // quick_sort(0, N - 1);
    // merge_sort(0, N - 1);
    for (int i = 0; i < N; i++) if (arr[i] != z[i]) {
        cout << "WA\n\n";
        exit(0);
    }
    cout << "OK\n\n";
}

int main () {
    srand(time(nullptr));
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int T = 100;

    while (T--) {
        input();
        solve();
    }
    return 0;
}
