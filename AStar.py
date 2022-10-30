drivingDistanceMatrix = []
geodesicDistanceMatrix = []
g= {}
f= {}
parents = {}
adjList = [[0,1],
			[0,5],
			[1,2],
			[1,3],
			[2,3],
			[5,6],
			[5,7],
			[6,8],
			[7,8],
			[2,4],
			[3,4],
			[4,8],
			[4,9],
			[8,9]]

def fillDistanaceMatrix():
	with open('g.txt', 'r') as filehandle:
	    for line in filehandle:
	        line = line[1:-2]
	        line = line.split(', ')
	        drivingDistanceMatrix.append(line)

	with open('h.txt', 'r') as filehandle:
	    for line in filehandle:
	        line = line[1:-2]
	        line = line.split(', ')
	        geodesicDistanceMatrix.append(line)

def findChild(node):
	children = []
	for element in adjList:
		if element[0]==node:
			children.append(element[1])
		if element[1] == node:
			children.append(element[0])
	return children


def calFValue(parent,node,destination):
	currG = float(g[parent]) + float(drivingDistanceMatrix[parent][node])
	g[node] = currG 
	currH = float(geodesicDistanceMatrix[node][destination])
	return currG + currH


def trackPath(source,destination):
	requiredPath = []
	start = destination
	while start != source:
		requiredPath.append(start)
		start = parents[start]
	requiredPath.append(start)
	return requiredPath


def aStar(source,destination):
	g[source] = 0
	openNodes = []
	closedNodes = []
	openNodes.append(source)
	f[source] = float(calFValue(source,source,destination))
	while(len(openNodes)!=int(0)):
		currNode = min(openNodes, key=lambda o:f[o])
		if(currNode == destination):
			return trackPath(source,destination)
		openNodes.remove(currNode)
		childrenOfCurr = findChild(currNode)
		if len(childrenOfCurr)!=0:
			for child in childrenOfCurr:
				if child not in openNodes and child not in closedNodes:
					f[child] = float(calFValue(currNode,child,destination))
					openNodes.append(child)
					parents[child] = currNode 
				elif child in openNodes:
					currF = float(calFValue(currNode,child,destination))
					if currF < f[child]:
						f[child] = currF
						parents[child] = currNode
				elif child in closedNodes:
					currF = float(calFValue(currNode,child,destination))
					if currF < f[child]:
						f[child] = currF
						closedNodes.remove(child)
						openNodes.append(child)
						parents[child] = currNode
		closedNodes.append(currNode)


def writeToFile(finalPath):
	with open('finalPath.txt', 'w') as f:
		for result in finalPath:
			f.write("%s\n" % result)



fillDistanaceMatrix();
finalPath = (aStar(0,9))
finalPath.reverse()

writeToFile(finalPath)
for i in range(len(finalPath)):
	print(finalPath[i],end='')
	if i != len(finalPath)-1:
		print(" --> ",end = '')

print()