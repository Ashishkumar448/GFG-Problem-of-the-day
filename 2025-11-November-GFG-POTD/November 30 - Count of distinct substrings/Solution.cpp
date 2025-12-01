class Solution {
public:
    struct State {
        int len = 0, link = -1;
        int next[26] = {0};
    };

    static int countSubs(const string &s) {
        int n = s.size();
        vector<State> st(2 * n);
        int last = 0, sz = 1;
        long long ans = 0;

        for (char ch : s) {
            int c = ch - 'a';
            int cur = sz++;
            st[cur].len = st[last].len + 1;

            int p = last;
            while (p != -1 && st[p].next[c] == 0) {
                st[p].next[c] = cur;
                p = st[p].link;
            }

            if (p == -1) {
                st[cur].link = 0;
            } else {
                int q = st[p].next[c];
                if (st[p].len + 1 == st[q].len) {
                    st[cur].link = q;
                } else {
                    int clone = sz++;
                    st[clone].len = st[p].len + 1;
                    memcpy(st[clone].next, st[q].next, sizeof(st[q].next));
                    st[clone].link = st[q].link;

                    while (p != -1 && st[p].next[c] == q) {
                        st[p].next[c] = clone;
                        p = st[p].link;
                    }
                    st[q].link = st[cur].link = clone;
                }
            }

            last = cur;
        }

        for (int i = 1; i < sz; i++)
            ans += st[i].len - st[st[i].link].len;

        return (int)ans;
    }
};
