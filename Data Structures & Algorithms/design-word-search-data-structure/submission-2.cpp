class TrieNode {
public:
    vector<TrieNode*> children;
    bool word;

    TrieNode() : children(26, nullptr), word(false) {}
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() {
        root=new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c- 'a';
            if (!node->children[idx]) {
                node->children[idx] = new TrieNode();
            }
            node = node->children[idx];
        }
        node->word = true;
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string word, int j, TrieNode* root) {
        TrieNode* node = root;
        for (int i = j; i < word.size(); i++) {
            char c = word[i];
            int idx = c - 'a';
            if (c=='.') {
                for (TrieNode* child : node->children){
                    if (child && dfs(word, i+1, child)){
                        return true;
                    }
                }
                return false;
            }
            else {
                if (!node->children[idx]) {
                    return false;
                }
                node=node->children[idx];
            }
        }
        return node->word;
    }
};
