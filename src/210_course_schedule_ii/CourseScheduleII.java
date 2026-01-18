import java.util.*;

public class CourseScheduleII {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adjList = new ArrayList<>();
        int[] inEdges = new int[numCourses];
        for (int i = 0; i < numCourses; i++)
            adjList.add(new ArrayList<>());
        for (int[] pair : prerequisites) {
            int dest = pair[0], src = pair[1];
            inEdges[dest]++;
            adjList.get(src).add(dest);
        }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (inEdges[i] == 0)
                q.offer(i);
        }
        int[] order = new int[numCourses];
        int idx = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            order[idx++] = course;
            for (int adj : adjList.get(course)) {
                if (inEdges[adj] > 0)
                    inEdges[adj]--;
                if (inEdges[adj] == 0)
                    q.offer(adj);
            }
        }
        if (idx == numCourses)
            return order;
        return new int[0];
    }

    // Test scaffolding
    public static void main(String[] args) {
        CourseScheduleII sol = new CourseScheduleII();
        System.out.println(Arrays.toString(sol.findOrder(2, new int[][] { { 1, 0 } })) + " | [0, 1]");
        System.out.println(Arrays.toString(sol.findOrder(2, new int[][] { { 1, 0 }, { 0, 1 } })) + " | []");
        System.out.println(Arrays.toString(sol.findOrder(1, new int[][] {})) + " | [0]");
        System.out.println(Arrays.toString(sol.findOrder(4, new int[][] { { 1, 0 }, { 2, 0 }, { 3, 1 }, { 3, 2 } }))
                + " | [0,2,1,3] or [0,1,2,3]");
        System.out.println(Arrays.toString(sol.findOrder(3, new int[][] { { 1, 0 }, { 0, 2 }, { 2, 1 } })) + " | []");
    }
}
