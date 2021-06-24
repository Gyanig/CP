class Solution():
	def __init__(self):
		pass

	def assign(self,t):
		d = dict()
		for pair in t:
			if(pair[0]==pair[1]): 
				continue
			if pair[0] not in d: 
				d[pair[0]] = []
			if pair[1] not in d:
				d[pair[1]] = [pair[0]]
			else:
				d[pair[1]].append(pair[0])

		c = dict() 
		for manager in d:
			c[manager] = len(d[manager])
			for employee in d[manager]:
				c[manager] += len(d[employee])
			print("{} : {}".format(manager,c[manager]))	 



if __name__=="__main__":
	t = (("A", "C"),("B", "C"),("C", "F"),("D", "E"),("E", "F"),("F", "F"))
	obj = Solution()
	obj.assign(t)
