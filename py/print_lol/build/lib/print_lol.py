""" this function is for printing nested lists """
def print_lol(li):
	for i in li:
		if isinstance(i, list):
			print_lol(i)
		else:
			print(i)
