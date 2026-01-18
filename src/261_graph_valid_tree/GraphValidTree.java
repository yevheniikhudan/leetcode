import java.util.*;

public class GraphValidTree {
    public boolean validTree(int n, int[][] edges) {
        if (edges.length != n - 1)
            return false;
        List<List<Integer>> adjList = new ArrayList<>();
        for (int i = 0; i < n; i++)
            adjList.add(new ArrayList<>());
        for (int[] edge : edges) {
            int src = edge[0], dest = edge[1];
            adjList.get(src).add(dest);
            adjList.get(dest).add(src);
        }
        Set<Integer> visited = new HashSet<>();
        Queue<int[]> q = new ArrayDeque<>();
        q.offer(new int[] { 0, -1 });
        visited.add(0);
        while (!q.isEmpty()) {
            int[] nodeParent = q.poll();
            int node = nodeParent[0], parent = nodeParent[1];
            for (int adj : adjList.get(node)) {
                if (adj == parent)
                    continue;
                if (visited.contains(adj))
                    return false;
                visited.add(adj);
                q.offer(new int[] { adj, node });
            }
        }
        return visited.size() == n;
    }

    // Test scaffolding
    public static void main(String[] args) {
        GraphValidTree sol = new GraphValidTree();
        System.out.println(sol.validTree(5, new int[][] { { 0, 1 }, { 0, 2 }, { 0, 3 }, { 1, 4 } }) + " | true");
        System.out.println(
                sol.validTree(5, new int[][] { { 0, 1 }, { 1, 2 }, { 2, 3 }, { 1, 3 }, { 1, 4 } }) + " | false");
        System.out.println(sol.validTree(1, new int[][] {}) + " | true");
        System.out.println(sol.validTree(2, new int[][] { { 0, 1 } }) + " | true");
        System.out.println(sol.validTree(2, new int[][] {}) + " | false");
    }
}
