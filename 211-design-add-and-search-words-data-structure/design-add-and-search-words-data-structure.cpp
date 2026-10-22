class WordDictionary {
public:
    WordDictionary() {
        children.fill(nullptr);
        isEnd = false;
    }

    ~WordDictionary() {
        for (WordDictionary* child : children) delete child;
    }

    void addWord(string word) {
        WordDictionary* node = this;
        for (char c : word) {
            int i = c - 'a';
            if (!node->children[i]) node->children[i] = new WordDictionary();
            node = node->children[i];
        }
        node->isEnd = true;
    }

    bool search(string word) {
        return match(word, 0);
    }

private:
    array<WordDictionary*, 26> children;
    bool isEnd;

    bool match(string& word, int pos) {
        if (pos == (int)word.size()) return isEnd;
        char c = word[pos];
        if (c == '.') {
            for (WordDictionary* child : children)
                if (child && child->match(word, pos + 1)) return true;
            return false;
        }
        WordDictionary* child = children[c - 'a'];
        return child && child->match(word, pos + 1);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
