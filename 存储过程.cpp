/*
存储过程和函数：保存到服务器端，减少了客户端和服务器端数据的交换，防止编写重复的sql语句
和触发器原理相同都保存在服务器
函数的定义：首先函数中要执行多条行为，所以存在和触发器中相同的问题，要重新定义结束字符
-->create procedure 函数名 (in/out/inout 类型名 类型)--in表示输入,out表示输出，inout表示既输入又输出
begin
declare 类型名(假设为A) 类型----定义变量(和c语言中相反)
select 列 into A from 表 where 条件---into A表示将查询到的数据赋值给A
执行的行为
end
结束字符
调用函数-->call 函数名(参数)

查询自己创建的存储-->show procedure status like '?'\G
或者-->show create procedure 储存名\G
或者-->select routine_definition from information_schema.Routines where routine_name='存储名'

变量的定义：delcare a,b,c 类型 default ?---同时定义多个变量，默认值为?
变量的赋值-->set 变量1，变量2…… =?
或select ? into 变量 from ……
对于函数列表中传入的参数，如果为out，也就是输出类型，那么最后这个参数是可以在函数外部拿到的(out A int)
对于调用这个存储并传入out类型的参数时，参数前需要加@,并且参数的名字和原本储存中相同call ?(@A)
从外部拿到这个out类型的参数时也需要在参数名前加@
通过select 参数来直接查询

光标：当存储过程中需要大量的数据读取时，光标可以将存储中进行读取的元素拿出来分给变量，简化了变量的赋值
声明在处理行为之前，声明在存储中的变量之后
声明-->declare 光标名 cursor for 查询语句
打开光标-->open 光标名
使用光标：将光标中读取到的数据储存到变量中-->fetch 光标名 into 变量1,变量2
定义一个判断光标是否查找到数据的变量：declare A int default 0;
这个变量一定要定义在光标定义之前
若光标找不到数据-->declare continue handler for not found set A=1;
关闭光标-->close 光标名

if else语句-->if 条件1 then 执行语句 elseif 条件2 then 执行语句 else 执行语句 end if
case语句-->case 变量 when 条件1 then 执行语句…… end case
loop循环语句-->循环标签/名字:loop 循环的执行语句 end loop 循环标签
退出循环-->leave 循环标签
iterate进入下次循环-->iterate 循环标签(相当于continue)
repeat循环-->repeat 循环语句 until 结束条件 end repeat(相当于do while)
while循环-->while 循环条件 do 循环语句 end while

问题：查找一个表中的一个自增长型的数据，由于是自动改变的类型，可以考虑用max,min寻找
但是会有多个用户插入数据，这时max/min可能改变，将自己插入的数据覆盖掉
所以用select last_insert_列名()函数(只能用于自增长类型)
select last_insert_列名() as ?-->将查询的数据保存在?中
来查询当前窗口中最后一个插入的数据

查看当前mysql所用的引擎-->show variables like 'default_storage_engine'
*/