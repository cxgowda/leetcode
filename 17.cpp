class Solution {
public:
    vector<string> letterCombinations(string digits) {
          if (digits.empty()) return {};
        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };
        vector<string> result;
        result.push_back("");   // start with empty string
        for (char d : digits) {
            vector<string> temp;
            string letters = mapping[d - '0'];
            
            for (string s : result) {
                for (char c : letters) {
                    temp.push_back(s + c);
                }
            }
            result = temp;
        }
        return result;
    }
};