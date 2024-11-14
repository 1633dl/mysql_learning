/*
MYSQL mysql;
MYSQL_RES *res=NULL;//数据查询的结果
MYSQL_ROW row;
mysql_init(&mysql);//初始化数据库
mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");//选择数据库的字符类型
//连接数据库
if (mysql_real_connect(&mysql, "127.0.0.1", "root", "&0312163315Dl", "tast", 3306, NULL, 0) == NULL)
{
cout << "错误原因" << mysql_error(&mysql) << endl;
cout << "连接失败" << endl;
system("pause");
exit(1);
}
//ret接受是否执行成功(数据库中为空不计入)，0代表成功，1代表失败
int ret = mysql_query(&mysql, "select * from student");//mysql中执行的操作
res = mysql_store_result(&mysql);//获取查询的结果
row = mysql_fetch_row(res);//将查询的结果从res中拿出
//判断查询的结果是否为空
if(row==NULL)
{
mysql_free_result(res);//将结果释放
mysql_close(&mysql);//关闭数据库
}
row[n]--代表的查询的表中的第n列的数据
row[n]的类型为字符串类型，需要强转类型
//执行mysql的操作
char sql[256];//mysql中为c类型的字符串
//将要执行的语句赋值给sql字符串
_snprintf_s(sql, 256, "delete from is_finished where name=%s", name.c_str());
mysql_query(&mysql,sql);
*/