
#include "BinarySearchTree.h"

#include <iostream>
using namespace std;

int main()
{
    // создание пустого дерева
    BinarySearchTree <int> intTree;
    BinarySearchTree <int> intTree2;
    intTree2.insertReq(5);
    intTree2.insertReq(2);
    intTree2.insertReq(0);
    intTree2.insertReq(3);
    intTree2.insertReq(7);
    intTree2.insertReq(6);
    intTree2.insertReq(9);
    try {
        int i = -1;
        while (1) {
            i = intTree2.getNext(i);
            cout << i << ' ';
        }
    } catch (const char * e) {}
    cout << endl;

    intTree2.print(cout);
    intTree2.deleteKeyReq(7);
    intTree2.print(cout);
    try{
        intTree.deleteKeyReq(2);
    } catch(const char * e) {
        cout << e << endl;
    }
    // добавление узлов
    intTree.insertReq(10);
    intTree.insertReq(120);
    intTree.insertReq(8);
    intTree.print(cout);
    intTree.deleteKeyReq(10);
    intTree.print(cout);
    intTree.deleteKeyReq(120);
    intTree.print(cout);
    intTree.deleteKeyReq(8);
    intTree.print(cout);
    intTree.insertReq(10);
    intTree.print(cout);
    try{
        intTree.insertReq(10);
    } catch(const char * e) {
        cout << e << endl;
    }
    intTree.insertReq(3);
    intTree.print(cout);
    intTree.insertReq(20);
    intTree.print(cout);
    intTree.insertReq(15);
    intTree.print(cout);
    intTree.insertReq(30);
    intTree.print(cout);
    intTree.insertReq(2);
    intTree.print(cout);
    intTree.insertReq(5);
    intTree.print(cout);
    intTree.insertReq(32);
    intTree.print(cout);
    intTree.insertReq(22);
    intTree.print(cout);
    intTree.horizontalWalk();
    cout << endl;
    cout << intTree.getCountEven() << endl;
    int  keyFound = intTree.iterativeSearch(15); // поиск должен быть успешным
    cout << "Key " << 15 << (keyFound ? " found successfully" : " not found") << " in the tree" << endl;
    keyFound = intTree.iterativeSearch(23);      // поиск должен быть неудачным
    cout << "Key " << 23 <<(keyFound ? " found successfully" : " not found") <<" in the tree" << endl;
// определение высоты и количества узлов дерева
    cout << "height = " << intTree.getHeight() << endl;
    cout << "count =  " << intTree.getCount () << endl;
    try{
        intTree.getKey(-1);
    } catch(const char * e) {
        cout << e << endl;
    }
    for (int i = 0; i < 9; ++i) {
        cout << "tree[" << i << "] = " << intTree.getKey(i) << ' ';
    }
    cout << endl;
    try{
        intTree.getKey(9);
    } catch(const char * e) {
        cout << e << endl;
    }
    cout << endl;
    intTree.deleteKeyReq(3);
    intTree.print(cout);
    intTree.deleteKeyReq(20);
    intTree.print(cout);
    intTree.deleteKeyReq(15);
    intTree.print(cout);
    intTree.deleteKeyReq(30);
    intTree.print(cout);

    try{
        intTree.deleteKeyReq(128);
    } catch(const char * e) {
        cout << e << endl;
    }
    intTree.print(cout);
    intTree.deleteKeyReq(5);
    intTree.print(cout);
    intTree.deleteKeyReq(32);
    intTree.print(cout);
    intTree.deleteKeyReq(22);
    intTree.print(cout);
    intTree.deleteKeyReq(10);
    intTree.print(cout);
    intTree.deleteKeyReq(2);
    intTree.print(cout);
    // Вывод узлов дерева в выходной поток
    return 0;
}
