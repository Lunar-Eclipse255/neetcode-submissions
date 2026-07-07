class Solution {
public:

    string encode(vector<string>& strs) {
        string combined_str;
        string str_sizes;
        if (strs.size()== 0) {
            return "";
        }
        for (int i = 0; i<strs.size(); i++){
            str_sizes+= to_string(strs[i].length()) +",";
            combined_str += strs[i];
        }
        str_sizes+="#";
        return str_sizes+combined_str;
    }

    vector<string> decode(string s) {
        if (s.empty()) return {};
        vector<int> sizes;
        vector<string> decoded;
        int i = 0;
        while (s[i] != '#') {
            string cur_val="";
            while (s[i] != ',') {
                cur_val += s[i];
                i++;
            }
            i++;
            sizes.push_back(stoi(cur_val));
        }
        int index=i+1;
        for (int element : sizes) {
            decoded.push_back(s.substr(index,element));
            index+=element;
        }
        return decoded;
    }
};
