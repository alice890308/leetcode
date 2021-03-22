class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    static bool for_lower_bound(vector<int> a, vector<int> b) {
        if (a[0] < b[0] && a[1] < b[1]) {
            return true;
        }
        else {
            return false;
        }
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        vector<vector<int> > arr;
        
        sort(envelopes.begin(), envelopes.end(), cmp);
        for(int i = 0; i < envelopes.size(); i++) {
            if (arr.empty()) {
                arr.push_back(envelopes[i]);
            }
            else {
                if (arr.back()[0] < envelopes[i][0] && arr.back()[1] < envelopes[i][1]) {
                    arr.push_back(envelopes[i]);
                }
                else {
                    *lower_bound(arr.begin(), arr.end(), envelopes[i], for_lower_bound) = envelopes[i];
                }
            }
        }
        return arr.size();
    }
};
