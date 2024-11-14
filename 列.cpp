/*
列的完整性约束：
数据库中列中数据的约束没有顺序,mysql会自动识别

主键约束--primary key，列中主键是唯一的，通过主键能更快的速度查找到数据(不允许为NULL)
每个列只能有一个主键
对多个数据添加主键性质create table ……(名字1 类型,名字2 类型,primary key(名字1,名字2))
这时多个数据为一个联合主键，类似f(x,y)一样，只有当插入的x,y都一样时才不允许插入
查询实现表时的定义---show create table ……

外键约束--首先是两个表之间，一般是父子关系，1对多，外键可以为null
设置外键时要依赖已存在父表中的主键
create table 子表名称 (…………foreign key(名字)references 父表(父表中主键))
不能创建父类主键以外的数据,当然删除的时候要先删除子表才能删除父表

表字段唯一约束--unique(与primary key不同的是unique可以允许有多个为NULL)
自增长性约束 auto_increment由于是自长性，所以必须配合unique(或primary key,foreign key)来使用
也就是设置为键key(主键，外键，唯一键)

字段默认值 default,当某个变量没有设置值，就会默认设置为default的值
不设置default后的值的话，默认为NULL
------------------------------------------------
调整列的约束:
对列添加键的性质-->
alter table 表名 add constraint 约束名(便于删除) 键类型(unique,primary key,foreign key) (要添加键的列)
查询查询键值的约束名-->show index/key from 表名
对列的键属性进行删除-->
对主键的删除-->alter table 表名 drop primary key
对其他键的删除-->alter table 表名 drop index 约束名
修改列的其他性质(not,default,auto_increment)-->alter table 表名 modify 列名 重新对列定义
插入多条数据，普通的添加一条数据后面 value(添加数据1),(添加数据2),(添加数据……)

更新数据-->update 表名 set 列名1=修改的数据1,列名2=修改的数据2 where 条件-----这里的条件最好选唯一列限制的数据
更新所有数据记录-->update 表名 set 列名1=修改的数据1,列名2=修改的数据2……

删除数据-->delete from 表名 where 条件 (全部删除 不写条件)
对一个已存表添加列-->alter table 表名 add 列名 对列的定义
对一个已存在表的列进行修改(不是只修改属性)-->alter table 表名 change column 原表的列名 修改后的列名 对列的定义
对列的删除-->alter table 表名 drop column 列名
*/