/*
触发器：相当于在某条语句执行前/后，通过触发器来执行某些特定语句(类似于if)
触发器的创建-->create trigger 触发器名 before/after 触发事件 on 表名 for each row 触发要执行的操作
其中的触发事件包括insert,update,delete
触发要执行的操作中，如果触发事件为insert，则用new来代替insert的数据,用old代替delete的数据，
update前的数据用old表示，update后的数据用new表示
触发器执行多条操作:
存在问题：执行多条操作时，每个操作需要用';'分开，但是';'表示语句的结束，所以要重新定义一个语句结束的标志
改变结束标志-->delimiter 标志
执行多条操作-->create trigger 触发器名 before/after 触发事件 on 表名 for each row
begin 触发要执行的操作1;触发要执行的操作2; end 结束的标志
最后记得将结束标志变回';'
不能创建两个相同的触发器(包括名字相同、执行的操作相同、执行的时机相同)
触发器的查询和表类似
*/