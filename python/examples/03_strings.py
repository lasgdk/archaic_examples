#Playing with string

#How to give a variable a value:
variable="Value"
print 'The variable contains a ' + variable

#It is easy to connect string:
part1='Two par'
part2='ts connected'
print part1 + part2

#And connect variables:
part_total = part1 + part2
print "Still " + part_total

#Handle parts of strings, (like arrays):
numbers='0123456789'
print numbers[3:6]
name='Rafael Justingowitch'
print name[0:7]

#Search in strings, output starting position:
print name.find('Rafael')

#Replace in strings:
print name.replace('Rafael','John')

#Easy printing multiple strings:
print 'Hej! '*5
