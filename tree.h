//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.
*/

template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    Node(const string &nodeID, const U &value) {
        id = nodeID;
        data = value;
    }
};

template <typename T>
class Tree {
private:
    Node<T>* root;
    vector<Node<T>*> allNodes;

    void findNodeHelper(Node<T>* current, const string &id, set<Node<T>*> &visited, Node<T>* &result) {
        if (current == nullptr || result != nullptr) return;
        if (visited.count(current)) return;
        visited.insert(current);

        if (current->id == id) {
            result = current;
            return;
        }

        for (int i = 0; i < current->children.size(); i++) {
            findNodeHelper(current->children[i], id, visited, result);
        }
    }

    void printHelper(Node<T>* current, set<Node<T>*> &visited) {
        if (current == nullptr) return;
        if (visited.count(current)) return;
        visited.insert(current);

        cout << "Node " << current->id << ": " << current->data << endl;
        if (current->children.empty()) {
            cout << "  Child -> (none)" << endl;
        } else {
            for (int i = 0; i < current->children.size(); i++) {
                cout << "  Child -> " << current->children[i]->id << endl;
            }
        }
        cout << endl;

        for (int i = 0; i < current->children.size(); i++) {
            printHelper(current->children[i], visited);
        }
    }

public:
    Tree() {
        root = nullptr;
    }

    void createRoot(const string &id, const T &value) {
        root = new Node<T>(id, value);
        allNodes.push_back(root);
    }

    void addNode(const string &parentID, const string &childID, const T &value) {
        Node<T>* parent = findNode(parentID);
        if (parent == nullptr) return;

        Node<T>* existingChild = findNode(childID);
        if (existingChild != nullptr) {
            parent->children.push_back(existingChild);
        } else {
            Node<T>* child = new Node<T>(childID, value);
            allNodes.push_back(child);
            parent->children.push_back(child);
        }
    }

    Node<T>* findNode(const string &id) {
        for (int i = 0; i < allNodes.size(); i++) {
            if (allNodes[i]->id == id) {
                return allNodes[i];
            }
        }
        return nullptr;
    }

    void printAll() {
        cout << "===== Story Tree =====" << endl;
        set<Node<T>*> visited;
        printHelper(root, visited);
        cout << "======================" << endl;
    }

    void playGame() {
        cout << "===== Begin Adventure =====" << endl << endl;

        Node<T>* current = root;
        while (current != nullptr) {
            cout << current->data << endl;

            if (current->children.empty()) {
                cout << "There are no further paths." << endl;
                cout << "Your journey ends here." << endl;
                break;
            }

            cout << "Choose your next action:" << endl;
            for (int i = 0; i < current->children.size(); i++) {
                cout << i + 1 << ". " << current->children[i]->data << endl;
            }

            cout << "Selection: ";
            int choice;
            cin >> choice;
            cout << endl;

            if (choice < 1 || choice > current->children.size()) {
                cout << "Invalid choice. Try again." << endl;
                continue;
            }

            current = current->children[choice - 1];
        }

        cout << endl << "===== Adventure Complete =====" << endl;
    }

    ~Tree() {
        for (int i = 0; i < allNodes.size(); i++) {
            delete allNodes[i];
        }
        allNodes.clear();
        root = nullptr;
    }
};

#endif //FA25EC3_TREE_H
