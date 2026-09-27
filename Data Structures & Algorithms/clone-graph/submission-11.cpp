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

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) {
            return nullptr;
        }

        if (oldToNew.count(node)) {
            return oldToNew[node];
        }

        oldToNew[node] = new Node(node->val);

        for (Node* originalNeighbor: node->neighbors) {
            oldToNew[node]->neighbors.emplace_back(cloneGraph(originalNeighbor));
        }
        
        return oldToNew[node];
    }

private:
    unordered_map<Node*, Node*> oldToNew{};
};
