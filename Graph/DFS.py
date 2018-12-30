# -*- coding: utf-8 -*-
"""
DFS Algorithm in Graph Use Stack - LIFO - Last In First Out
האלגוריתם הינו רקורסיבי, כלומר הוא בודק את הצומת הנוכחית ולאחר מכן קורא באופן רקורסיבי לעצמו על
כל אחד מבניו (כל עוד הוא עוד לא ביקר בהם).
כל צומת יסומן באחד משלושה צבעים: לבן אומר טרם נבדק, אפור אומר שהוא/בניו בתהליך בדיקה
ושחור אומר שהצומת ובניו כבר נבדקו ולכן סיימנו איתו.
השימוש במערך הבוליאני מונע מאיתנו להתקל במצב של מעגלים - כאשר עבידנו צומת מסויים לא נרצה לחזור אליו שוב
"""
from collections import defaultdict

class Graph:
    def __init__(self):
        self.graph= defaultdict(list)

    #create the edge u->v
    def addEdge(self,u,v):
        self.graph[u].append(v)

    def DFSHelper(self,cure_node,visited_list):
        #mark the current node as visited and print it
        visited_list[cure_node]=True
        print(cure_node)

        for i in self.graph[cure_node]:
            if visited_list[i] == False:
                #last in first outL LIFO
                self.DFSHelper(i,visited_list)



    def DFS(self,cure_node):
        # create array which indicates if we visit each node:
        visited_lst = [False]*len(self.graph)

        #call the helper function
        self.DFSHelper(cure_node,visited_lst)


g = Graph()
g.addEdge(0, 1)
g.addEdge(0, 2)
g.addEdge(1, 2)
g.addEdge(2, 0)
g.addEdge(2, 3)
g.addEdge(3, 3)

print "Following is DFS from (starting from vertex 2)"
g.DFS(2)
