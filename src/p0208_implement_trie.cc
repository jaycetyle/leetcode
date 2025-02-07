#include <gtest/gtest.h>
#include <string>
#include <map>

using std::string;
using std::map;

namespace {
struct Node {
    map<char, Node> children;
};

class Trie {
public:
    Trie() {}

    void insert(string word) {
        Node *n = &_root;

        for (auto c: word) {
            auto it = n->children.find(c);
            if (it != n->children.end()) {
                n = &it->second;
                continue;
            }
            auto ret = n->children.emplace(c, Node());
            n = &ret.first->second;
        }
        n->children.emplace('\0', Node());
    }

    Node *searchPrefix(const string &word) {
        Node *n = &_root;

        for (auto c: word) {
            auto it = n->children.find(c);
            if (it == n->children.end())
                return NULL;
            n = &it->second;
        }

        return n;
    }

    bool search(string word) {
        Node *n = searchPrefix(word);
        if (n && n->children.find('\0') != n->children.end())
            return true;
        return false;
    }

    bool startsWith(string prefix) {
        Node *n = searchPrefix(prefix);
        if (n)
            return true;
        return false;
    }

private:
    Node _root;
};

TEST(TrieTest, test1) {
    Trie trie;
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_FALSE(trie.search("app"));
    EXPECT_TRUE(trie.startsWith("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("app"));
}
} // namespace
