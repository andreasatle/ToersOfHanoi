## Tower of Hanoi

The [Tower of Hanoi][tower] is a game designed to show the strength of recursion. You start with a stack of n blocks of decreasing size at a source. The blocks are to be moved to a target stack, using a work stack as temporary storage. You are supposed to move one block at a time, without putting a larger block on top of a smaller one.

This can be beautifully solved with a recursive algorithm (python-style pseudo code).

```python

recursive function tower(n, source, work, target):

if (n>1):

  # Move the first n-1 blocks from source to work with target as 'work-stack'
  tower(n-1, source, target, work)

  # Move the last block from source to target
  tower(1,   source, work,   target)

  # Move the n-1 blocks from work to target with source as 'work-stack'
  tower(n-1, work,   source, target)

else:

  move_one(source, target)
  print move

```

We also use [catch2] to test our program, and doxygen to document the code.

a simple make creates the program, test and creates html-output for doxygen documentation.

So far the make-files are VERY primitive.

[tower]: https://en.wikipedia.org/wiki/Tower_of_Hanoi
[catch2]: https://github.com/catchorg/Catch2/releases