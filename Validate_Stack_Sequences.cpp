class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        ios::sync_with_stdio(0);
        cin.tie(0);

        stack<int> stk;
        int i = 0, j = 0, n = pushed.size(), m = popped.size();

        while(i < n)
        {
            stk.push(pushed[i++]);
            while(j < m && !stk.empty() && stk.top() == popped[j]){
                stk.pop();
                j++;
            }
        }
        return stk.empty();
    }
};
