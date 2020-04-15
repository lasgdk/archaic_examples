#Python file handling

#Note that this script creates the temporary file "09_tempfile"
print "Note that this script creates the temporary file 09_tempfile"

#A file is opened with "open('filename','mode')" where mode is either
# r or w for read or write.
testfile = open('09_tempfile','w')

#Lets do a list of random junk:
randlist=[3,5,8,'twack']

#And for-loop it into the tempfile:
for entry in randlist:
	testfile.write(str(entry) + '\n')
print "09_tempfile written. You can view contents with cat"

#Note three important things with that write command i the for loop:
# It is a write command, not an append command, so any old content in the file,
# will be overwritten.
#You can only write strings to files, not integers directly. That why we
# have the str() inside.
#Normal screen output automatically gets newline in the end. File-written
# strings does not. So we add the "+ '\n'" to get a newline.

#Always close opened files after work is done:
testfile.close()

#When reading the lines in a file, the lines will be stored in a list:
readfile = open('09_tempfile','r')
lines = readfile.readlines()
print lines

readfile.close()
