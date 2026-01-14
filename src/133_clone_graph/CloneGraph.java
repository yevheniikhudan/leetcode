import java.util.*;

class Node {
    public int val;
    public List<Node> neighbors;

    public Node() {
        val = 0;
        neighbors = new ArrayList<Node>();
    }

    public Node(int val) {
        this.val = val;
        neighbors = new ArrayList<Node>();
    }

    public Node(int val, ArrayList<Node> neighbors) {
        this.val = val;
        this.neighbors = neighbors;
    }
}

public class CloneGraph {
    public Node cloneGraph(Node node) {
        // ...existing code...
        return null;
    }

    // Helper to build a graph from adjacency list
    private static Node buildGraph(int[][] adj) {
        if (adj.length == 0)
            return null;
        Node[] nodes = new Node[adj.length];
        for (int i = 0; i < adj.length; ++i)
            nodes[i] = new Node(i + 1);
        for (int i = 0; i < adj.length; ++i)
            for (int n : adj[i])
                nodes[i].neighbors.add(nodes[n - 1]);
        return nodes[0];
    }

    // Helper to print adjacency list
    private static void printGraph(Node node) {
        if (node == null) {
            System.out.println("[]");
            return;
        }
        Set<Integer> visited = new HashSet<>();
        List<String> res = new ArrayList<>();
        dfsPrint(node, visited, res);
        Collections.sort(res);
        System.out.println(res);
    }

    private static void dfsPrint(Node node, Set<Integer> visited, List<String> res) {
        if (visited.contains(node.val))
            return;
        visited.add(node.val);
        List<Integer> neigh = new ArrayList<>();
        for (Node n : node.neighbors)
            neigh.add(n.val);
        Collections.sort(neigh);
        res.add("(" + node.val + ", " + neigh + ")");
        for (Node n : node.neighbors)
            dfsPrint(n, visited, res);
    }

    public static void main(String[] args) {
        // Test case 1: Empty graph
        Node node = buildGraph(new int[][] {});
        Node cloned = new CloneGraph().cloneGraph(node);
        System.out.println(cloned == null); // true

        // Test case 2: Single node, no neighbors
        node = buildGraph(new int[][] { {} });
        cloned = new CloneGraph().cloneGraph(node);
        printGraph(cloned); // [(1, [])]

        // Test case 3: Two nodes, one edge
        node = buildGraph(new int[][] { { 2 }, { 1 } });
        cloned = new CloneGraph().cloneGraph(node);
        printGraph(cloned); // [(1, [2]), (2, [1])]

        // Test case 4: Four nodes, square
        node = buildGraph(new int[][] { { 2, 4 }, { 1, 3 }, { 2, 4 }, { 1, 3 } });
        cloned = new CloneGraph().cloneGraph(node);
        printGraph(cloned); // [(1, [2, 4]), (2, [1, 3]), (3, [2, 4]), (4, [1, 3])]

        // Test case 5: Three nodes, chain
        node = buildGraph(new int[][] { { 2 }, { 1, 3 }, { 2 } });
        cloned = new CloneGraph().cloneGraph(node);
        printGraph(cloned); // [(1, [2]), (2, [1, 3]), (3, [2])]
    }
}
