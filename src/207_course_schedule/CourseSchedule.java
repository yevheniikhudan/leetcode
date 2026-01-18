import java.util.*;

public class CourseSchedule {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adjList = new ArrayList<>();
        int[] inEdges = new int[numCourses];
        for (int i = 0; i < numCourses; i++) adjList.add(new ArrayList<>());
        for (int[] pair : prerequisites) {
            int dest = pair[0], src = pair[1];
            inEdges[dest]++;
            adjList.get(src).add(dest);
        }
        Queue<Integer> q = new ArrayDeque<>();
        for (int i = 0; i < numCourses; i++) {
            if (inEdges[i] == 0) q.offer(i);
        }
        int coursesFinished = 0;
        while (!q.isEmpty()) {
            int course = q.poll();
            coursesFinished++;
            for (int adj : adjList.get(course)) {
                if (inEdges[adj] > 0) inEdges[adj]--;
                if (inEdges[adj] == 0) q.offer(adj);
            }
        }
        return coursesFinished == numCourses;
    }

    // Test scaffolding
    public static void main(String[] args) {
        CourseSchedule sol = new CourseSchedule();
        System.out.println(sol.canFinish(2, new int[][]{{1,0}}) + " | true");
        System.out.println(sol.canFinish(2, new int[][]{{1,0},{0,1}}) + " | false");
        System.out.println(sol.canFinish(1, new int[][]{}) + " | true");
        System.out.println(sol.canFinish(3, new int[][]{{1,0},{2,1}}) + " | true");
        System.out.println(sol.canFinish(3, new int[][]{{1,0},{0,2},{2,1}}) + " | false");
    }
}
