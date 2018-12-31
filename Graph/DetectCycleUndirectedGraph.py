# -*- coding: utf-8 -*-
"""
Union-Find | Detect Cycle in an Undirected Graph
הרעיון הוא להשתמש במבנה נתונים מסוג union find.
עבור כל צומת ניצור סט כך שהצומת הוא השורש של הסט
נעבור על כל הקשתות שבעץ ונבדוק עבור כל קשת האם שני הצמתים שיוצרים אותה נמצאים באותו סט,
אם לא, אז נאחד את שני הסטים לסט אחד,אבל אם הם כן סימן שיש מעגל בגרף!

            0
           / \
          2--1
          נייצר כעת שלושה סטים עבור כל צומת:

          0     1       2

          נתבונן בקשת (0,1) כיוון שהם לא תחת אותו סט, אז נאחד אותם
          1     2
         /
        0
        כעת נתבונן בקשת (0,2), כיוון שהם לא תחת אותו סט, נאחד אותם
            2
           /
          1
         /
        0
נתבונן כעת בקשת האחרונה שהיא (1,2), כיוון שכאן אם נשים לב שתי הצמתים נמצאים תחת אותו סט ששורשו הוא 2, אז סימן שיש מעגל בגרף
"""

from collections import defaultdict
class Graph():
    def __init__(self,V):
        self.V=V
        self.graph = defaultdict(list)

    def makeEdge(self,u,v):
        self.graph[u].append(v)

    def findParent(self,x,list_parents):
        if list_parents[x] == -1:
            return x
        else:
            return self.findParent(list_parents[x],list_parents)

    def union(self,list_parents,u,v):
        u_set_root = self.findParent(u,list_parents)
        v_set_root = self.findParent(v,list_parents)
        #make v parent to be parent of u parent
        list_parents[u_set_root]=v_set_root

    def detectCycle(self):
        list_parents = [-1]*(self.V)
        for u,lst in self.graph.items():
            for v in lst:
                u_p = self.findParent(u, list_parents)
                v_p = self.findParent(v,list_parents)
                if(v_p == u_p):
                    return True
                self.union(list_parents,u_p,v_p)


g = Graph(3)
g.makeEdge(0, 1)
g.makeEdge(1, 2)
g.makeEdge(2, 0)

if g.detectCycle():
    print "Graph contains cycle"
else:
    print "Graph does not contain cycle "