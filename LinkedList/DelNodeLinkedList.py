# -*- coding: utf-8 -*-
from __future__ import print_function
"""
* Given a Singly Linked List, write a function to delete a given node.
* Your function must follow following constraints:
1) It must accept pointer to the start node as first parameter and node to
 be deleted as second parameter i.e., pointer to head node is not global.
2) It should not return pointer to the head node.
3) It should not accept pointer to pointer to head node.

You may assume that the Linked List never becomes empty.

Let the function name be deleteNode(). In a straightforward implementation,
the function needs to modify head pointer when the node to be deleted is first node.
As discussed in previous post, when a function modifies the head pointer, the function
must use one of the given approaches, we can’t use any of those approaches here.
"""


class Node:
    def __init__(self, d):
        self.data = d
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None



    def deleteNode(self,head,node_to_remove):
        if head==node_to_remove:
            if head.next == None:
                print ("there is only one node in the list so we wont remove it since the list can not be empty")
                return

            head.data=head.next.data
            head.next = head.next.next

        cure = head
        while cure.next is not node_to_remove and cure.next is not None:
            cure = cure.next

        if cure.next == None:
            print ("the node you want to remove is not in the list,try again")
            return

        cure.next = cure.next.next

    def printList(self):
        cure = self.head
        while(cure):
            print (cure.data ,end=" ")
            cure = cure.next



list = LinkedList()
new_node = Node(5)
list.head = new_node
list.head.next = Node(15)
list.head.next.next = Node(10)
list.head.next.next.next = Node(11)
list.head.next.next.next.next = Node(5)
list.head.next.next.next.next.next = Node(6)
list.head.next.next.next.next.next.next = Node(2)
list.head.next.next.next.next.next.next.next = Node(3)

print("Given Linked List :")

list.printList()
print("")

print("Deleting node : "+str(list.head.next.next.data))
list.deleteNode(list.head, list.head.next.next)

print("Modified Linked list :")
list.printList()
print("")

#remove the first node
print("Deleting first Node")
list.deleteNode(list.head,list.head)
print("Modified Linked list :")
list.printList()