#pragma once
#include "LinkList.h"

void travalList()
{
    Node* headNode = nullptr;
    LinkList list(headNode);
    list.listInsertEnd(10);
    list.listInsertEnd(12);
    list.listInsert(1, 11);

    while (headNode)
    {
        std::cout << headNode->age << std::endl;
        headNode = headNode->next;
    }
}