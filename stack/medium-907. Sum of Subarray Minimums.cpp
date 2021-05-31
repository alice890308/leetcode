/*
1. 在stack中存放單調遞增的數列，stack中的element會紀錄該數字的值以及在arr中的index
2. 開一個陣列記錄該數字作為右邊界時，所有sub array的總和
3. 從左到右iterate所有數字。每個數字都會和當前stack的top比較，如果比top還要小的話，就把stack的top pop掉。最終會找到一個比自己小，或是將stack中的element全部清空。此時這個數字作為右邊界時的
   sub array總和就是：top(stack中的top)記錄在陣列中的總和值，加上(該數字的index - top的index) * 該數字的值。
4. 最後跑一次迴圈把陣列中的值加總，就是答案了
*/

class Solution {
public:
    int sum[30010];
    
    int sumSubarrayMins(vector<int>& arr) {
        //init
        for(int i = 0; i < 30010; i++)
            sum[i] = -1;
        vector<pair<int, int> > stk; // first is value, second is the index in input array
        stk.push_back(make_pair(-1, -1)); // dummy element, to make sure the stack never being empty
        
        int len = arr.size();
        pair<int, int> top;
        sum[0] = arr[0];
        stk.push_back(make_pair(arr[0], 0));
        for(int i = 1; i < len; i++) {
            while (stk[stk.size()-1].first > arr[i]) {
                stk.pop_back();
            }
            top = stk[stk.size()-1];
            stk.push_back(make_pair(arr[i], i));
            sum[i] = arr[i]*(i-top.second);
            if (top.second != -1) {
                sum[i] += sum[top.second];
            }
            sum[i] = sum[i] % 1000000007;
        }
        
        int ans = 0;
        for(int i = 0; i < len; i++) {
            //cout << sum[i] << '\n';
            ans += sum[i];
            ans = ans % 1000000007;
        }
        return ans;
    }
};
