/*
进入数据库--mysql -h 127.0.0.1 -uroot -p
一个数据库中可以有多个表,每个数据库之间的数据不影响，每个表之间也不会影响，每个表有包含很多列
数据库查询库：show databases
选择库：use ……
查看库对应的表:show tables
创建库：create database 库名
删除库：drop database 库名(!!!!!!!!!!!!!!!!!!!!!!!!!慎用)
数据库命名规则：不区分大小写,英文，0~9的数字(不常用)，下划线组成
一个项目用一个数据库，多个项目不能使用一个数据库
数据库中的注释为#
数据库中字符串为''
创建表：create table class……(表头1 类型，表头2 类型，表头3 类型……)
class……表示表的名字
查看创建的表头和对应的数据类型：desc 表的名称
将数据插入到表中：insert into 表的名字 value(对应类型的数据)
查询对应表头中的数据：select 表头名称 from 表的名字
查询表中全部信息：select * from 表的名字
查询对应条件下的某个表头中的信息：select 表头名称 from 表的名字 where 条件
表中插入数据时可以加关键字(加在每个数据类型后面)unique/primary key(独一无二的，不能相同) not null(非空)

在整数类型后面的()里面代表的是查看的时候显示几位，配合zerofill使用（类似c中%3d输出）
unsigned加在整型后面，可以将其范围变为0--原来的2倍，如果已经有了zerofill，会自动添加unsigned
auto_increment在数据类型后(整型)，代表可自增类型，一个表中只能有一个auto_increment修饰的列,要配合unique/primary key使用
not null表示不能为空 default表示可以为……

(双)浮点数和c++相同,更高精度的数据类型decimal(M,D),M代表保留数据的总长度，D代表小数点后的长度
最后如果小数点后不够,超过规定的范围,则会四舍五入

时间类型：year 表示年,date表示日期，time表示时间,datetime和timestamp代表时间
其中timestamp到2038年，时间的类型和字符串相同，用''包起来，年月分隔用-,时间分隔用: 年月和时间之间用空格分开
常用的时间接口 curdate()--获取当前日期 now()--获取当前时间(放在datetime和timestamp中)
time()--获取传入的时间中的时分秒 year()--获取传入的时间中的年份 month(),day(),hour(),minute(),second()用法相同

字符串类型char类型最大长度0~255,可以用()来指定长度 varchar开始有一段内存来记录后面存储了多少字符
char插入2个空格以上时会自动屏蔽掉空格后的数据，而且空格后的数据会被char丢弃，varchar就不会
在字符串两侧加()--select concat('(',e_char,')'),concat('(',v_char,')') from char_example;
如果插入的数据超过规定长度，但是结尾有空格(不会报错)，系统会自动把多余的空格截去
查询效率char高于varchar，char需要指定空间,最大保存288长度
如果字符串最后要保留空格，务必选择varchar

text类型：是一种特殊的字符串类型，有tinytext,text,mediumtext,longtext这几个类型，这个类型不用指定长度
mysql编码环境中一个汉字占3个字节,不知道数据的最大长度时可以用text类型
查询的效率char>varchar>text

枚举类型enum(……),mysql中保存的是enum类型中的编号，根据编号找到编号对应的数据(存储节约空间，位存储，易查询)
插入数据时需要插入enum中的数据，或者数字(每次只能选一个选项)
set类型：和enum类型相同，可以多选,选择的时候用一组''把内容括起来就好
select insert+0 from ……以整数的类型查找

二进制类型:binary varbinary tinyblob blob mediumblob longblob bit
binary固定长度，长度不够用/0来补全 varbinary是可变长度，有个最大长度，二者需要()指定长度
bit按位存储,通过()指定的最大位为64位
tinyblob blob mediumblob longblob这几个类型都和varchar一样,开头开辟几个字节的内存来记录后面有多少个字节的数据
tinyblob blob mediumblob longblob这4个类型不用提前指定长度
访问速度：binary>varbinary>blob	可以用varbinary不用blob

数据库中row,column为关键字，不能作为列名
*/
