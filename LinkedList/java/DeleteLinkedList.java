/*
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
* */
public class LinkedList {


    /*When a member is declared static, it can be accessed before any
     objects of its class are created, and without reference to any
     object.*/
    static Node head;

    /*
    *1)1Nested static class doesn’t need reference of Outer class
    *2)  Only nested classes can be static.
    *3)  A static class cannot access non-static members of the Outer class. It can access only
     *   static members of Outer class.
     * */
    static class Node {
        int data;
        Node next;

        //consturctor:
        Node(int d){
            data=d;
            next=null;
        }
    }

    /*
    * If you do not specify it, by default the visibility is package.
    * Package means that They're visible to other classes in the same package.
    * */
    void deleteNode(Node n_head,Node node_to_remove)
    {
        //if the node_to_remove is the head of our list:
        if (n_head==node_to_remove){
            //if there is only one node in the list we wont remove it since the list can not be empty
            if (n_head.next == null){
                System.out.println("there is only one node in the list so we wont remove it since the list can " +
                        "not be empty");
                return;
            }

            n_head.data=n_head.next.data;
            n_head.next=n_head.next.next;

            /*
            * in Java, the programmer need not to care for all those objects which are no longer in use.
            * Garbage collector destroys these objects.
            * it is always running in background.
            * Main objective of Garbage Collector is to free heap memory by destroying unreachable objects.
            *
            * We can also request JVM to run Garbage Collector by:
            * 1)Using System.gc() method
            * 2)Using Runtime.getRuntime().gc() method
             * */
            //free memory after removing a node from our list
            System.gc();
            return;
        }

        //if the head is not the node_to_remove
        Node cure = n_head;
        while (cure.next != node_to_remove && cure.next!=null)
        {
            //check next node
            cure=cure.next;
        }

        if (cure.next == null){
            System.out.println("the node you want to remove is not in the list,try again");
            return;
        }

        cure.next= cure.next.next;

        //free memory
        System.gc();
    }

    void printLinkedList(Node head){
        while (head!=null){
            System.out.print(head.data + "  ");
            head=head.next;
        }
        System.out.println("");
    }

    public static void main(String[] args) {
        LinkedList list = new LinkedList();
        list.head = new Node(12);
        list.head.next = new Node(15);
        list.head.next.next = new Node(10);
        list.head.next.next.next = new Node(11);
        list.head.next.next.next.next = new Node(5);
        list.head.next.next.next.next.next = new Node(6);
        list.head.next.next.next.next.next.next = new Node(2);
        list.head.next.next.next.next.next.next.next = new Node(3);

        System.out.println("Given Linked List :");
        list.printLinkedList(head);
        System.out.println("");

        // Let us delete the node with value 10
        System.out.println("Deleting node :" + head.next.next.data);
        list.deleteNode(head, head.next.next);

        System.out.println("Modified Linked list :");
        list.printLinkedList(head);
        System.out.println("");

        // Lets delete the first node
        System.out.println("Deleting first Node");
        list.deleteNode(head, head);
        System.out.println("Modified Linked List");
        list.printLinkedList(head);

    }

}
