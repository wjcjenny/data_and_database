# `lambda` is a way to define a really short function. 
def add( x,y ):
	return x+y
# can just be
add = lambda x,y: x+y

# You can call it the normal way.
print add(3,7)
# 10


# Using `lambda` is useful when we have to pass a really short function as a parameter/argument to another function.


# For example, the `sorted()` function.
# This is the way the `sorted()` function works:


# If we pass the `sorted()` function a list, it's obvious what it's supposed to sort on, so we don't need to specify the `key` function.
print sorted( [ 2,6,12,5 ] )
# This does the same thing as
print sorted( [ 2,6,12,5 ],key=lambda e: e )
# [2, 5, 6, 12]

# Say we want to sort a list on something that's NOT obvious (here, the absolute value of the element value minus 8). We can use `lambda`.
print sorted( [ 2,6,12,5 ],key=lambda e: abs(e-8) )
# [6, 5, 12, 2]


# If we pass the `sorted()` function a dictionary, it's NOT obvious what it's supposed to sort on, so we specify the `key` function, often by using `lambda`.

word_counts = {'it': 123, 'was': 48, 'the': 423, 'best': 7, 'worst': 13, 'of': 350, 'times': 2}

# Recall that `.items()` turns a dictionary in to a list of tuples:
print word_counts.items()
# [('of', 350), ('it', 123), ('times', 2), ('worst', 13), ('the', 423), ('was', 48), ('best', 7)]

# We can sort that on the dictionary values (the 2nd ("1th") element of the tuples).
print sorted( word_counts.items(),key=lambda t: t[1] )
# [('times', 2), ('best', 7), ('worst', 13), ('was', 48), ('it', 123), ('of', 350), ('the', 423)]

# We can sort that on the dictionary keys (the 1st ("0th") element of the tuples).
print sorted( word_counts.items(),key=lambda t: t[0])
# [('best', 7), ('it', 123), ('of', 350), ('the', 423), ('times', 2), ('was', 48), ('worst', 13)]

# We can even sort that on the last letter of the dictionary keys (the last letter of the 1st ("0th") element of the tuples).
print sorted( word_counts.items(),key=lambda t: t[0][-1])
# [('the', 423), ('of', 350), ('times', 2), ('was', 48), ('it', 123), ('worst', 13), ('best', 7)]
# (Notice how the last letters are in order: 'e','f','s','s','t','t','t')

# The temporary variable name can be `t` or `asdf` or whatever.
print sorted( word_counts.items(),key=lambda asdf: asdf[0])
# [('best', 7), ('it', 123), ('of', 350), ('the', 423), ('times', 2), ('was', 48), ('worst', 13)]


# While we're talking about the `sorted()` function, here are some nice tricks when you're looping through dictionaries:

# Looping through the dictionary `word_counts` in no particular order:
for key in word_counts:
	 print key,word_counts[key]
# You get
# of 350
# it 123
# times 2
# worst 13
# the 423
# was 48
# best 7

# Looping through the dictionary `word_counts` in ascending order of its values:
for key in sorted( word_counts,key=word_counts.get ): 
	print key,word_counts[key]
# You get
# times 2
# best 7
# worst 13
# was 48
# it 123
# of 350
# the 423


# Looping through the dictionary `word_counts` in descending order of its values:
for key in sorted( word_counts,key=word_counts.get,reverse=True ): 
	print key,word_counts[key]
# You get
# the 423
# of 350
# it 123
# was 48
# worst 13
# best 7
# times 2
