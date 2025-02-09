#include <gtest/gtest.h>
#include <vector>
#include <map>

using std::vector;
using std::map;

namespace {

class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        map<int, Node*> visited;
        return clone(node, visited);
    }

    Node* clone(Node* node, map<int, Node*> &visited) {
        if (!node)
            return nullptr;
        auto it = visited.find(node->val);
        if (it != visited.end())
            return it->second;

        Node *cloned = new Node(node->val);
        visited[node->val] = cloned;

        for (auto n: node->neighbors) {
            Node *c = clone(n, visited);
            if (c)
                cloned->neighbors.push_back(c);
        }

        return cloned;
    }
};
} // namespace
