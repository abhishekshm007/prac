class Emp:
	"""A Simple Emp class"""
	empcount = 0

	def __init__(self, name, salary):
		self.name = name
		self.salary = salary
		Emp.empcount += 1
		print "Employ object created ",self
	
	def getEmpCount(self):
		print "Total no of employees ", Emp.empcount
	
	def displayEmp(self):
		print "Name = ", self.name, " salary = ", self.salary

emp = Emp("khan", 7000)
emp.displayEmp()
emp.getEmpCount()

emp = Emp("SRK" , 4500)
emp.displayEmp()
emp.getEmpCount()
