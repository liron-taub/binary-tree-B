//
// Created by Liron on 20/05/2021.
//

#ifndef MATALA5_BINARYTREE_H
#define MATALA5_BINARYTREE_H

#include <vector>
#include <iostream>

using namespace std;


namespace ariel {
    enum Order {
        INORDER, POSTORDER, PREORDER
    };

    template<class T>
    class Node {
    public:
        T value;
        //Pointers = so we can put a -1 value
        Node *leftChild;
        Node *rightChild;

        // constructors
        Node(T val) : value(val), leftChild(nullptr), rightChild(nullptr) {}

        Node(T val, Node *r, Node *l) : value(val), leftChild(l), rightChild(r) {}

    };


    template<class T>
    class BinaryTree {
    private:
        Node<T> *root;

    public:
        class iterator {
        private:
            vector<Node<T> *> flatTree;
            int currentNode;

        public:
            void preorder(Node<T> *node) {
                flatTree.push_back(node);
                if (node->leftChild != nullptr) {
                    preorder(node->leftChild);
                }
                if (node->rightChild != nullptr) {
                    preorder(node->rightChild);
                }
            }

            void postorder(Node<T> *node) {
                if (node->leftChild != nullptr) {
                    postorder(node->leftChild);
                }
                if (node->rightChild != nullptr) {
                    postorder(node->rightChild);
                }
                flatTree.push_back(node);
            }

            void inorder(Node<T> *node) {
                if (node->leftChild != nullptr) {
                    inorder(node->leftChild);
                }
                flatTree.push_back(node);
                if (node->rightChild != nullptr) {
                    inorder(node->rightChild);
                }
            }

            iterator(Node<T> *root, Order order) {

                //order is meant to tell us which method
                // we want to go through on the tree
                //the method from the enom
                if (order == INORDER) {
                    if (root != nullptr) {
                        inorder(root);
                    }
                }
                if (order == PREORDER) {
                    if (root != nullptr) {
                        preorder(root);
                    }
                }
                if (order == POSTORDER) {
                    if (root != nullptr) {
                        postorder(root);
                    }
                }
                currentNode = (root == nullptr ? -1 : 0);//if root=null, put -1,else put 0
            }

            //Access the node itself
            Node<T> *getNode() {
                return flatTree[(unsigned int)currentNode];
            }

            iterator &operator++() {
                //That we have reached the maximum size in the tree we will delete it and make the size -1
                // flatTree.clear();
                if (++currentNode == flatTree.size()) {
                    currentNode = -1;
                }
                return *this;
            }

             iterator operator++(int) {
                //That we have reached the maximum size in the tree we will delete it and make the size -1
                // flatTree.clear();
                iterator tmp = *this;
                if (++currentNode == flatTree.size()) {
                    currentNode = -1;
                }
                return tmp;
            }

            T &operator*() const {
                return flatTree[(unsigned int)currentNode]->value;
            }

            T *operator->() const {
                return &(flatTree[(unsigned int)currentNode]->value);
            }

            bool operator==(const iterator &rhs) const {
                if(currentNode != -1 && rhs.currentNode != -1){
                    return flatTree[(unsigned int)currentNode] == rhs.flatTree[(unsigned int)rhs.currentNode];
                }
                return currentNode * rhs.currentNode > 0;
            }

            bool operator!=(const iterator &rhs) const {
                return !(*this == rhs);
            }
        };

//cunstractor
        ~BinaryTree() {
            treeDel( root );
        }
        void treeDel(Node<T>* root){
            if(root!=nullptr) {
                if (root->leftChild != nullptr) {
                    treeDel(root->leftChild);
                }
                if (root->rightChild != nullptr) {
                    treeDel(root->rightChild);
                }

            delete root;
            }
        }

        BinaryTree() {
            root = nullptr;
        }

        Node<T>* treeDeepCopy(Node<T>* root){
            if(root!=nullptr){
                Node<T>* copy=new Node<T>(root->value);
                if(root->rightChild!= nullptr){
                    copy->rightChild=treeDeepCopy(root->rightChild);
                }
                if(root->leftChild!=nullptr){
                    copy->leftChild=treeDeepCopy(root->leftChild);
                }
                return copy;
            }
            return nullptr;
        }


        BinaryTree<T>& operator=( BinaryTree<T> other_tree) {
            if (root!=nullptr) {
                delete root;
            }
            root = treeDeepCopy(other_tree.root);
            return *this;
        }


        BinaryTree(BinaryTree<T> const& other_tree){
            root = treeDeepCopy(other_tree.root);
        }

        BinaryTree(BinaryTree<T>&& other)noexcept{
            root= other.root;
            other.root = nullptr;
        }
        BinaryTree<T>& operator=(BinaryTree<T>&& other)noexcept{
            if (root){
                delete root;}
            root = other.root;
            other.root = nullptr;
        }

        iterator begin() {
            return iterator(root, INORDER);
        }

        iterator end() {
            return iterator(nullptr, INORDER);
        }

        iterator begin_preorder() {
            return iterator(root, PREORDER);
        }

        iterator end_preorder() {
            return iterator(nullptr, PREORDER);

        }

        iterator begin_inorder() {
            return iterator(root, INORDER);

        }

        iterator end_inorder() {
            return iterator(nullptr, INORDER);

        }

        iterator begin_postorder() {
            return iterator(root, POSTORDER);
        }

        iterator end_postorder() {
            return iterator(nullptr, POSTORDER);
        }

        BinaryTree<T> &add_root(T tRoot) {
            if (root != nullptr) {
                root->value = tRoot;
            } else {
                root = new Node<T>(tRoot);
            }
            return *this;
        }

        BinaryTree<T> &add_left(T nodeIn, T nodeAdd) {
            for (iterator it = begin(); it != end(); ++it) {
                if (*it == nodeIn) {
                    //If he does not have a left child, build a left child
                    if (it.getNode()->leftChild == nullptr) {
                        it.getNode()->leftChild = new Node<T>(nodeAdd);
                    }
                    //Put the new content in the left child
                    it.getNode()->leftChild->value = nodeAdd;
                    return *this;
                }
            }
            throw std::invalid_argument("dosnt exist");
        }


        BinaryTree<T> &add_right(T nodeIn, T nodeAdd) {
            for (iterator it = begin(); it != end(); ++it) {
                if (*it == nodeIn) {
                    //If he does not have a right child, build a right child
                    if (it.getNode()->rightChild == nullptr) {
                        it.getNode()->rightChild = new Node<T>(nodeAdd);
                    }
                    //Put the new content in the right child
                    it.getNode()->rightChild->value = nodeAdd;
                    return *this;
                }
            }
            throw std::invalid_argument("dosnt exist");
        }

        void printF(const std::string &space, const Node<T> *node, bool Left) {
            if (node) {
                cout << space << "O──> " << node->value << std::endl;
                printF(space + (Left ? "│   " : "    "), node->leftChild, true);
                printF(space + (Left ? "│   " : "    "), node->rightChild, false);
            }
        }

        friend ostream &operator<<(ostream &os, BinaryTree<T> &tree) {
            tree.printF("", tree.root, false);
            return os;
        }
    };
}

#endif //MATALA5_BINARYTREE_H
