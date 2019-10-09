//
// Created by hfq on 10/9/19.
//

#include <iostream>
#include <vector>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;

    Node() {}

    Node(int _val, std::vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:
    Node* cloneGraph(Node* node) {
        std::unordered_map<Node*, Node*> mp;
        return cloneGraphCore(node, mp);
    }

    Node* cloneGraphCore(Node* node, std::unordered_map<Node*, Node*>& mp) {
        if(!node) {
            return nullptr;
        }
        if(mp.count(node)) {
            return mp[node];
        }
        auto cpNode = new Node(node->val, std::vector<Node*>());
        mp[node] = cpNode;
        for(int i = 0; i < node->neighbors.size(); i++) {
            if(node->neighbors[i]) {
                cpNode->neighbors.push_back(cloneGraphCore(node->neighbors[i], mp));
            }
        }
        return cpNode;
    }
};