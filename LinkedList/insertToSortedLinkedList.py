"""
the problem:
Given a sorted linked list and a value to insert, write a function
 to insert the value in sorted way.

1) If Linked list is empty then make the node as
   head and return it.
2) If value of the node to be inserted is smaller
   than value of head node, then insert the node
   at start and make it head.
3) In a loop, find the appropriate node after
   which the input node (let 9) is to be inserted.
   To find the appropriate node start from head,
   keep moving until you reach a node GN (10 in
   the below diagram) who's value is greater than
   the input node. The node just before GN is the
   appropriate  node (7).
4) Insert the node (9) after the appropriate node
   (7) found in step 3.
"""
class Node:
    def __init__(self,value):
        self.val=value
        self.next=None

class LinkedList:
    def __init__(self):
        self.head=None

    def insertByOrderInc(self,node_to_insert):
        #if the list is empty
        if self.head == None:
            self.head=node_to_insert
            self.next=None

        elif self.head.val >= node_to_insert.val:
            temp_node = self.head
            self.head = node_to_insert
            self.head.next = temp_node

        else:
            cure = self.head
            while(cure!=None):
                if cure.next==None:
                    cure.next = node_to_insert
                    node_to_insert.next=None

                elif node_to_insert.val<=cure.next.val:
                    tmp = cure.next
                    cure.next = node_to_insert
                    node_to_insert.next = tmp

                cure=cure.next

    def push(self,node_data):
        new_node = Node(node_data)
        new_node.next = self.head
        self.head = new_node

    def printList(self):
        cure = self.head
        while(cure):
            print cure.val
            cure = cure.next


llist = LinkedList()
new_node = Node(5)
llist.insertByOrderInc(new_node)
new_node = Node(10)
llist.insertByOrderInc(new_node)
new_node = Node(7)
llist.insertByOrderInc(new_node)
new_node = Node(3)
llist.insertByOrderInc(new_node)
new_node = Node(1)
llist.insertByOrderInc(new_node)
new_node = Node(9)
llist.insertByOrderInc(new_node)
print "Create Linked List"
llist.printList()
