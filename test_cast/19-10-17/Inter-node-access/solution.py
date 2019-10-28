class Solution:
    def findWhetherExistsPath(self, n: int, graph, start: int, target: int) -> bool:
        g = [[] for x in range(n)]
        q = []
        vis = set()
        for e in graph:
            g[e[0]].append(e[1])
        q.append(start)
        vis.add(start)

        while len(q) != 0:
            now = q.pop(0)
            if now == target:
                return True
            for nxt in g[now]:
                if nxt not in vis:
                    vis.add(start)
                    q.append(nxt)
        return False
