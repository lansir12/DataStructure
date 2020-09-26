#pragma once
#include <string>

struct Node
{
    int age;
    std::string name;
    Node* next;
};

class LinkList
{
public:
    LinkList(Node* &headNode);
    ~LinkList();

    //指定位置插入元素
    bool listInsert(int location, int age);
    bool listInsert(int location, Node* node);
    //在头部插入元素
    bool listInsertFront(int age);
    //在尾部插入元素
    bool listInsertEnd(int age);
    //获取element
    Node* getElement(int location);
    //获取尾部的element
    Node* getLastElement();
    //获取头部的element
    Node* getFirstElement();

    //删除元素
    bool listDelete(int location);
    //查找元素,通过年龄查找
    int findElement(int age);

private:
    Node* pm_linklist;

};
