#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;

struct FibNode {
    int key;
    int degree;
    FibNode *parent;
    FibNode *child;
    FibNode *left;
    FibNode *right;
    bool mark;

    FibNode(int k) : key(k), degree(0), parent(nullptr), child(nullptr), mark(false) {
        left = right = this;
    }
};

struct FibHeap {
    FibNode *min;
    int n;

    FibHeap() : min(nullptr), n(0) {}

    void insert(int key) {
        FibNode* node = new FibNode(key);
        if (!min) {
            min = node;
        } else {
            node->right = min;
            node->left = min->left;
            min->left->right = node;
            min->left = node;
            if (node->key < min->key)
                min = node;
        }
        n++;
    }

    void cut(FibNode *x, FibNode *y) {
        if (x->right == x) {
            y->child = nullptr;
        } else {
            x->right->left = x->left;
            x->left->right = x->right;
            if (y->child == x)
                y->child = x->right;
        }
        y->degree--;

        x->right = min;
        x->left = min->left;
        min->left->right = x;
        min->left = x;

        x->parent = nullptr;
        x->mark = false;
    }

    void cascadingCut(FibNode *y) {
        FibNode *z = y->parent;
        if (z) {
            if (!y->mark) {
                y->mark = true;
            } else {
                cut(y, z);
                cascadingCut(z);
            }
        }
    }

    void decreaseKey(FibNode *x, int newKey) {
        if (newKey > x->key) {
            cout << "New key is greater than current key\n";
            return;
        }
        x->key = newKey;
        FibNode *y = x->parent;
        if (y && x->key < y->key) {
            cut(x, y);
            cascadingCut(y);
        }
        if (x->key < min->key)
            min = x;
    }

    FibNode* search(FibNode *min, int key) {
        if (!min) return nullptr;
        FibNode *found = nullptr, *start = min;
        do {
            if (start->key == key) {
                found = start;
                break;
            }
            if (start->child) {
                found = search(start->child, key);
                if (found) break;
            }
            start = start->right;
        } while (start != min);
        return found;
    }

    void printHeap() {
        if (!min) return;

        vector<int> keys;
        FibNode *start = min;
        do {
            keys.push_back(start->key);
            start = start->right;
        } while (start != min);

        sort(keys.begin(), keys.end());

        for (int key : keys) {
            cout << key << " ";
        }
        cout << endl;
    }
};

int main() {
    FibHeap heap;
    int n, key;

    cout << "Enter number of elements to insert: ";
    cin >> n;

    cout << "Enter the keys to insert:\n";
    for (int i = 0; i < n; ++i) {
        cin >> key;
        heap.insert(key);
    }

    char choice;
    cout << "Do you want to decrease a key? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        int oldKey, newKey;
        cout << "Enter the key to decrease: ";
        cin >> oldKey;
        cout << "Enter the new key value: ";
        cin >> newKey;

        FibNode *node = heap.search(heap.min, oldKey);
        if (node) {
            heap.decreaseKey(node, newKey);
        } else {
            cout << "Key not found in the heap.\n";
        }
    }

    cout << "Heap in sorted order: ";
    heap.printHeap();

    return 0;
}
