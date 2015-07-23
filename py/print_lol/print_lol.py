""" this function is for printing nested lists """
def print_lol(li, level):
	for i in li:
		if isinstance(i, list):
			print_lol(i,level)
		else:
			for tab in range(level):
				print("\t", end='')
			print(i)
print("hey that's changed...")
