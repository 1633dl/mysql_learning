/*
�洢���̺ͺ��������浽�������ˣ������˿ͻ��˺ͷ����������ݵĽ�������ֹ��д�ظ���sql���
�ʹ�����ԭ����ͬ�������ڷ�����
�����Ķ��壺���Ⱥ�����Ҫִ�ж�����Ϊ�����Դ��ںʹ���������ͬ�����⣬Ҫ���¶�������ַ�
-->create procedure ������ (in/out/inout ������ ����)--in��ʾ����,out��ʾ�����inout��ʾ�����������
begin
declare ������(����ΪA) ����----�������(��c�������෴)
select �� into A from �� where ����---into A��ʾ����ѯ�������ݸ�ֵ��A
ִ�е���Ϊ
end
�����ַ�
���ú���-->call ������(����)

��ѯ�Լ������Ĵ洢-->show procedure status like '?'\G
����-->show create procedure ������\G
����-->select routine_definition from information_schema.Routines where routine_name='�洢��'

�����Ķ��壺delcare a,b,c ���� default ?---ͬʱ������������Ĭ��ֵΪ?
�����ĸ�ֵ-->set ����1������2���� =?
��select ? into ���� from ����
���ں����б��д���Ĳ��������Ϊout��Ҳ����������ͣ���ô�����������ǿ����ں����ⲿ�õ���(out A int)
���ڵ�������洢������out���͵Ĳ���ʱ������ǰ��Ҫ��@,���Ҳ��������ֺ�ԭ����������ͬcall ?(@A)
���ⲿ�õ����out���͵Ĳ���ʱҲ��Ҫ�ڲ�����ǰ��@
ͨ��select ������ֱ�Ӳ�ѯ

��꣺���洢��������Ҫ���������ݶ�ȡʱ�������Խ��洢�н��ж�ȡ��Ԫ���ó����ָ����������˱����ĸ�ֵ
�����ڴ�����Ϊ֮ǰ�������ڴ洢�еı���֮��
����-->declare ����� cursor for ��ѯ���
�򿪹��-->open �����
ʹ�ù�꣺������ж�ȡ�������ݴ��浽������-->fetch ����� into ����1,����2
����һ���жϹ���Ƿ���ҵ����ݵı�����declare A int default 0;
�������һ��Ҫ�����ڹ�궨��֮ǰ
������Ҳ�������-->declare continue handler for not found set A=1;
�رչ��-->close �����

if else���-->if ����1 then ִ����� elseif ����2 then ִ����� else ִ����� end if
case���-->case ���� when ����1 then ִ����䡭�� end case
loopѭ�����-->ѭ����ǩ/����:loop ѭ����ִ����� end loop ѭ����ǩ
�˳�ѭ��-->leave ѭ����ǩ
iterate�����´�ѭ��-->iterate ѭ����ǩ(�൱��continue)
repeatѭ��-->repeat ѭ����� until �������� end repeat(�൱��do while)
whileѭ��-->while ѭ������ do ѭ����� end while

���⣺����һ�����е�һ���������͵����ݣ��������Զ��ı�����ͣ����Կ�����max,minѰ��
���ǻ��ж���û��������ݣ���ʱmax/min���ܸı䣬���Լ���������ݸ��ǵ�
������select last_insert_����()����(ֻ����������������)
select last_insert_����() as ?-->����ѯ�����ݱ�����?��
����ѯ��ǰ���������һ�����������

�鿴��ǰmysql���õ�����-->show variables like 'default_storage_engine'
*/