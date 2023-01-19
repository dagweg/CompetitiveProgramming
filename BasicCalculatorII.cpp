class Solution {
public:
    // does operation on 'x' and 'y' based on 'o'
    int doOperation(const string& o, const string& x, const string& y) const 
    {	
        int temp;
        if(o == "+")
            temp = stoi(x) + stoi(y);
        else if(o == "-")
            temp = stoi(x) - stoi(y);
        else if(o == "*")
            temp = stoi(x) * stoi(y);
        else
            temp = stoi(x) / stoi(y);
        return temp;
    }

    // high priority operand
    inline bool hpOperand(const string& s) const { return s == "*" || s == "/";}

    int calculate(string s) {
        
        // numbers and operands
        vector<string> numopers;
        // to later check if we need to return instantly if none found
        bool operandPresent = 0;
        
        // parsing to vector -> numopers
        string tmp;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == '*' || s[i] == '+' || s[i] == '-' || s[i] == '/')
            {
                if(!tmp.empty()){
                    numopers.emplace_back(tmp);
                }
                tmp="";
                tmp+=s[i];
                numopers.emplace_back(tmp);
                tmp="";
                operandPresent=1;
            }
            else if(s[i] == ' ')
            {
                if(!tmp.empty()){
                    numopers.emplace_back(tmp);
                    tmp="";
                }
                continue;
            }
            else
            {
                tmp+=s[i];
                if(i == s.size()-1){
                    if(!tmp.empty())
                        numopers.emplace_back(tmp);
                    break;
                }
            }
        }

        // multiply and divide
        int temp;
        for(int i = 1; i < numopers.size(); i++)
        {
            if(numopers[i] == "*" || numopers[i] == "/"){

                temp = doOperation(numopers[i], numopers[i-1], numopers[i+1]);
                
                numopers.erase(numopers.begin()+i-1, numopers.end()-(numopers.size()-(i+2)));
                numopers.insert(numopers.begin()+i-1, to_string(temp));
                temp = 0;
                i--;
            }	
        }

        // if no operands were present
        if(!operandPresent)
        {
            return stoi(numopers[0]);
        }

        int result = stoi(numopers[0]);
        // add and subtract
        for(int i = 0; i < numopers.size(); i++)
        {
            if(!isdigit(numopers[i][0]))
            {
                result = doOperation(numopers[i], to_string(result), numopers[i+1]);
            }
        }

        return result;

    }	
};
