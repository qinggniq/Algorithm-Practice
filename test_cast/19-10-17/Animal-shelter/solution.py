class Animal:
    def __init__(self, id: int, isDog: bool):
        self.id = id
        self.isDog = isDog


class Solution:
    def __init__(self):
        self.catQueue = []
        self.dogQueue = []
        self.time = 0

    def enqueue(self, animal: list):
        if animal[1]:
            self.dogQueue.append((animal, self.time))
        else:
            self.catQueue.append((animal, self.time))
        self.time += 1

    def dequeueAny(self) -> list:
        if len(self.catQueue) == 0 or self.catQueue[0][1] <= self.dogQueue[0][1]:
            return self.catQueue.pop(0)[0]
        if len(self.dogQueue) == 0 or self.dogQueue[0][1] <= self.catQueue[0][1]:
            return self.dogQueue.pop(0)[0]
        return [-1, -1]

    def dequeueDog(self) -> Animal:
        if len(self.dogQueue) != 0:
            return self.dogQueue.pop(0)[0]
        return [-1, -1]

    def dequeueCat(self) -> Animal:
        if len(self.catQueue) != 0:
            return self.catQueue.pop(0)[0]
        return [-1, -1]
