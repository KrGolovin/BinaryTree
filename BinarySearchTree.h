//
// Created by Macbook Pro on 04/03/2020.
//

#ifndef BINARYTREE_BINARYSEARCHTREE_H
#define BINARYTREE_BINARYSEARCHTREE_H
#include <iostream>
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
    };

    // Дерево реализовано в виде указателя на корневой узел.
    Node* root_;
public:

    // Конструктор "по умолчанию" создает пустое дерево
    BinarySearchTree() : root_(nullptr)
    {}

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
//  . . .
    }
// Удаление элемента из дерева, не нарушающее порядка элементов
    void deleteKey(const T& key)
    {
        // . . .
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
private:

    // Функция поиска адреса узла по ключу в бинарном дереве поиска
    Node* iterativeSearchNode(const T& key) const
    {
        // . . .
    }

    //
    // Рекурсивные функции, представляющие
    // рекурсивные тела основных интерфейсных методов
    //

    // Рекурсивная функция для освобождения памяти
    void deleteSubtree(Node* node)
    {
        //. . .
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
        // . .
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
        // . . .
    }

}; // конец шаблона класса TreeBinarySearchTree



#endif //BINARYTREE_BINARYSEARCHTREE_H
