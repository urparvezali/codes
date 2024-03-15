class Node{
	int data;
	Node next;
	public Node(int d){
		this.data=d;
		this.next=null;
	}
}

/**
 * Linked
 */
class Linked {
	Node head;
	public Linked(){
		this.head=null;
	}
	
	public void add(int d){
		Node newnode = new Node(d);
		newnode.next=head;
	}


	public static void main(String[] args) {
		Linked list = new Linked();
		list.add(65);
	}
}