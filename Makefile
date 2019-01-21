# use the gnu C++ compiler
CCC= g++
# list all warnings
CCCFLAGS = -Wall -g -std=c++11

# all is called a target, after the colon you have dependencies
# ie. "the target all is dependent on the executables
all : test

# the target <excecutable1> is dependent on the list of dependencies
# the line following  is the required executable (don't need to adjust it)
# Note: executable lines, ie. $(CCC) ..., always begin with a tab.
# $^ = this target
# $@ = this/these dependencies
test: administration.o token.o scanner.o symbol.h test.o
	$(CCC) $(CCCFLAGS) $^ -o $@

# if 2 or more problems in assignment, you can compile them all with extra 
# executable targets and dependencies.
# tester : map.o tester.o
#	$(CCC) $(CCCFLAGS) $^ -o $@

# default rule compiling .cc to .o
# all .o file targets are dependent on the corresponding .cc files
# $< = the corresponding .cc file
%.o : %.cpp
	$(CCC) -c $(CCCFLAGS) $<

# Don't need next lines b/c of the above default rule but no harm including them
# In the following lines, make knows that the .cc file is required in the
# current dependency so you can leave it out.  You can also leave out the
# corresponding executable line

administration.o : administration.h
token.o : token.cpp
symbol.o : symbol.h
test.o : test.cpp
#etc
clean:
	rm -f *.o *~ *% *# .#*

clean-all: clean
	rm -f test
