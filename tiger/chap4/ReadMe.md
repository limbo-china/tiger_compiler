1. `lvalue [exp]` 和 `id [exp] of exp` 的移进规约冲突问题：

在第三章的解决方案（无冲突）只能用在语法分析阶段，在生成抽象语法的阶段会出现问题
第三章解决：
解决前：(有害冲突)
<code>
	 lvalue:	ID 	
		|		lvalue DOT ID	 
		|		lvalue LBRACK exp RBRACK  

	array: 		ID LBRACK exp RBRACK OF exp </code>

解决后：(无冲突)
<code>
	lvalue:		ID 		
		|		lvalue DOT ID	
		|		ID LBRACK exp RBRACK  bracklist

	bracklist: 	LBRACK exp RBRACK bracklist
		| 

	array: 		ID LBRACK exp RBRACK OF exp </code>

由于需要生成抽象语法，如果用之前的文法，需要给`bracklist`一个类型，而并不需要这种类型。

继续修改`lvalue` 和`array`的定义，并删除`bracklist`：（优先移进，无害冲突）
<code>
	lvalue:		ID 
		|		lvalue DOT ID
		|		ID LBRACK exp RBRACK 
		|		lvalue LBRACK exp RBRACK

	array: 		ID LBRACK exp RBRACK OF exp  </code>

修改之后，虽然没有解决移进规约冲突问题，但是之前的为有害冲突，修改之后的为无害冲突（优先考虑移进），不影响语法分析，也不需要增加另外的类型。


2. 某些终结符（带语义值）需要指定其基本类型，从而使$符号能运行。
   所有的非终结符都需要指定其类型，包括开始符。

3. 编译错误： undefined reference to `A_StringExp' 等

	原因： 未在makefile内添加生成 absyn.o 等类似的目标文件，系统无法进行连接。 具体读csapp

4. 学习到makefile的使用

5. 出现重复声明的情况，需要在absyn.h中加上 ifndef

6. 添加输出功能，能打印出一个源tig文件产生的抽象语法。