class Solution:
    def isFlipedString(self, s1: str, s2: str) -> bool:
        if len(s1) != len(s2):
            return False
        if s1 == s2:
            return True
        for i in range(len(s2)):
            if s1 == s2[i:] + s2[:i]:
                return True
        return False


sol = Solution()


def test_null():
    assert sol.isFlipedString('', '')


def test_single():
    assert sol.isFlipedString('a', 'a')
    assert not sol.isFlipedString('a', 'b')


def test_double():
    assert sol.isFlipedString('ab', 'ba')
    assert not sol.isFlipedString('aa', 'ab')


def test_normal():
    assert sol.isFlipedString('waterbottle', 'erbottlewat')


def test_all():
    test_null()
    test_single()
    test_double()
    test_normal()
    print("ok\n")


if __name__ == '__main__':
    test_all()
