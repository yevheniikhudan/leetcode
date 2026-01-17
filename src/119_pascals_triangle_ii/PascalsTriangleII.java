import java.util.*;

public class PascalsTriangleII {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> res = new ArrayList<>();
        res.add(1);
        for (int line = 1; line <= rowIndex; line++) {
            List<Integer> nextLine = new ArrayList<>(Collections.nCopies(line + 1, 0));
            for (int i = 0; i < res.size(); i++) {
                nextLine.set(i, nextLine.get(i) + res.get(i));
                nextLine.set(i + 1, nextLine.get(i + 1) + res.get(i));
            }
            res = nextLine;
        }
        return res;
    }

    public static void main(String[] args) {
        PascalsTriangleII sol = new PascalsTriangleII();
        System.out.println(sol.getRow(3) + " | [1, 3, 3, 1]");
        System.out.println(sol.getRow(0) + " | [1]");
        System.out.println(sol.getRow(1) + " | [1, 1]");
        System.out.println(sol.getRow(4) + " | [1, 4, 6, 4, 1]");
        System.out.println(sol.getRow(5) + " | [1, 5, 10, 10, 5, 1]");
    }
}
