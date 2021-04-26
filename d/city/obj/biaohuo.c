// Code of ShenZhou
// biaohuo.c

#include <ansi.h>
inherit ITEM;

void create()
{
	set_name("����", ({"hong biao", "biao"}));
	set("long",
		"����һ�ݺ��ڣ���װ�طǳ���ϸ����֪װ��ʲô������\n");
	set("unit", "��");
	set("weight", 20);
}

void init()
{
	object obj = this_object();
	object ppl = this_player();
	int t;

	t = 100 + random(20);
	remove_call_out("destroy_it");
	call_out("destroy_it", t, ppl, obj);

	add_action("do_check", "check");
}

int do_check()
{
	object ppl = this_player();
	
	if ( ppl->query_temp("biao/li") ) write("���ǻ�ɽ������ȪԺ��������ڻ���\n");
	if ( ppl->query_temp("biao/ma") ) write("����Ȫ��������ݹ����������ʦ���͵��ڻ���\n");
	if ( ppl->query_temp("biao/zhu") ) write("���ǰ�¹��Ժ�����������ڻ���\n");
	if ( ppl->query_temp("biao/bayi") ) write("���Ǳ���С��������͵����ڣ�Ҫ�����͵���\n");
	if ( ppl->query_temp("biao/jiang") ) write("���ǵ����������������еĺ��ڣ��뽻���ױ��ӳ�����ʤ���\n");

	return 1;
}

void destroy_it(object ppl, object obj) 
{ 
	tell_object( ppl, "ʱ���ѵ����������ʧ���ˣ�\n" );
	ppl->delete_temp("apply/short");
	ppl->delete_temp("biao");	
	ppl->set_temp("biao/fail", 1);
	destruct(obj); 
}
