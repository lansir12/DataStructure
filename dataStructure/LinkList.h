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

    //ָ��λ�ò���Ԫ��
    bool listInsert(int location, int age);
    bool listInsert(int location, Node* node);
    //��ͷ������Ԫ��
    bool listInsertFront(int age);
    //��β������Ԫ��
    bool listInsertEnd(int age);
    //��ȡelement
    Node* getElement(int location);
    //��ȡβ����element
    Node* getLastElement();
    //��ȡͷ����element
    Node* getFirstElement();

    //ɾ��Ԫ��
    bool listDelete(int location);
    //����Ԫ��,ͨ���������
    int findElement(int age);

private:
    Node* pm_linklist;

};
