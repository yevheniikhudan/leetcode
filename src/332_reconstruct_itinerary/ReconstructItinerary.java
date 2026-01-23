import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class Solution {
    public List<String> findItinerary(List<List<String>> tickets) {
        Map<String, List<String>> adjList = new HashMap<>();
        for (List<String> ticket : tickets) {
            adjList.putIfAbsent(ticket.get(0), new ArrayList<>());
        }
        // Sort tickets in reverse order and add to adjList
        tickets.sort((a, b) -> b.get(1).compareTo(a.get(1)));
        for (List<String> ticket : tickets) {
            adjList.get(ticket.get(0)).add(ticket.get(1));
        }

        List<String> res = new ArrayList<>();

        dfs("JFK", adjList, res);

        Collections.reverse(res);
        return res;
    }

    private void dfs(String src, Map<String, List<String>> adjList, List<String> res) {
        while (adjList.containsKey(src) && !adjList.get(src).isEmpty()) {
            String dst = adjList.get(src).remove(adjList.get(src).size() - 1);
            dfs(dst, adjList, res);
        }
        res.add(src);
    }
}

public class ReconstructItinerary {
    public static void main(String[] args) {
        testFindItinerary();
    }

    public static void testFindItinerary() {
        Solution solution = new Solution();

        // Test case 1: Example 1
        List<List<String>> tickets1 = List.of(
                List.of("MUC", "LHR"),
                List.of("JFK", "MUC"),
                List.of("SFO", "SJC"),
                List.of("LHR", "SFO"));
        List<String> expected1 = List.of("JFK", "MUC", "LHR", "SFO", "SJC");
        List<String> actual1 = solution.findItinerary(tickets1);
        System.out.println(actual1 + " | " + expected1);

        // Test case 2: Example 2
        List<List<String>> tickets2 = List.of(
                List.of("JFK", "SFO"),
                List.of("JFK", "ATL"),
                List.of("SFO", "ATL"),
                List.of("ATL", "JFK"),
                List.of("ATL", "SFO"));
        List<String> expected2 = List.of("JFK", "ATL", "JFK", "SFO", "ATL", "SFO");
        List<String> actual2 = solution.findItinerary(tickets2);
        System.out.println(actual2 + " | " + expected2);

        // Test case 3: Single ticket
        List<List<String>> tickets3 = List.of(List.of("JFK", "ABC"));
        List<String> expected3 = List.of("JFK", "ABC");
        List<String> actual3 = solution.findItinerary(tickets3);
        System.out.println(actual3 + " | " + expected3);

        // Test case 4: Two tickets
        List<List<String>> tickets4 = List.of(
                List.of("JFK", "A"),
                List.of("A", "JFK"));
        List<String> expected4 = List.of("JFK", "A", "JFK");
        List<String> actual4 = solution.findItinerary(tickets4);
        System.out.println(actual4 + " | " + expected4);

        // Test case 5: Multiple from JFK
        List<List<String>> tickets5 = List.of(
                List.of("JFK", "A"),
                List.of("JFK", "B"),
                List.of("A", "JFK"));
        List<String> expected5 = List.of("JFK", "A", "JFK", "B");
        List<String> actual5 = solution.findItinerary(tickets5);
        System.out.println(actual5 + " | " + expected5);
    }
}
