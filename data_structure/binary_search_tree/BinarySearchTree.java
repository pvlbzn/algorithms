package dataStructures;

import java.util.LinkedList;


public class BinarySearchTree<T extends Comparable<T>> {

    private class Node {
        private Node parent;
        private Node left;
        private Node right;
        private T data;

        public Node(T data) {
            this.data = data;
            this.parent = null;
            this.left = null;
            this.right = null;
        }

        public Node(Node parent, T data) {
            this.data = data;
            this.parent = parent;
            this.left = null;
            this.right = null;
        }
    }

    private Node root;

    public BinarySearchTree(T data) {
        root = new Node(data);
    }

    public void insert(T data) {
        insert(root, data);
    }

    private void insert(Node node, T data) {
        if (node.data.compareTo(data) < 0) {
            // Insert right
            if (node.right == null) {
                node.right = new Node(node, data);
            } else {
                insert(node.right, data);
            }
        } else if (node.data.compareTo(data) > 0) {
            // Insert left
            if (node.left == null) {
                node.left = new Node(node, data);
            } else {
                insert(node.left, data);
            }
        }
    }

    public T getMax() {
        Node tmp = root;
        while (tmp.right != null)
            tmp = tmp.right;

        return tmp.data;
    }

    public T getMin() {
        Node tmp = root;
        while (tmp.left != null)
            tmp = tmp.left;

        return tmp.data;
    }

    public boolean search(T data) {
        return search(root, data);
    }

    private boolean search(Node node, T data) {
        if (node == null) {
            return false;
        }

        if (node.data == data) {
            return true;
        }

        if (node.data.compareTo(data) < 0) {
            return search(node.right, data);
        } else if (node.data.compareTo(data) > 0) {
            return search(node.left, data);
        }

        return false;
    }

    /**
     * In order tree traversal.
     *
     * Time complexity: O(n)
     */
    public Integer[] inOrderTraversal() {
        LinkedList<Integer> storage = new LinkedList();
        traverseInOrder(root, storage);
        Integer[] res = new Integer[storage.size()];

        return storage.toArray(res);
    }

    public Integer[] preOrderTraversal() {
        LinkedList<Integer> storage = new LinkedList();
        traversePreOrder(root, storage);
        Integer[] res = new Integer[storage.size()];

        return storage.toArray(res);
    }

    public Integer[] postOrderTraversal() {
        LinkedList<Integer> storage = new LinkedList();
        traversePostOrder(root, storage);
        Integer[] res = new Integer[storage.size()];

        return storage.toArray(res);
    }

    private void traverseInOrder(Node node, LinkedList storage) {
        if (node == null)
            return;

        if (node.left != null)
            traverseInOrder(node.left, storage);

        storage.add(node.data);

        if (node.right != null)
            traverseInOrder(node.right, storage);
    }

    private void traversePreOrder(Node node, LinkedList storage) {
        if (node == null)
            return;

        storage.add(node.data);

        if (node.left != null)
            traversePreOrder(node.left, storage);

        if (node.right != null)
            traversePreOrder(node.right, storage);
    }

    private void traversePostOrder(Node node, LinkedList storage) {
        if (node == null)
            return;

        if (node.left != null)
            traverseInOrder(node.left, storage);

        if (node.right != null)
            traverseInOrder(node.right, storage);

        storage.add(node.data);
    }

    public static void main(String[] args) {
        BinarySearchTree bst = new BinarySearchTree(new Integer(4));
        bst.insert(new Integer(7));
        bst.insert(new Integer(2));
        bst.insert(new Integer(8));
        bst.insert(new Integer(5));

        Integer[] inSorted   = bst.inOrderTraversal();
        Integer[] preSorted  = bst.preOrderTraversal();
        Integer[] postSorted = bst.postOrderTraversal();

        assert inSorted[0] == 2;
        assert inSorted[1] == 4;
        assert inSorted[2] == 5;
        assert inSorted[3] == 7;
        assert inSorted[4] == 8;

        assert preSorted[0] == 4;
        assert preSorted[1] == 2;
        assert preSorted[2] == 7;
        assert preSorted[3] == 5;
        assert preSorted[4] == 8;

        assert postSorted[0] == 2;
        assert postSorted[1] == 5;
        assert postSorted[2] == 8;
        assert postSorted[3] == 7;
        assert postSorted[4] == 4;

        assert bst.getMax().compareTo(new Integer(2)) == 0;
        assert bst.getMin().compareTo(new Integer(8)) == 0;

        System.out.println("SUCCESS");
    }
}