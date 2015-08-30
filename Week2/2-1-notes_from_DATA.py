########################################################################
# 1: reading discussion

# data analysis:
# perhaps a little inaccurate, but efficient, plausible?
# efficient because the labor is being hidden? -- your search is doing labor for Google to make money
# ethical issues of using people's search

# crowd-sourcing, open source software, 
# Wikipedia editors are mostly men, probably white American men
# just a new outlet for them?

# big data supplements, not replaces, traditional analysis


# N-GRAM, sequence of words
# https://books.google.com/ngrams
# compare "george bush", "ronald reagan"
# e.g. a 3-gram analysis of "The Road Not Taken" by Robert Frost would go something like
# We have a line like this
# "Two roads diverged in a yellow wood,"
# And the 3-grams in there are 
# "Two roads diverged"
#     "roads diverged in"
#           "diverged in a"
#                     "in a yellow"
#                        "a yellow wood"

# CORPUS

# an ONTOLOGY: in style in AI research in the 80's, 90's, even today;
# a computer representation 
# a computer-readable model of how the world works
# conceptNet, an example of a data ontology
# GFT reading: This doesn't scale to the level that we need

# from the Google Flu paper
# BLUE TEAM: marketing, business needs of Google changed so the algorithm changed
# e.g. when autocomplete was introduced
# RED TEAM: user behavior to game the system


########################################################################
# 2: function as value

kitty = "meow"
# `kitty` is the variable name
# `"meow"` is the variable value, and its type is a string
print type( kitty )

#
def vocalize():
	return "meow!"
# `vocalize` is the variable name
# the function we wrote out is the variable value 
print type( function )
#
foo = vocalize
print foo()
#
give_me_the_length_of = len
print give_me_the_length_of( "hello" )


# passing functions as arguments to other functions


# `apply()` lets you call functions another way
def schoolyardtaunt( person1,person2,location ):
	return person1+" and "+person2+" sitting in a(n) "+location+" KISSING!"

schoolyardtaunt( "Mr Rogers","Mother Teresa","1969 Mustang" )
# does the same thing as
apply( schoolyardtaunt,( "Mr Rogers","Mother Teresa","1969 Mustang" ) )


# `map()` calls a funciton on each item of a list ........

def square( x ):
	return x * x
numbers = [ 5,27,19,2,6 ]

map( square,numbers )
# does the same thing as
[ square( n )  for n in numbers ]


def upper_func( s ): # `upper_func()` is a function (a function version of `.upper()`)
	return s.upper() # Can't just use `.upper()` in `map` because it's a method
ee_cummings = [ "hello","there","how","are","you" ]

map( upper_func,ee_cummings )
# does the same thing as
[ upper_func( e )  for e in ee_cummings ]

# does the same thing as
map( lambda s: s.upper(),ee_cummings )
# does the same thing as
[ e.upper()  for e in ee_cummings ]


# `filter()` ........

def less_than_ten( x ):
	return x < 10
	# does the same thing as
	## if x < 10:
	## 	return True
	## else:
	## 	return False
numbers = [ 2,4,92,-16,11,19 ]

filter( less_than_ten,numbers )
# does the same thing as
[ n  for n in numbers  if less_than_ten( n ) ]


words = [ "HELLO","there","HOW","are","YOU" ]
# Using `filter()` to get only `[ "there","are" ]`
# Googled `python method to check if string is lowercase`
def is_this_lower( s ):
	return s.islower()

filter( is_this_lower,words )
# does the same thing as
[ w  for w in words  if is_this_lower( w ) ]

map( upper_func,filter( is_this_lower,words ) )
# does the same thing as
[ upper_func( w )  for w in words  if is_this_lower( w ) ]



# LAMBDA functions
# write an entire function in one expression! Can't have multiple statements, only a return value

square = lambda x: x * x
# does the same thing as
def square( x ):
	return x * x

schoolyardtaunt = lambda person1,person2,location: person1+" and "+person2+" sitting in a(n) "+location+" KISSING!"
# does the same thing as
def schoolyardtaunt( person1,person2,location ):
	return person1+" and "+person2+" sitting in a(n) "+location+" KISSING!"



