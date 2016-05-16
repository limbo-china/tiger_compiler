#### 1.
在检查数组类型的变量时（在 `TransVar()`的 `case A_subscriptVar`中），如何检查后面[]内的表达式所表示的整型值是否越界???


#### 2.
尚不能处理递归函数、递归类型，不能保证break嵌套正确。

3.
每一个表达式exp都需要被类型检查，即使对此表达式的类型没有要求。

可能有exp中含有声明。

#### 4.
`return Expty(NULL, TransExp(venv, tenv, e)->ty);`

可能可以优化为 `return TransExp(venv, tenv, e);` 但是可能`Tr_exp` 不同，目前不修改。

5.
在每个头文件上加上了条件编译

6.
类型声明中，对`Ty_Name`类型，只可能有一层嵌套。即所有的`NameTy`都是一个标识符绑定一个基本类型。

7.
修改`tiger.y`文件，  类似 `exp PLUS exp	{$$=A_OpExp(EM_tokPos,$1,$2,$3);}`

改为： `exp PLUS exp	{$$=A_OpExp(EM_tokPos,$1,A_plusOp,$3);}`

去掉 `%token	<op> PLUS` 处对操作符类型的指定，因为无法识别$2的值，只知道其类型。改成直接传值。

8.
修改`tiger.lex`文件，添加 `<COMMENT>"\n"  	{adjust(); EM_newline(); continue;}`，且优先级比
`<COMMENT>(.)` 要高。 即遇到注释内的回车符也需要对全局行数变量加1。

#### 9.
错误信息输出的错误所在行数有BUG，需要修改。

10.
已修改： `= <> `比较操作符也可以应用于数组和记录。

#### 11.
test28.29.40.46.tig 所指出的问题，未修复

已修复 test40.46.tig指出的问题

