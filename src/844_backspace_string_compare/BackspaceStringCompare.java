public class BackspaceStringCompare {
    public boolean backspaceCompare(String s, String t) {
        int indexS = s.length() - 1, indexT = t.length() - 1;
        while (indexS >= 0 || indexT >= 0) {
            indexS = nextValidChar(s, indexS);
            indexT = nextValidChar(t, indexT);
            char charS = indexS >= 0 ? s.charAt(indexS) : 0;
            char charT = indexT >= 0 ? t.charAt(indexT) : 0;
            if (charS != charT)
                return false;
            indexS--;
            indexT--;
        }
        return true;
    }

    private int nextValidChar(String st, int index) {
        int backspace = 0;
        while (index >= 0) {
            if (backspace == 0 && st.charAt(index) != '#') {
                break;
            } else if (st.charAt(index) == '#') {
                backspace++;
            } else {
                backspace--;
            }
            index--;
        }
        return index;
    }

    public static void main(String[] args) {
        BackspaceStringCompare sol = new BackspaceStringCompare();
        System.out.println(sol.backspaceCompare("ab#c", "ad#c") + " | True");
        System.out.println(sol.backspaceCompare("ab##", "c#d#") + " | True");
        System.out.println(sol.backspaceCompare("a#c", "b") + " | False");
        System.out.println(sol.backspaceCompare("a##b", "#a#b") + " | True");
        System.out.println(sol.backspaceCompare("", "") + " | True");
    }
}
