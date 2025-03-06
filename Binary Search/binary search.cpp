#include<iohtream>
#include<vector>
using namespace std;

int binary(int t, vector<int>& arr) {
    int l= 0, h = arr.size() - 1;
    while (l <= h) {
        int mid = l + (h - l) / 2;
        if (arr[mid] == t) {
            h = mid - 1;
        } else if (arr[mid] < t) {
            l = mid + 1;
        } else {
            h = mid - 1;
        }
    }
    return l< arr.size() && arr[l] == t ? l : -1;
}

int main() {
    int t = 4;
    vector<int> a = {1,2,3,4,4,4,6,6,6,7};
    cout << binary(t, a) << " is the index";
}
