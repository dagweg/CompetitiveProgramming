class Solution {
public:
    vector<string> topKFrequent(vector<string> words, int k) {
        map<string, int> freq;
        for(const auto& s : words){
            freq[s]++;
        }
        
        vector<pair<string, int>> vec;
        for(pair<string, int> p : freq){
            vec.push_back(p);
        }

        sort(vec.begin(), vec.end(), [](pair<string,int> p1, pair<string,int> p2){
            // if same frequency order by lex
            if(p1.second == p2.second){
                return p1.first < p2.first;
            }
            // if not by frequency
            return p1.second > p2.second;
        });

        vector<string> ret;
        for(pair<string, int> p : vec){
            ret.push_back(p.first);
        }

        return vector<string>(ret.begin(), ret.begin()+k);
    }
};
