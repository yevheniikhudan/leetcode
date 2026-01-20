import java.util.*;

class DSU {
    int[] parent, rank;

    public DSU(int n) {
        parent = new int[n];
        rank = new int[n];
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int node) {
        if (parent[node] != node)
            parent[node] = find(parent[node]);
        return parent[node];
    }

    boolean union(int node1, int node2) {
        int parent1 = find(node1), parent2 = find(node2);
        if (parent1 == parent2)
            return false;
        if (rank[parent1] < rank[parent2])
            parent[parent1] = parent2;
        else if (rank[parent2] < rank[parent1])
            parent[parent2] = parent1;
        else {
            parent[parent1] = parent2;
            rank[parent1]++;
        }
        return true;
    }
}

public class RedundantConnection {
    public int[] findRedundantConnection(int[][] edges) {
        int n = edges.length;
        DSU dsu = new DSU(n);
        for (int[] edge : edges) {
            int src = edge[0] - 1, dst = edge[1] - 1;
            if (!dsu.union(src, dst))
                return new int[] { edge[0], edge[1] };
        }
        return new int[0];
    }

    // Test scaffolding
    public static void main(String[] args) {
        RedundantConnection sol = new RedundantConnection();
        System.out.println(Arrays.toString(sol.findRedundantConnection(new int[][] { { 1, 2 }, { 1, 3 }, { 2, 3 } }))
                + " | [2,3]");
        System.out.println(Arrays
                .toString(sol.findRedundantConnection(new int[][] { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 4 }, { 1, 5 } }))
                + " | [1,4]");
        System.out.println(Arrays.toString(sol.findRedundantConnection(new int[][] { { 1, 2 }, { 2, 3 }, { 3, 1 } }))
                + " | [3,1]");
        System.out.println(Arrays
                .toString(sol.findRedundantConnection(new int[][] { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 4, 1 }, { 1, 5 } }))
                + " | [4,1]");
    }
}
