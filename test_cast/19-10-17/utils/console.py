class Console:
    def showList(self, arr):
        print(arr)

    def showDict(self, dic):
        print(dic)

    def showNum(self, num):
        print(num)

    def showStr(self, strs):
        print(strs)

    def showAny(self, input):
        if isinstance(input, list):
            self.showList(input)
        elif isinstance(input, dict):
            self.showDict(input)
        elif isinstance(input, int):
            self.showNum(input)
        elif isinstance(input, str):
            self.showStr(input)
        else:
            print(input)
