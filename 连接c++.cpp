/*
MYSQL mysql;
MYSQL_RES *res=NULL;//���ݲ�ѯ�Ľ��
MYSQL_ROW row;
mysql_init(&mysql);//��ʼ�����ݿ�
mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "gbk");//ѡ�����ݿ���ַ�����
//�������ݿ�
if (mysql_real_connect(&mysql, "127.0.0.1", "root", "&0312163315Dl", "tast", 3306, NULL, 0) == NULL)
{
cout << "����ԭ��" << mysql_error(&mysql) << endl;
cout << "����ʧ��" << endl;
system("pause");
exit(1);
}
//ret�����Ƿ�ִ�гɹ�(���ݿ���Ϊ�ղ�����)��0����ɹ���1����ʧ��
int ret = mysql_query(&mysql, "select * from student");//mysql��ִ�еĲ���
res = mysql_store_result(&mysql);//��ȡ��ѯ�Ľ��
row = mysql_fetch_row(res);//����ѯ�Ľ����res���ó�
//�жϲ�ѯ�Ľ���Ƿ�Ϊ��
if(row==NULL)
{
mysql_free_result(res);//������ͷ�
mysql_close(&mysql);//�ر����ݿ�
}
row[n]--����Ĳ�ѯ�ı��еĵ�n�е�����
row[n]������Ϊ�ַ������ͣ���Ҫǿת����
//ִ��mysql�Ĳ���
char sql[256];//mysql��Ϊc���͵��ַ���
//��Ҫִ�е���丳ֵ��sql�ַ���
_snprintf_s(sql, 256, "delete from is_finished where name=%s", name.c_str());
mysql_query(&mysql,sql);
*/