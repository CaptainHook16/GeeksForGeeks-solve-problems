from __future__ import print_function
"""
Given two numbers represented by two linked lists, write a function that returns sum list.
The sum list is linked list representation of addition of two input numbers.
 It is not allowed to modify the lists. Also, not allowed to use explicit extra space (Hint: Use Recursion).
"""

"""
first try-using extra space:
"""

class Node:
    def __init__(self,v):
        self.data = v
        self.next = None
        self.cure = None


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

    def PushStartList(self,c):
        node = Node(c)
        node.next = self.head
        self.head = node

    def CalculateSum(self):
        sum_str = ""
        is_negative=False
        if self.head is None:
            print("the list is empty")
            return 0
        cure = self.head
        if cure.char == "-":
            is_negative=True
            cure=cure.next

        while(cure):
            sum_str = sum_str+cure.char
            cure=cure.next
        if is_negative:
            return (-1)*int(sum_str)
        else:
            return int(sum_str)

    def getListLen(self):
        cure = self.head
        len = 0
        while(cure != None):
            len = len+1
            cure = cure.next
        return len

    def printList(self):
        cure = self.head
        while(cure):
            print (cure.data ,end=" ")
            cure = cure.next

    """
    second solution: Recursion
    """
carry = 0

result =LinkedList()
def AddSameSizeList(head1,head2):
    global carry
    global result
    if head1==None:
        return

    AddSameSizeList(head1.next,head2.next)

    sum = head1.data + head2.data + carry
    carry= sum/10
    sum = sum%10
    #print(sum)
    # global result
    result.PushStartList(sum)

def addRemaining(head1,cure):
    global carry,result
    if head1 is not cure:
        addRemaining(head1.next,cure)
        sum = carry+head1.data
        carry = sum/10
        sum = sum % 10

        result.PushStartList(sum)

def addTwoList(l1,l2):
    global result
    if l1.head is None:
        result = l2.head

    if l2.head is None:
        result = l1.head

    len1 = l1.getListLen()
    len2 = l2.getListLen()

    if len1 == len2:
        AddSameSizeList(l1.head,l2.head)

    else:
        if(len2<len1):
            diff = abs(len1-len2)
            temp = l1.head
            while(diff>=0):
                l1.cure = temp
                temp = temp.next
                diff -=1

            AddSameSizeList(l1.cure,l2.head)

            addRemaining(l1.head,l1.cure)

        else:
            diff = abs(len1 - len2)
            temp = l2.head
            while (diff >= 0):
                l2.cure = temp
                temp = temp.next
                diff -= 1

            AddSameSizeList(l2.cure, l1.head)

            addRemaining(l2.head,l2.cure)
    if carry>0:
        result.PushStartList(carry)










l1= LinkedList()
l1.PushNode(9)
l1.PushNode(9)
l1.PushNode(9)

l1.printList()

l12= LinkedList()
l12.PushNode(1)
l12.PushNode(8)
# l12.PushNode(4)

# AddSameSizeList(l1.head,l12.head)
# if carry>0:
#     result.PushStartList((carry))

addTwoList(l1,l12)
print("")
result.printList()





# list1 = LinkedList()
# list1.PushNode('1')
# list1.PushNode('2')
# list1.PushNode('3')
#
# print list1.CalculateSum()








