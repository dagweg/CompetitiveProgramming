class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.rbegin(), citations.rend());

        int i = 0, n = citations.size();
        do{
            if(citations[i] < i+1)
                break;
            i++;
        }
        while(i < n);

        return i;
    }
};
