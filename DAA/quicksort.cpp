#include <bits/stdc++.h>
using namespace std;

// Global RNG for randomized partition
static std::mt19937 rng(std::random_device{}());

// ---------------- Deterministic partition (pivot = first element) ----------------
int partition_det(int low, int high, vector<int>& arr) {
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void qsort_det(int low, int high, vector<int>& v) {
    if (low < high) {
        int pindex = partition_det(low, high, v);
        qsort_det(low, pindex - 1, v);
        qsort_det(pindex + 1, high, v);
    }
}

// ---------------- Randomized partition (pivot chosen randomly) ----------------
int partition_rand(int low, int high, vector<int>& arr) {
    // pick a random index in [low, high] and swap it with arr[low]
    std::uniform_int_distribution<int> dist(low, high);
    int pivotIndex = dist(rng);
    swap(arr[low], arr[pivotIndex]);

    // same Hoare-style partition as deterministic version
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    while (true) {
        while (i <= high && arr[i] <= pivot) i++;
        while (j >= low + 1 && arr[j] > pivot) j--;
        if (i >= j) break;
        swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void qsort_rand(int low, int high, vector<int>& v) {
    if (low < high) {
        int pindex = partition_rand(low, high, v);
        qsort_rand(low, pindex - 1, v);
        qsort_rand(pindex + 1, high, v);
    }
}

// ---------------- Utility to print vector ----------------
void print_vec(const vector<int>& v, const string& label) {
    cout << label;
    for (int x : v) cout << x << " ";
    cout << "\n";
}

int main() {
    vector<int> original = {3,4,2,1,5,8,6,7};

    // Deterministic quicksort
    vector<int> a = original;
    qsort_det(0, (int)a.size() - 1, a);
    print_vec(a, "Deterministic (pivot = first) sorted: ");

    // Randomized quicksort (non-deterministic)
    vector<int> b = original;
    qsort_rand(0, (int)b.size() - 1, b);
    print_vec(b, "Randomized pivot sorted: ");

    // Show that randomized ordering of pivot selection won't change final sorted output,
    // but internals (pivot positions / recursion shape) will differ.
    return 0;
}
