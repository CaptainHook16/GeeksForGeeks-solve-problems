# -*- coding: utf-8 -*-
from __future__ import print_function
import sys


"""
find shortest distances between every pair of vertices in an edge weighted directed Graph.
שלב האתחול - לכל זוג צמתים x,y נגדיר d(x,y להיות משקל הקשת ביניהם אם יש כזאת,אחרת נגדיר אותו לאינסוף
נמספר את הצמתים בגרף, ועבור כל שני צמתים אפשריים בגרף ננסה לשפר את ערך המרחק ביניהם על ידי כך שנגדיר אותו להיות
המינימום בין הערך הנוכחי לבין d(u,k)+d(k,v, כלומר ננסה לשפר את המרחק דרך K

אם במהלך האלגוריתם נקבל צומת V עבורו d(v,v)<0 אב נחזיר שיש מעגל בגרף
"""
#for INT_MAX
INF = sys.maxint


class Graph():
    def __init__(self,vecs_number,edges_arr):
        self.V = vecs_number
        self.W = edges_arr

    def printOutput(self,dst):
        for i in range(self.V):
            for j in range(self.V):
                if dst[i][j]==INF:
                    print("INF", end="      ")
                else:
                    print (dst[i][j],end="      ")
                if j==self.V -1:
                    print("")



    def FloydWarshall(self):
        dist = self.W

        for k in range(self.V):
            for i in range(self.V):
                for j in range(self.V):
                    dist[i][j]= min(dist[i][j],dist[i][k]+dist[k][j])
        self.printOutput(dist)

graph = [[0,5,INF,10],
             [INF,0,3,INF],
             [INF, INF, 0,   1],
             [INF, INF, INF, 0]
        ]

g = Graph(4,graph)
g.FloydWarshall()