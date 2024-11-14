/*
查询去重:select distinct 列1,列2 from 表

in关键字(用于where条件)：select 列1,列2 from 表 where 列 in(value1,value2,value3) ()代表一个区间
也可用not in进行反向查询
如果在in的区间中有null关键字，则不会查询到有null的数据,如果not in中有null，则不会查到任何信息

between and关键字(用于where)：select 列1,列2 from 表 where 列 between A and B
可以使用and和or来修饰条件

like关键字：可以查询到字段中含有类似关键字的数据-->查询语句+where 列 like ……
like配合通配符使用：_ 匹配单个字符 %匹配任意长度的字符0~无穷
查询字段中含有某个字符的数据 可以用%A%来查询,或者%A%B%
查询字段中多个字符-->查询语句 where 列1 like %A% and 列1 like %B%
也可以反向查询-->where后加not或!

对查询结果进行排序-->select * from 表 order by 列 ASC/DESC
如果排序中存在null，则DESC会放在底部，ASC会放在顶部

对数据进行分组:group by 列----按相同的列分为n组
对数据求和sum(列) 对表中的记录进行统计-->count(*)对表中所有数据进行统计个数(null也可以统计)
count(列)对指定的列进行统计个数(忽略null)
显示分组结果中每组中的列的数据-->group_concat(列)
统计平均值-->avg(列) 统计最大值-->max(列) 统计最小值-->min(列)
-------------------------------------在多个表中查询
联合查询--联合多个表一起查询,关键字 inner join
select 列 from 表1 inner join 表2 on 条件---条件一般是两个表中的公共部分(注意条件前是on,不是where)
对于一些表名较长的表，在查询时可以对表名取别名，只需在查询时紧接着表名写别名即可
select a.class_id,a.class_name,a.human,b.id,b.name from class a inner join student b on a.class_id=b.class_id;
等值连接--自连接，将一个表中含有相同信息的数据联合在一起--思路就是给一个表取两个别名，然根据条件查询
select * from student a inner join student b on a.class_id=b.class_id and a.class_id=1 and a.id!=b.id

左外连接--这里有左右表的概念，左表就是查询from的那个表
select ? from 左表 left join 右表 on 条件
左外连接查询的结果最少为左表的所有数据,和原来不同的是之前的联合查询中只显示两个表中信息匹配的数据
而左表查询显示的是二者匹配的数据+不匹配的数据但存在于左表的数据，但因为和另一个表中数据不匹配
所以查询时不匹配的那一个数据在右表中显示为NULL
右外连接和左外连接相同

合并查询--将多个表信息依次从上到下显示出来,当然查询表的列数必须是一样的
select 列 from 表1 union/union all select 列 from 表2……
union all关键字是把所有表的信息完全照搬过来，union是将union all后的结果进行一次去重
子查询：一个查询语句中包含另一个查询条件
比较运算符的子查询:select * from 表1 where 列=(select 列 from 表2 where 条件)
注意：子查询的条件查询出来的数据不能大于1
in关键字--如果子查询的结果有多个，则需要用in将=替换掉
exists关键字--用于查询语句where中,exists后加(查询语句),如果能查询到,返回true，否则为false
any关键字--用于查询语句where中,any(查询语句),返回的结果为查询到所有的数据,where 列 >/</=/…… any(查询语句)
当where中比较时，满足any()中的哪个数据，就把对应的数据输出出来(满足any中的一个数据的条件就行)
all关键字--与any相同，不过where比较时，条件要满足all中的所有数据，才能把满足all所有条件的数据查询出来
*/