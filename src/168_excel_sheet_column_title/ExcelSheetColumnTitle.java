public class ExcelSheetColumnTitle {
    public String convertToTitle(int columnNumber) {
        StringBuilder res = new StringBuilder();
        while (columnNumber > 0) {
            int offset = (columnNumber - 1) % 26;
            res.append((char) ('A' + offset));
            columnNumber = (columnNumber - 1) / 26;
        }
        return res.reverse().toString();
    }

    public static void main(String[] args) {
        ExcelSheetColumnTitle s = new ExcelSheetColumnTitle();
        System.out.println(s.convertToTitle(1) + " | A");
        System.out.println(s.convertToTitle(28) + " | AB");
        System.out.println(s.convertToTitle(701) + " | ZY");
        System.out.println(s.convertToTitle(52) + " | AZ");
        System.out.println(s.convertToTitle(2147483647) + " | FXSHRXW");
    }
}
