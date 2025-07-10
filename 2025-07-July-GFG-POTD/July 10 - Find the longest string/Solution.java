class Solution {
    class TrieNode {
        Map<Character, TrieNode> children = new HashMap<>();
        boolean isEnd = false;
        String word = null;  // Store full word at end node
    }

    public String longestString(String[] arr) {
        TrieNode root = new TrieNode();
        
        // Insert all words into Trie
        for (String word : arr) {
            TrieNode curr = root;
            for (char ch : word.toCharArray()) {
                curr = curr.children.computeIfAbsent(ch, k -> new TrieNode());
            }
            curr.isEnd = true;
            curr.word = word;
        }

        // BFS to find the longest valid string
        String result = "";
        Queue<TrieNode> queue = new LinkedList<>();
        queue.offer(root);

        while (!queue.isEmpty()) {
            TrieNode curr = queue.poll();

            for (char ch = 'a'; ch <= 'z'; ch++) {
                TrieNode next = curr.children.get(ch);
                if (next != null && next.isEnd) {
                    queue.offer(next);
                    if (next.word.length() > result.length() || 
                       (next.word.length() == result.length() && next.word.compareTo(result) < 0)) {
                        result = next.word;
                    }
                }
            }
        }

        return result;
    }
}
