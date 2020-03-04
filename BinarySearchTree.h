//
// Created by Macbook Pro on 04/03/2020.
//

#ifndef BINARYTREE_BINARYSEARCHTREE_H
#define BINARYTREE_BINARYSEARCHTREE_H
#include <iostream>
#include <algorithm>
using namespace std;

//
// Определение шаблона класса BinarySearchTree
//
template <class T>
class BinarySearchTree
{
private:
    // Описание структуры узла со ссылками на детей
    struct Node {
        T  key_;         // значение ключа, содержащееся в узле
        Node* left_;     // указатель на левое поддерево
        Node* right_;    // указатель на правое поддерево
        Node* p_;        // указатель на  родителя !!! не используется
        // Конструктор узла
        Node(const T& key, Node* left = nullptr, Node* right = nullptr,
             Node* p = nullptr) :
                key_(key), left_(left), right_(right), p_(p)
        {  }
        ~Node() = default;
    };
    // Дерево реализовано в виде указателя на корневой узел.
    Node* root_;
public:

    // Конструктор "по умолчанию" создает пустое дерево
    BinarySearchTree() : root_(nullptr)
    {

    }
    // Деструктор освобождает память, занятую узлами дерева
    virtual ~BinarySearchTree()
    {
        deleteSubtree(root_);
    }

    // Печать строкового изображения дерева в выходной поток out
    void print(ostream& out) const
    {
        printNode(out, root_);
        out << endl;
    }

    // Функция поиска по ключу в бинарном дереве поиска
    bool iterativeSearch(const T& key)  const
    {
        return (iterativeSearchNode(key) != nullptr);
    }
// Вставка нового элемента в дерево, не нарушающая порядка // элементов. Вставка производится в лист дерева
    void insert(const T& key)
    {
        if (root_ == nullptr) {
            root_ = new Node(key, nullptr, nullptr, nullptr);
            return;
        }
        Node* curr = root_;
        while (curr->key_ != key) {
            if (key < curr->key_){
                if (curr->left_ == nullptr) {
                    curr->left_ = new Node(key, nullptr, nullptr, curr);
                    return;
                } else {
                    curr = curr->left_;
                }
            } else {
                if (curr->right_ == nullptr) {
                    curr->right_ = new Node(key, nullptr, nullptr, curr);
                    return;
                } else {
                    curr = curr->right_;
                }
            }
        }
        throw "Just Is";
    }
// Удаление элемента из дерева, не нарушающее порядка элементов
    void deleteKey(const T& key)
    {
        Node* curr = iterativeSearchNode(key);
        if (curr == nullptr) {
            throw "Just Not Is";
        }
        if (curr->right_ == nullptr && curr->left_ == nullptr) { // оба потомка - пустые
            Node* parent = curr->p_;
            if (parent->key_ < curr->key_) {
                parent->right_ = nullptr;
            } else {
                parent->left_ = nullptr;
            }
            delete(curr);
        } else if (curr->left_ == nullptr || curr->right_ == nullptr) { // один из потомков - пустой
            Node* child = nullptr;
            (curr->left_ != nullptr) ? child = curr->left_ : child = curr->right_;
            Node* parent = curr->p_;
            if (parent->key_ < curr->key_) {
                parent->right_ = (curr->left_ != nullptr) ? curr->left_ : curr->right_;
                child->p_ = parent;
            } else {
                parent->left_ = (curr->left_ != nullptr) ? curr->left_ : curr->right_;
                child->p_ = parent;
            }
            delete (curr);
        } else { // оба не пустые
            Node* next = getNext(curr);
            curr->key_ = next->key_;
            if (next->p_->left_ == next) {
                next->p_->left_ = next->right_;
                if (next->right_ != nullptr) {
                    next->right_->p_ = next->p_;
                }
            } else {
                next->p_->right_ = next->left_;
                if (next->left_ != nullptr)
                    next->right_->p_ = next->p_;
            }
            delete (next);
        }

    }
// Определение количества узлов дерева
    int getCount() const
    {
        return getCountSubTree(this->root_);
    }
    // Определение высоты дерева
    int getHeight() const
    {
        return getHeightSubTree(this->root_);
    }

    bool isEmpty() const {
        return root_ == nullptr;
    }
private:

    // Функция поиска адреса узла по ключу в бинарном дереве поиска
    Node* iterativeSearchNode(const T& key) const
    {
        Node* curr = root_;
        while (curr != nullptr) {
            if (curr->key_ == key) {
                return curr;
            } else if (key < curr->key_) {
                curr = curr->left_;
            } else {
                curr = curr->right_;
            }
        }
        return curr;
    }

    //
    // Рекурсивные функции, представляющие
    // рекурсивные тела основных интерфейсных методов
    //

    // Рекурсивная функция для освобождения памяти
    void deleteSubtree(Node* node)
    {
        if (node == nullptr) {
            return;
        }
        deleteSubtree(node->left_);
        deleteSubtree(node->right_);
        delete (node);
    }

    // Рекурсивная функция определения количества узлов дерева
    int getCountSubTree(Node* node) const
    {
        if (node == nullptr)
            return 0;
        return (1 + getCountSubTree(node->left_) + getCountSubTree(node->right_));
    }

    // Рекурсивная функция определения высоты дерева
    int getHeightSubTree(Node* node) const
    {
        if (node == nullptr) {
            return 0;
        }
        return max(getHeightSubTree(node->left_), getHeightSubTree(node->right_)) + 1;
    }
// Рекурсивная функция для вывода изображения дерева в выходной поток
    void printNode(ostream& out, Node* root) const
    {
        // Изображение дерева заключается в круглые скобки.
        out << '(';
        if (root) {
            // Для узлов дерева должна быть определена (или переопределена)
            // операция вывода в выходной поток <<
            out << root->key_;
            printNode(out, root->left_);
            printNode(out, root->right_);
        }
        out << ')';
    }
    // Рекурсивная функция для организации обхода узлов дерева.
    void inorderWalk(Node* node) const
    {
        if (node == nullptr) {
            return;
        }
        inorderWalk(node->left_);
        inorderWalk(node->right_);
    }

    Node* getNext(Node* node) const {
        if (node->right_ == nullptr) {
            while (node != nullptr && node->right_ == nullptr) {
                node = node->p_;
            }
            if (node == nullptr) {
                return nullptr;
            }
        }
        node = node->right_;
        while (node->left_ != nullptr) {
            node = node->left_;
        }
        return node;
    }

    Node* getMin(Node* node) const {
        if (isEmpty()) {
            return nullptr;
        }
        Node* curr = root_;
        while (curr->left_ != nullptr){
            curr = curr->left_;
        }
        return curr;
    }



}; // конец шаблона класса TreeBinarySearchTree



#endif //BINARYTREE_BINARYSEARCHTREE_H
