package positional;

public class LinkedList<E> implements Positional<E> {
	private static class Node<E> implements PositionList<E> {
		private E element;
		private Node<E> next;
		private Node<E> prev;

		public Node(E e,Node<E> p,Node<E> n)
		{
			element=e;
			prev=p;
			next=n;
		}
		@Override
		
		public E getElement() throws IllegalArgumentException {
			if (next==null) 
				throw new IllegalStateException("Position no longer valid");			
			return element;
		}
		public Node<E> getPrev() {
			return prev;
		}

		public Node<E> getNext() {
			return next;
		}

		public void setElement(E e) {
			element = e;
		}

		public void setPrev(Node<E> p) {
			prev = p;
		}

		public void setNext(Node<E> n) {
			next = n;
		}
	}
	private int size=0;
	private Node<E> head;
	private Node<E> trailer;
	

	
	public LinkedList() {
		head = new Node<>(null, null, null);
		// create header
		trailer = new Node<>(null, head, null);
		// trailer is preceded by header
		head.setNext(trailer);
		// header is followed by trailer
	}
	private Node<E> validate(PositionList<E> p) throws IllegalArgumentException {
		if (!(p instanceof Node))
			throw new IllegalArgumentException("Invalid p");
		Node<E> node = (Node<E>) p;
		// safe cast
		if (node.getNext() == null)
			// convention for defunct node
			throw new IllegalArgumentException("p is no longer in the list");
		return node;
	}

	/** Returns the given node as a Position (or null, if it is a sentinel). */
	private PositionList<E> position(Node<E> node) {
		if (node == head || node == trailer)
			return null;
		// do not expose user to the sentinels
		return node;
	}

	@Override
	public int size() {
		
		return size;
	}

	@Override
	public boolean isEmpty() {
		// TODO Auto-generated method stub
		return size==0;
	}

	@Override
	public PositionList<E> first() {
		// TODO Auto-generated method stub
		return position(head.getNext());
	}

	@Override
	public PositionList<E> last() {
		// TODO Auto-generated method stub
		return position(trailer.getPrev());
	}

	@Override
	public PositionList<E> before(PositionList<E> p) throws IllegalArgumentException {
		Node<E> node = validate(p);
		return position(node.getPrev());
	}

	@Override
	public PositionList<E> after(PositionList<E> p) throws IllegalArgumentException {
		
		Node<E> node = validate(p);
		return position(node.getNext());
	}
	private PositionList<E> addBetween(E e, Node<E> pred, Node<E> succ) {
		Node<E> newest = new Node<>(e, pred, succ); // create and link a new node
		pred.setNext(newest);
		succ.setPrev(newest);
		size++;
		return newest;
	}

	@Override
	public PositionList<E> addFirst(E e) {

		return addBetween(e,head,head.getNext());
	}

	@Override
	public PositionList<E> addLast(E e) {

		return addBetween(e,trailer.getPrev(),trailer);
	}

	@Override
	public PositionList<E> addBefore(PositionList<E> p, E e) throws IllegalArgumentException {

		Node<E> node = validate(p);
		return addBetween(e,node.getPrev(),node);
	}

	@Override
	public PositionList<E> addAfter(PositionList<E> p, E e) throws IllegalArgumentException {
	
		Node<E> node = validate(p);
		return addBetween(e,node,node.getNext());
	}

	@Override
	public E remove(PositionList<E> p) throws IllegalArgumentException {
		
		Node<E> node = validate(p);
		Node<E> predecessor = node.getPrev();
		Node<E> successor = node.getNext();
		predecessor.setNext(successor);
		successor.setPrev(predecessor);
		size--;
		E answer = node.getElement();
		node.setElement(null);
		node.setNext(null);
		node.setPrev(null);
		return answer;
	}

	@Override
	public E set(PositionList<E> p, E e) throws IllegalArgumentException {
		Node<E> node = validate(p);
		E answer = node.getElement();
		node.setElement(e);
		return answer;
	}

}
