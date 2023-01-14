class Solution {
public:
    string reverseParentheses(string s) {
        unordered_map<int,int> brackIndex; // <current,previous> index storing
        // Idea is that whenever I find a start of a Bracket I store its index and the previous bracket index with it

        brackIndex[0] = -1; // start bracket previous set to -1
        int previousIndex = 0;
        
        for(int i = 1; i < s.length(); i++){

            if(s[i] == '('){
                brackIndex[i] = previousIndex;
                previousIndex = i;
            }else if (s[i] == ')'){
                string temp = s.substr(previousIndex+1, i-previousIndex-1);
                reverse(temp.begin(), temp.end());

                // erase the string enclosed by the brackets
                s.erase(previousIndex+1, i - previousIndex - 1);


                // insert the reversed substring
                s.insert(previousIndex+1, temp);


                // remove the brackets
                s.erase(s.begin()+previousIndex);
                s.erase(s.begin()+(i-1));


                previousIndex = brackIndex[previousIndex];
                i-=2; // backtrack for the deleted 2 brackets   
            }


        }

        return s;

    }
};
