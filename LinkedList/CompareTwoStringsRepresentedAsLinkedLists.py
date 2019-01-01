"""
Given two linked lists, represented as linked lists (every character is a node in linked list).
Write a function compare() that works similar to strcmp(), i.e., it returns 0 if both strings are same,
1 if first linked list is lexicographically greater, and -1 if second string is lexicographically greater.
"""

class Node:
    def __init__(self,c):
        self.char = c
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None

    def PushNode(self,c):
        node_to_push = Node(c)
        cure = self.head
        #if the list is empty
        if cure == None:
            self.head = node_to_push
            return

        while(cure.next is not None):
            cure = cure.next

        cure.next = node_to_push


def compare(lst1,lst2):
    cure1 = lst1.head
    cure2 = lst2.head

    while(cure1 and cure2 and cure1.char==cure2.char):
        cure1 = cure1.next
        cure2=cure2.next

    if cure2 and cure1:
        if cure1.char > cure2.char:
            return 1
        else:
            return -1

    if cure1 and not cure2:
        return 1
    if cure2 and not cure1:
        return -1
    return 0

list1 = LinkedList()
list1.PushNode('g')
list1.PushNode('e')
list1.PushNode('k')
list1.PushNode('s')
list1.PushNode('b')

list2 = LinkedList()
list2.PushNode('g')
list2.PushNode('e')
list2.PushNode('k')
list2.PushNode('s')
list2.PushNode('e')

print compare(list1,list2)

