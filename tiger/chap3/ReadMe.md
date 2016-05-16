1.
已解决 else 移进规约冲突 ： 添加了 `if exp then exp` 语法

直接添加if then 语法，仍然存在冲突，但是为无害冲突，不需要修改。

2.
%prec 的使用

#### 3.
`tyassign , tyfields,args` 等类似非终结符定义可能有错误
	

4.
解决如 a+b*c   a:=b+c 等类似的移进规约冲突问题，需要设置相应操作符的优先级(包括of do)

5.
解决 `lvalue [exp]` 和 `id [exp] of exp` 的移进规约冲突问题：
解决前：
<code>
	lvalue:		ID 	
		|		lvalue DOT ID	 
		|		lvalue LBRACK exp RBRACK  

	array: 		ID LBRACK exp RBRACK OF exp </code>

解决后：
<code>
	lvalue:		ID 		
		|		lvalue DOT ID	
		|		ID LBRACK exp RBRACK  bracklist

	bracklist: 	LBRACK exp RBRACK bracklist
		| 

	array: 		ID LBRACK exp RBRACK OF exp </code>

#### 6.
未添加功能：错误恢复

