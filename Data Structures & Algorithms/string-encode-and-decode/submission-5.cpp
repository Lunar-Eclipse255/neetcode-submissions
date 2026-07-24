class Solution {
public:

    string encode(vector<string>& strs) {
        string result = "";
        for (string str : strs){
            result += std::to_string(str.length()) + "&";
            result += str;
        }
        return result;
    }

    vector<string> decode(string s) {
        std::string str = s;
        vector<string> result;
        int idx = s.find("&");
        while (idx != std::string::npos) {
            int length = stoi(str.substr(0, idx));
            result.push_back(str.substr(idx+1, length));
            str = str.substr(idx+length+1);
            idx = str.find("&");
        }
        return result;
    }
};
