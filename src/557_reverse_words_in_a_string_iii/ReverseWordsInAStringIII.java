public class ReverseWordsInAStringIII {
    public String reverseWords(String s) {
        String[] words = s.split(" ", -1);
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < words.length; i++) {
            sb.append(new StringBuilder(words[i]).reverse());
            if (i < words.length - 1)
                sb.append(" ");
        }
        return sb.toString();
    }

    public static void main(String[] args) {
        ReverseWordsInAStringIII sol = new ReverseWordsInAStringIII();
        System.out.println(sol.reverseWords("Let's take LeetCode contest") + " | s'teL ekat edoCteeL tsetnoc");
        System.out.println(sol.reverseWords("God Ding") + " | doG gniD");
        System.out.println(sol.reverseWords("a b c") + " | a b c");
        System.out.println(sol.reverseWords("  hello world  ") + " |   olleh dlrow  ");
        System.out.println(sol.reverseWords("") + " | ");
    }
}
