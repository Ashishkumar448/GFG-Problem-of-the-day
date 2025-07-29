class Solution:
    def asciirange(self, s: str) -> list[int]:
        result = []
        seen = set()

        for ch in s:
            if ch in seen:
                continue

            first = s.find(ch)
            last = s.rfind(ch)

            if first != last:
                total = sum(ord(c) for c in s[first + 1:last])
                if total > 0:
                    result.append(total)

            seen.add(ch)

        return result
