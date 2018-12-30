# -*- coding: utf-8 -*-
"""
BFS Algorithm uses Queue
התור עוזר לאלגוריתם לדעת מה הצומת הבא בה עומד לבקר.
בכל פעם שיבקר בצומת הוא יסמן אותו כנבדק,ואז בודק את כל הקשתות שיוצאות ממנו (שכנים)
אם יש לצומת שכן שלא נבדק נוסיף אותו לתור
אלגוריתם זה מחזיר את המסלול הקצר ביותר בגרף ללא משקולות על הקשתות (או משקולות אחידות)
"""
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph= defaultdict(list)

    #create the edge u->v
    def addEdge(self,u,v):
        self.graph[u].append(v)

    def BFS(self,first_node):
        #create an empty Queue
        queue = []

        #create array which indicates if we visit each node:
        visited = [False]*(len(self.graph))

        #add the first node to queue:
        queue.append(first_node)
        visited[first_node]=True

        #as long as the queue is not empty:
        while(queue):
            #pop the next node from queue - by FIFO order - first in first out
            first_node = queue.pop(0)
            print(first_node)

            """
            נרוץ בלולאה על כל השכנים של הצומת הנוכחית, אם נגיע לצומת
            שכבר עברנו עליו נדלג להבא, אחרת נכניס אותו לתור
            """
            #graph[x] contains its adjacents
            for i in self.graph[first_node]:
                if(visited[i] == False):
                    visited[i]=True
                    queue.append(i)

if __name__ == '__main__':
    graph = Graph()
    graph.addEdge(0, 1)
    graph.addEdge(0, 2)
    graph.addEdge(1, 2)
    graph.addEdge(2, 0)
    graph.addEdge(2, 3)
    graph.addEdge(3, 3)

    #print bfs from vertex 2:
    graph.BFS(2)

