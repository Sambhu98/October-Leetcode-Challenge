/*
// Definition for a Node.
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
*/
map < Node*, Node* > mem;
class Solution {
public:
    Node* cloneGraph(Node* node) {
        mem[NULL] = NULL;

        if (mem.count(node)) return mem[node];

        Node *newNode = new Node(node->val);
        mem[node] = newNode;

        for (auto n : node->neighbors)
            newNode->neighbors.push_back(cloneGraph(n));

        return newNode;
    }
};
//copied