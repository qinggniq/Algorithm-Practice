class Solution:
    def replaceSpaces(self, S: str, length: int) -> str:
        cnt = 0
        S = list(S)
        cnt += sum((1 for c in S[:length] if c == ' '))
        newLen = length + 2 * cnt
        #print(length, newLen)
        S = S[:newLen]

        for i in range(length - 1, -1, -1):
            if S[i] == ' ':
                S[newLen - 1] = '0'
                S[newLen - 2] = '2'
                S[newLen - 3] = '%'
                newLen -= 3
            else:
                S[newLen - 1] = S[i]
                newLen -= 1
        return ''.join(S)
