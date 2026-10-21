class Trie {
public:
    Trie() {
        children.fill(nullptr);
        isEnd = false;
    }

    ~Trie() {
        for (Trie* child : children) delete child;
    }

    void insert(string word) {
        Trie* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new Trie();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        Trie* node = walk(word);
        return node && node->isEnd;
    }

    bool startsWith(string prefix) {
        return walk(prefix) != nullptr;
    }

private:
    array<Trie*, 26> children;
    bool isEnd;

    Trie* walk(string& s) {
        Trie* node = this;
        for (char c : s) {
            int i = c - 'a';
            if (!node->children[i]) return nullptr;
            node = node->children[i];
        }
        return node;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
