class TrieNode {
public:
    bool endofWord;
    TrieNode* children[26];

    // Constructore to initialize a trie node
    TrieNode()
    {
        endofWord = false;
        for (int i = 0; i < 26; i++) {
            children[i] = nullptr;
        }
    }
};
class PrefixTree {
public:
    TrieNode* root;
    PrefixTree() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        for (char c: word){
            int idx = c - 'a';
            if (!node->children[idx]) {
                node->children[idx]=new TrieNode();
            }
            node=node->children[idx];
        }
        node->endofWord=true;
    }
    
    bool search(string word) {
        TrieNode* node = root;
        for (char c : word){
            int idx = c- 'a';
            if (!(node->children[idx])) {
                return false;
            }
            node = node->children[idx];
        }
        if (node->endofWord) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (char c : prefix){
            int idx = c- 'a';
            if (!(node->children[idx])) {
                return false;
            }
            node = node->children[idx];
        }
        return true;
    }
};
