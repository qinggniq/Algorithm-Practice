class Solution:
    def compressString(self, S: str):
        if len(S) <= 2:
            return S
        cnt = 1
        ans = ""
        for i in range(1, len(S)):
            if S[i] == S[i-1]:
                cnt += 1
            else:
                ans += S[i-1] + str(cnt)
                cnt = 1
        ans += S[-1] + str(cnt)
        return ans if len(ans) < len(S) else S


sol = Solution()


def test_null():
    assert sol.compressString('') == ''


def test_single():
    assert sol.compressString('a') == 'a'


def test_double():
    assert sol.compressString('aa') == 'aa'


def test_trible():
    assert sol.compressString('aaa') == 'a3'


def test_normal():
    assert sol.compressString('aabcccccaaa') == 'a2b1c5a3'


def test_all():
    test_null()
    test_single()
    test_double()
    test_trible()
    test_normal()
    print("ok\n")


if __name__ == "__main__":
    test_all()
