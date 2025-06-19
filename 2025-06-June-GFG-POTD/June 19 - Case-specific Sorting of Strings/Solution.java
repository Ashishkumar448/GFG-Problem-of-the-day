class Solution {
    public static String caseSort(String s) {
        int n = s.length();
        char[] chars = s.toCharArray();
        
        // Lists to store uppercase and lowercase letters separately
        ArrayList<Character> upper = new ArrayList<>();
        ArrayList<Character> lower = new ArrayList<>();
        
        // Separate characters by case
        for (char c : chars) {
            if (Character.isUpperCase(c)) {
                upper.add(c);
            } else {
                lower.add(c);
            }
        }
        
        // Sort both lists
        Collections.sort(upper);
        Collections.sort(lower);
        
        // Reconstruct the result
        StringBuilder result = new StringBuilder();
        int i = 0, j = 0;
        
        for (char c : chars) {
            if (Character.isUpperCase(c)) {
                result.append(upper.get(i++));
            } else {
                result.append(lower.get(j++));
            }
        }
        
        return result.toString();
    }
}
