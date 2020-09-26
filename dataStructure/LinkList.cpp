#include "LinkList.h"

LinkList::LinkList(Node* &headNode)
{
    pm_linklist = new Node;
    pm_linklist->age = -1;
    pm_linklist->name = "this head node";
    pm_linklist->next = nullptr;
    headNode = pm_linklist;
}

LinkList::~LinkList() 
{
    if (pm_linklist)
    {
        while (pm_linklist->next)
        {
            Node* p = pm_linklist->next;
            pm_linklist->next = p->next;
            delete p;
        }
        delete pm_linklist;
    }
}

bool LinkList::listInsert(int location, int age)
{
    Node* headptr = pm_linklist;
    int currentLocation = 0;
    while (headptr && currentLocation<location-1)
    {
        headptr = headptr->next;
        ++currentLocation;
    }
    if (!headptr || currentLocation >location - 1)
    {
        return false;
    }
    Node* node = new Node;
    node->age = age;
    node->next = headptr->next;
    headptr->next = node;

    return true;
}

bool LinkList::listInsert(int location, Node* node)
{
    //todo
    return false;
}

bool LinkList::listInsertFront(int age)
{
    if (!pm_linklist)
    {
        return false;
    }
    Node* node = new Node;
    node->age = age;
    node->next = nullptr;
    if (pm_linklist->next)
    {
        node->next = pm_linklist->next;
    }
    pm_linklist->next = node;
 
    return true;
}

bool LinkList::listInsertEnd(int age)
{
    while (pm_linklist)
    {
        if (!pm_linklist->next)
        {
            Node* node = new Node;
            node->age = age;
            node->next = nullptr;
            pm_linklist->next = node;
            break;
        }
        pm_linklist = pm_linklist->next;
    }
    return true;
}

Node* LinkList::getElement(int location)
{
    int j = 0;
    while (pm_linklist && j<location)
    {
        pm_linklist = pm_linklist->next;
        j++;
    }
    if (pm_linklist || j > location)
    {
        return nullptr;
    }
    return pm_linklist;
}

Node* LinkList::getFirstElement()
{
    if (pm_linklist)
    {
        return pm_linklist->next;
    }
    return nullptr;
}

bool LinkList::listDelete(int location)
{
    int j = 0;
    while (pm_linklist && j<location-1)
    {
        pm_linklist = pm_linklist->next;
        j++;
    }
    if (!pm_linklist ||j>location-1)
    {
        return false;
    }
    if (!pm_linklist->next)
    {
        return false;
    }

    Node* p = pm_linklist->next;
    pm_linklist->next = p->next;
    delete p;
    return true;
}

int LinkList::findElement(int age)
{
    int j = 0;
    while (pm_linklist)
    {
        if (pm_linklist->age == age)
        {
            return j;
        }
        j++;
        pm_linklist = pm_linklist->next;
    }
    return j;
}

Node* LinkList::getLastElement()
{
    while (pm_linklist)
    {
        if (pm_linklist->next)
        {
            return pm_linklist;
        }
        pm_linklist = pm_linklist->next;
    }

    return nullptr;
}

