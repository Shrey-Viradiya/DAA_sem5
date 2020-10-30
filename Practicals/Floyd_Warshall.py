# Python Program for Floyd Warshall Algorithm
INF = 99999

def fw(graph, n):
	dist = graph

	for k in range(n):
		for i in range(n):
			for j in range(n):
				dist[i][j] = min(dist[i][j] ,dist[i][k]+ dist[k][j])
		
		print(f"M{k+1}")
		for l in dist:
			print(l)
graph = [[0,5,7,9,3],
		[2,0,3,4,5],
		[1,2,0,3,4],
		[9,6,2,0,3],
		[2,6,9,8,0]]

fw(graph, 5)