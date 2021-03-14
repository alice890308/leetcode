class Solution {
public:
    string removeKdigits(string num, int k) {
        string ans = "";
        if (num.size() == k) {
            ans = "0";
            return ans;
        }
        
        int len = num.size();
        for(int i = 0; i < len; i++) {
            if (ans.size() == 0) {
                if (num[i] != '0') {
                    ans += num[i];
                }
                continue;
            }
            
            while(ans.size() > 0 && ans[ans.size()-1] > num[i] && k > 0) {
                ans.erase(ans.size()-1);
                k--;
            }
            if (ans.size() != 0 || num[i] != '0') {
                ans += num[i];
            }
        }
        if (k > 0) {
            ans.erase(ans.size()-k, ans.size());
        }
        if (ans == "") {
            ans = "0";
        }
        return ans;
    }
};
