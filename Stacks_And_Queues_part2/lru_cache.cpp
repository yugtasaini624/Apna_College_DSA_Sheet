/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache. If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.


Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.

*/

#include<iostream>
#include<unordered_map>
using namespace std;

struct Node {
    int key, value;
    Node *next, *prev;

    Node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    int cap;
    unordered_map<int, Node*> mp;

    Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    void deleteNode(Node *delNode) {
        Node *nextNode = delNode->next;
        Node *prevNode = delNode->prev;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertNode(Node *addNode) {
        Node *temp = head->prev;

        temp->next = addNode;
        addNode->prev = temp;

        addNode->next = head;
        head->prev = addNode;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        tail->next = head;
        head->prev = tail;
    }

    int get(int key) {
        if (mp.find(key) == mp.end()) {
            return -1;
        }

        Node *getNode = mp[key];

        deleteNode(getNode);
        insertNode(getNode);

        return getNode->value;
    }

    void put(int key, int value) {
        if (mp.find(key) == mp.end()) {
            if (mp.size() == cap) {
                Node *lruNode = tail->next;

                deleteNode(lruNode);
                mp.erase(lruNode->key);
                delete lruNode;
            }

            Node *newNode = new Node(key, value);
            insertNode(newNode);
            mp[key] = newNode;
        }
        else {
            Node *putNode = mp[key];
            deleteNode(putNode);
            putNode->value = value;
            insertNode(putNode);
        }
    }
};

#include <bits/stdc++.h>
using namespace std;

int main() {
    LRUCache cache(2);

    cache.put(1, 10);
    cache.put(2, 20);

    cout<<cache.get(1)<<endl; 

    cache.put(3, 30);              // removes key 2

    cout<<cache.get(2)<<endl;  // -1

    cache.put(4, 40);              // removes key 1

    cout<<cache.get(1)<<endl;  // -1
    cout<<cache.get(3)<<endl;  // 30
    cout<<cache.get(4)<<endl;  // 40

    return 0;
}