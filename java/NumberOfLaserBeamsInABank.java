class NumberOfLaserBeamsInABank {
    public int numberOfBeams(String[] bank) {
        int previousCount = 0;
        int result = 0;

        for (String lasers : bank) {
            int count = count(lasers);
            if (count == 0)
                continue;

            result += previousCount * count;
            previousCount = count;
        }

        return result;
    }

    private int count(String s) {
        int count = 0;
        for (char c : s.toCharArray())
            if (c == '1')
                count += 1;
        return count;
    }

    public static void main(String[] args) {
        NumberOfLaserBeamsInABank s = new NumberOfLaserBeamsInABank();

        String[] bank1 = { "011001", "000000", "010100", "001000" };
        System.out.println(s.numberOfBeams(bank1) + " Expected: 8");

        String[] bank2 = { "000", "111", "000" };
        System.out.println(s.numberOfBeams(bank2) + " Expected: 0");
    }
}
