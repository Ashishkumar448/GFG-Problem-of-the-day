class Solution:
    def __init__(self):
        self.document = []
        self.redoStack = []

    def append(self, x):
        self.document.append(x)
        self.redoStack.clear()  # clear redo history

    def undo(self):
        if self.document:
            self.redoStack.append(self.document.pop())

    def redo(self):
        if self.redoStack:
            self.document.append(self.redoStack.pop())

    def read(self):
        return ''.join(self.document)
