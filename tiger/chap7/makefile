a.exe: parse.o  table.o prabsyn.o tiger.tab.o lex.yy.o errormsg.o util.o absyn.o symbol.o env.o types.o semant.o printtree.o tree.o translate.o frame.o temp.o 
	cc -g parse.o table.o prabsyn.o tiger.tab.o lex.yy.o errormsg.o util.o absyn.o symbol.o env.o types.o semant.o printtree.o tree.o translate.o frame.o temp.o

	
types.o: types.c types.h
	cc -g -c types.c
	
env.o: env.c env.h
	cc -g -c env.c
	
semant.o: semant.c semant.h 
	cc -g -c semant.c
	
parse.o: parse.c errormsg.h util.h
	cc -g -c parse.c
	
tiger.tab.o: tiger.tab.c
	cc -g -c tiger.tab.c

tiger.tab.c: tiger.y
	bison -dv tiger.y

tiger.tab.h: tiger.tab.c
	echo "tiger.tab.h was created at the same time as tiger.tab.c"
	
symbol.o: symbol.c symbol.h
	cc -g -c symbol.c

absyn.o: absyn.c absyn.h
	cc -g -c absyn.c
	
table.o: table.c table.h
	cc -g -c table.c
	
frame.o: frame.c frame.h
	cc -g -c frame.c
	
temp.o: temp.c temp.h
	cc -g -c temp.c
	
prabsyn.o: prabsyn.c prabsyn.h 
	cc -g -c prabsyn.c
	
printtree.o: printtree.c printtree.h
	cc -g -c printtree.c

tree.o: tree.c tree.h
	cc -g -c tree.c

translate.o: translate.c translate.h
	cc -g -c translate.c
	
errormsg.o: errormsg.c errormsg.h util.h
	cc -g -c errormsg.c

lex.yy.o: lex.yy.c symbol.h absyn.h tiger.tab.h errormsg.h util.h
	cc -g -c lex.yy.c

lex.yy.c: tiger.lex
	flex tiger.lex

util.o: util.c util.h
	cc -g -c util.c
	
clean: 
	rm -f a.exe symbol.o table.o absyn.o util.o parse.o prabsyn.o lex.yy.o errormsg.o tiger.tab.c tiger.tab.h tiger.tab.o env.o types.o semant.o printtree.o tree.o translate.o frame.o temp.o 