words = [ "HELLO","there","HOW","are","YOU" ]
# Using `filter()` to get only `[ "there","are" ]`
# Googled `python method to check if string is lowercase`
def is_this_lower( s ):
	return s.islower()
# does the same thing as
is_this_lower = lambda s: s.islower()

filter( is_this_lower,words ) # variable name of the function

# does the same thing as
filter( lambda s: s.islower(),words ) # value

# does the same thing as
[ w  for w in words  if is_this_lower( w ) ]
# does the same thing as
[ w  for w in words  if w.islower() ]



# `sorted()`
words = [ "mastodon","brie","zebra","ZZZZZZZ","ZZZ","abacus","norseman","Name" ]
print sorted( words )
print sorted( words,reverse=True )
# 
print sorted( words,key=len )
# when two elements are the "same" according to the `key`,  falls back to the default, OR
# OR, specify secondary sort key with
print sorted( words,key=lambda x: ( len,x[-1],x[-2] ) )
# or perhaps
print sorted( words,key=lambda x: ( x[0].lower(),-len( x ) ) )

word_counts = {'it': 123, 'was': 48, 'the': 423, 'best': 7, 'worst': 13, 'of': 350, 'times': 2}
print max( word_counts,key=word_counts.get )
# does the same thing as
print sorted( word_counts.items(), key=lambda w: w[1], reverse=True )[0][0]
# does the same thing as
print sorted( word_counts.items(), key=lambda w: w[1] )[-1][0]


########################################################################
# 3: unicode, text encoding


# how computers see text
# big long "spreadsheet" with one row, each cell corresponds to a particular number
# computers can only understand numbers (actually only 0's and 1's but )

# digitizing text, encoding
# text ==encoding=> numbers, "raw" data
# decoding (so we can understand them)
#                   numbers, "raw" data ==decoding=> text


# various competing standards
# (1930's) ITA2     	A ->   3
# (1950's) Fieldata 	A ->   6 (military)
# (1960's) EBCDIC   	A -> 193 (IBM mainframe)
# (1960's) Radix-50 	A ->  13

# ASCII
[ ord( x )  for x in list( "AZaz" ) ] # [65, 90, 97, 122]
[ ord( x )  for x in "AZaz" ] # [65, 90, 97, 122]
# so American English specific


# sorting: can sort simply by sorting the numbers


# "Extended" ASCII
# z is 122
# &eacute; is 233
# why zymurgy was followed by &eacute;clair
	# @everyword # eschatology
# All of these characters range from 0 to 255 so one character would be 1 byte, 2**8 (1 byte = 8 bits, every bit is 0 or 1)

# ........ IPYNB, wikipedia code page

# Unicode
# numbers are bigger than 0 to 255; take up more memory, 2**32 == 4294967296, needs 4 bytes for one character

# UTF-8
# encoding for a character encoding
# The original ASCII characters have the same values in Unicode
# 0 - 127 => just store that as itself, only takes up 1 byte

	# OBJECT ORIENTED PROGRAMMING
	# "Platonic ideal of a table and that's Unicode...That's a terrible analogy!" -Allison

message = "I am your father, Luke!"
type( message )

ord( "a" )
chr( 65 )

# we can think of a string like `message` a sequence of bytes
ord( message[0] )
[ ord( x )  for x in message ]

french = "touché" # OSX, US keyboard: option + e then e
len( french ) # 7
[ ord( x )  for x in french ] # [116, 111, 117, 99, 104, 195, 169]
chr( 195 ) # '\xc3'
chr( 169 ) # '\xa9'
french[5] # '\xc3'
french[6] # '\xa9'
# You're typing in UTF-8 encoding so under the hood é is being represented as 2 bytes
# Putting a `u` in front makes it 
french_unicode = u"touché"
len( french_unicode ) # 6
[ ord( x )  for x in french_unicode ] # [116, 111, 117, 99, 104, 233]
print french[5] # 



# In iPython notebook,
## !say meow


# unicode
# strings
# regular expressions