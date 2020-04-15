#Pythonic Lists

#Like an array:
list1=[1,2,3,42,500]

#By printing the list, it makes it look nice
print list1

#Perhaps we want the length of the list:
print len(list1)

#Test if the n'th place in the list contains something:
print 1 in list1
print 8 in list1

#print the list a couple of times:
print list1 * 3

#print a single place in the list, or parts of the list:
print list1[1]
print list1[3]
print list1[1:3]
print list1[:3]

#Let us create a more complex list, a two dimentional array, table, matrix,
# or whatever youll call it:
matrix1=[['ID','Name','Score'],[0,'me',42],[1,'mother',100],[2,'father',65535]]

#we can extract an entry:
print matrix1[2]

#or just a single name:
print matrix1[3][1]

#We can replace his score:
matrix1[3][2] = -42
print matrix1[3]

#To isolate an entry:
mealone = matrix1[1]
print mealone

#Print and remove the last element:
print matrix1.pop()
print matrix1.pop()

#extent the list:
mealone.extend(['more','yet more', 'MOST'])
print mealone

#reverse the list:
mealone.reverse()
print mealone

#remove elements:
del mealone[3:6]
print mealone
