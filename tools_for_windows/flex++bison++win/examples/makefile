

.SUFFIXES : .cc .y .l $(SUFFIXES)

.cc.o :
	CC   -I$(CENTERCCLIBDIR)/incl -c  $*.cc

.y.cc :
	bison++ -d  -o $*.cc -h $*.h  $*.y
.l.cc :
	flex++  -8  -h$*.h -o$*.cc $*.l
.y.h :
	bison++ -d  -o $*.cc -h $*.h  $*.y
.l.h :
	flex++ -8   -h$*.h -o$*.cc $*.l

all : compiler dman ios

# COMPILER ON IOSTREAM SAMPLE

MyCompilerIOS.o : MyCompilerIOS.cc MyParserIOS.h MyScannerIOS.h

MyParserIOS.o : MyParserIOS.cc MyParserIOS.h

MyScannerIOS.o : MyScannerIOS.cc MyScannerIOS.h MyParserIOS.h

MyParserIOS.cc : MyParserIOS.y

MyScannerIOS.cc : MyScannerIOS.l

MyParserIOS.h : MyParserIOS.y

MyScannerIOS.h : MyScannerIOS.l


ios : MyCompilerIOS.o MyParserIOS.o MyScannerIOS.o
	CC  -o $@ MyCompilerIOS.o MyParserIOS.o MyScannerIOS.o


# COMPILER SAMPLE

MyCompiler.o : MyCompiler.cc MyParser.h MyScanner.h

MyParser.o : MyParser.cc MyParser.h

MyScanner.o : MyScanner.cc MyScanner.h MyParser.h

MyParser.cc : MyParser.y

MyScanner.cc : MyScanner.l

MyParser.h : MyParser.y

MyScanner.h : MyScanner.l

compiler : MyCompiler.o MyParser.o MyScanner.o
	CC  -o $@ MyCompiler.o MyParser.o MyScanner.o

# DMAN

dmanParser.o : dmanParser.cc dmanParser.h

dmanScanner.o : dmanScanner.cc dmanScanner.h dmanParser.h

dmanParser.cc : dmanParser.y

dmanScanner.cc : dmanScanner.l

dmanParser.h : dmanParser.y

dmanScanner.h : dmanScanner.l

dman : dmanParser.o dmanScanner.o
	CC  -o $@ dmanParser.o dmanScanner.o

	
