from sys import argv

script , file_name = argv

txt = open(file_name , 'a+')

print "file content ", txt.read()
txt.seek(0)
txt.truncate()

print "File content removed ", txt.read()

txt.write("rewrittent file content")
txt.seek(0)
print "new content ",txt.read()
txt.close()
