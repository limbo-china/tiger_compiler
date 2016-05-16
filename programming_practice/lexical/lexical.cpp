// lexical.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "lexical.h"
#include <iostream>
using namespace std;

#define getchdo (ch=getchar())  //读取一个字符
#define MAX 20  //标识符的最大长度

enum symbol {
	nul, ident, number, plus_, minus_,
	times, odd, backslash, eql, neq,
	lss, leq, gtr, geq, lparen,
	rparen, comma, semicolon, period, becomes,
	beginsym, endsym, ifsym, thensym, whilesym,
	writesym, readsym, dosym, callsym, constsym,
	varsym, procsym
};
char symbol[][10] = {
	"nul", "ident", "number", "plus", "minus",
	"times", "odd", "backslash", "eql", "neq",
	"lss", "leq", "gtr", "geq", "lparen",
	"rparen", "comma", "semicolon", "period", "becomes",
	"beginsym", "endsym", "ifsym", "thensym", "whilesym",
	"writesym", "readsym", "dosym", "callsym", "constsym",
	"varsym", "procsym"
};
char word[][10] = {
	"begin","end","if","then","while","write","read","do","call","const","var","procedure"
};
char chr[] = {
	'+','-','*','/','\\','=','#','(',')',',',';','.'
};
int wsym[] = { beginsym,endsym,ifsym,thensym,whilesym,writesym,readsym,dosym,callsym,constsym,varsym,procsym };
int csym[] = { plus_,minus_,times,odd,backslash,eql,neq,lparen,rparen,comma,semicolon,period };

char ch = 32;  //读取字符到此变量
char a[MAX + 1];
char id[MAX + 1];
int sym; //单词类别
int num; //整数数值
int cp;  //字符串指针

int getsym() {
	while (ch == 32 || ch == 9 || ch == 10 || ch == 13)  //忽略空白符
		getchdo;
	if (ch >= 'a'&&ch <= 'z') {   //标识符
		cp = 0;
		while (ch >= 'a'&&ch <= 'z') {   //取字母
			a[cp++] = ch;
			getchdo;
		}
		a[cp] = '\0';
		strcpy(id, a);
		int k;
		k = searchw(id);      //寻找是否是保留字
		if (k != -1)
			sym = wsym[k];   //取单词类型
		else
			sym = ident;  //单词为标识符
	}
	else if (ch >= '0'&&ch <= '9') {   //整数数值
		cp = 0;
		while (ch >= '0'&&ch <= '9') {   //取数字
			a[cp++] = ch;
			getchdo;
		}
		a[cp] = '\0';
		strcpy(id, a);
		sym = number;  //单词为数字类型
		num = atoi(id); //转换字符串为数字
	}
	else if (ch == ':') {
		getchdo;
		if (ch == '=') {
			sym = becomes;
			getchdo;
		}
		else
			sym = nul;
	}
	else if (ch == '<') {
		getchdo;
		if (ch == '=') {
			sym = leq;
			getchdo;
		}
		else
			sym = lss;
	}
	else if (ch == '>') {
		getchdo;
		if (ch == '=') {
			sym = geq;
			getchdo;
		}
		else
			sym = gtr;
	}
	else {
		int k = searchc(ch);
		sym = csym[k];
		getchdo;
	}
}

int searchw(char *a) {
	for (int i = 0;i<12;i++) {
		if (strcmp(a, word[i]) == 0)
			return i;
	}
	return -1;
}
int searchc(char a) {
	for (int i = 0;i<12;i++) {
		if (a == chr[i])
			return i;
	}
	return -1;
}

int main()
{
	while (ch != '@') {
		getsym();
		if (sym == ident)
			cout << symbol[sym] << "\t" << id << endl;
		else if (sym == number)
			cout << symbol[sym] << "\t" << num << endl;
		else
			cout << symbol[sym] << endl;
	}

	return 0;
}
