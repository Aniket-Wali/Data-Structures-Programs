//import edu.princeton.cs.algs4.*;
import java.util.*;
import java.util.NoSuchElementException;

public class LinkedLists{
    private int n;         // number of elements on queue
    private Node first;    // beginning of queue
    private Node last;     // end of queue


    private class Node {
        private String item;
        private Node next;
    }

    public LinkedLists() {
        first = null;
        last  = null;
        n = 0;
    }

    public boolean isEmpty() {
        return first == null;
    }


    public void enqueue(String item) {
        Node oldlast = last;
        last = new Node();
        last.item = item;
        last.next = null;
        if (isEmpty()) first = last;
        else           oldlast.next = last;
        n++;
    }

    public void printList(){
        Node temp = first;
        while(temp.next!=null){
            System.out.print(temp.item);
        }
        System.out.println();
    }

    public static void main(String[] args) {
        LinkedLists queue = new LinkedLists();
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        queue.enqueue(str);
        queue.printList();
    }
}

