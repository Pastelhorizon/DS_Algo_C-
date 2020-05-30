class Solution {
    public:
        vector<string> wordBreak(string s, vector<string> &dictV) {
            unordered_set<string> dict(dictV.begin(), dictV.end());
            vector<vector<string> > words(s.length() + 1, vector<string>(0));

            // initialize the valid values
            words[s.length()].push_back("");

            // generate solutions from the end
            for(int i = s.length() - 1; i >= 0; i--) {
                vector<string> values;
                for(int j = i + 1; j <= s.length(); j++) {
                    if (dict.find(s.substr(i, j - i)) != dict.end()) {
                        for (int k = 0; k < words[j].size(); k++) {
                            values.push_back(s.substr(i, j - i) + (words[j][k].empty() ? "" : " ") + words[j][k]);
                        }
                    }
                }
                words[i] = values;
            }
            return words[0];
        }
};