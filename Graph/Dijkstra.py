# -*- coding: utf-8 -*-
"""
Dijkstra’s shortest path algorithm
עבור כל צומת בגרף נסמן האם ביקרנו בו או לא, ומרחקו מצומת המוצא.
במצב ההתחלתי נגדיר שכל הצמתים טרם ביקרנו בהם, ומרחק אליהם הוא אינסוף
כל עוד נותרו צמתים שלא ביקרנו בהם:
נסמן צומת נוכחי X כצומת שביקרנו בו
עבור כל צומת שכן של צומת נוכחי נעדכן את ערכו של השכן Y להיות הערך המינימלי מבין מרחקו הנוכחי
לבין מרחק של X ועוד משקל הקשת בין X ל-Y
נבחר X חדש מהרשימה שמרחקו מצומת מוצא הוא מינמלי מבין הצמתים שעוד לא ביקרנו בהם
"""

#for INT_MAX
import sys

class Graph():
    def __init__(self,vecs_number):
        self.V = vecs_number
        #base case - all edges weights 0
        self.edges_weight = [[0 for col in range(vecs_number)]
                             for row in range((vecs_number))]

    def getNearestNode(self,dist_lst,visited):
        min = sys.maxint

        for v in range(self.V):
            if dist_lst[v]<min and visited[v]==False:
                min = dist_lst[v]
                min_node = v

        return min_node

    def printDijkstraOutput(self,dst):
        for node in range(self.V):
            print str(node) + "     "+str(dst[node])


    def Dijkstra(self,s):
        visited_lst = [False]*self.V
        dist_list = [sys.maxint]*self.V

        #set distance from source node to 0
        dist_list[s]=0

        for x in range(self.V):
            #in first iter y is equal to source node
            y = self.getNearestNode(dist_list,visited_lst)
            visited_lst[y]=True
            for v in range(self.V):
                #if there is an edge between y and v
                #if we didnt visit this node already
                if visited_lst[v]==False and self.edges_weight[y][v]>0 and\
                        dist_list[y]+self.edges_weight[y][v] < dist_list[v]:
                        dist_list[v] = dist_list[y]+self.edges_weight[y][v]
        self.printDijkstraOutput(dist_list)


g = Graph(9)
g.edges_weight = [[0, 4, 0, 0, 0, 0, 0, 8, 0],
           [4, 0, 8, 0, 0, 0, 0, 11, 0],
           [0, 8, 0, 7, 0, 4, 0, 0, 2],
           [0, 0, 7, 0, 9, 14, 0, 0, 0],
           [0, 0, 0, 9, 0, 10, 0, 0, 0],
           [0, 0, 4, 14, 10, 0, 2, 0, 0],
           [0, 0, 0, 0, 0, 2, 0, 1, 6],
           [8, 11, 0, 0, 0, 0, 1, 0, 7],
           [0, 0, 2, 0, 0, 0, 6, 7, 0]
           ];

g.Dijkstra(0);

