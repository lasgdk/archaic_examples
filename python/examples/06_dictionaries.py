#Dictionaries 

#Dictionaries are lists where the objects are referenced by a key,
# and not by and numeric index.
#This is what perl-people call hashes

#Sample dictionary:
admins = { 'root' : 'mama', 'operator': 'me', 'coadmins':5 }

#who is behind key root?
print admins['root']

#which keys do we have?
print admins.keys()

#and which values?
print admins.values()

#We should add exobit/exibot as pentester perhaps...:
admins['pentester'] = 'my sister'

#show it all:
print admins
