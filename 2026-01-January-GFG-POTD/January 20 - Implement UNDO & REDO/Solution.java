class Solution {
    private StringBuilder document = new StringBuilder();
    private Stack<Character> redoStack = new Stack<>();

    public void append(char x) {
        document.append(x);
        redoStack.clear(); // new change invalidates redo history
    }

    public void undo() {
        if (document.length() > 0) {
            char removed = document.charAt(document.length() - 1);
            document.deleteCharAt(document.length() - 1);
            redoStack.push(removed);
        }
    }

    public void redo() {
        if (!redoStack.isEmpty()) {
            document.append(redoStack.pop());
        }
    }

    public String read() {
        return document.toString();
    }
}
