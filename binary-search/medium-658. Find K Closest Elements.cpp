class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int less;
        auto itr = lower_bound(arr.begin(), arr.end(), x);
        if (itr == arr.end()) {
            less = arr.size()-1;
        }
        else {
            less = itr-arr.begin();
        }
        auto greater = less;
        if (less != 0 && x - arr[less-1] <= arr[less]-x) {
            less = less-1;
            greater = less;
        } // 確保less和greater一開始都指向距離最小的element
        while(--k) {
            if (less == 0 && greater != arr.size()-1) {
                greater++;
                continue;
            }
            else if (less != 0 && greater == arr.size()-1) {
                less--;
                continue;
            }
            else if (less == 0 && greater == arr.size()-1) {
                break;
            }
            if (x - arr[less-1] <= arr[greater+1] - x) {
                less = less - 1;
            }
            else {
                greater = greater + 1;
            }
        }
        return vector<int>(arr.begin()+less, arr.begin()+greater+1);
    }
};
