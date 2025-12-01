class Solution:
    class State:
        __slots__ = ("len", "link", "next")

        def __init__(self):
            self.len = 0
            self.link = -1
            self.next = [0] * 26

    @staticmethod
    def countSubs(s: str) -> int:
        n = len(s)
        st = [Solution.State() for _ in range(2 * n)]
        last = 0
        sz = 1
        ans = 0

        for ch in s:
            c = ord(ch) - ord('a')
            cur = sz
            sz += 1
            st[cur].len = st[last].len + 1

            p = last
            while p != -1 and st[p].next[c] == 0:
                st[p].next[c] = cur
                p = st[p].link

            if p == -1:
                st[cur].link = 0
            else:
                q = st[p].next[c]
                if st[p].len + 1 == st[q].len:
                    st[cur].link = q
                else:
                    clone = sz
                    sz += 1
                    st[clone].len = st[p].len + 1
                    st[clone].next = st[q].next[:]     # copy transitions
                    st[clone].link = st[q].link

                    while p != -1 and st[p].next[c] == q:
                        st[p].next[c] = clone
                        p = st[p].link

                    st[q].link = st[cur].link = clone

            last = cur

        for i in range(1, sz):
            ans += st[i].len - st[st[i].link].len

        return ans
