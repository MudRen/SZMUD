//                ��׼��������ʾ��                                   |
// �����������ӣ�����  ��/obj/yizi.c
// by naihe �κ�  2002-04-23
// ������ı��ļ�Դ�룬лл��

#include <ansi.h>
inherit ITEM;


void create()
{
	set_name(WHT"ʯ��"NOR, ({"yizi", "shiyi", "yi zi"}));
	set_weight(10000);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "һ��ʯ�ϵĳ��Σ������˿���������Ŀ����ͷ��֡���ߵķ��ֿ���һ��С�֣�\n�����佨����������˹���������Ʒ�����ұߵ�����ţ����ɽ�2002��4�¡���\n���������sit����ȥ��Ϣ��\n");
	set("unit", "��");
	set("value", 1);
	set("no_get","1");
	}

	setup();
}

void init()
{
	add_action("do_sit",  "sit");
//	add_action("do_sdup", "sdup");
}

int do_sit(string arg)
{
	object me , test;
	me = this_player();
//	test = present("start_busy()", me);

	if(!arg)
	{
//	me->start_busy(10);
	tell_object(me,"����������ȥ��ͻȻ�����������Ͽ��š����߷��������С���֣��ŵøϿ�����������\n");
	tell_room(environment(me),(string)me->query("name")+"��׼����ʯ��������ȥ��ȴ��֪���������������������������亹��\n",me);
	return 1;
	}
	return 0;
}
/* �������������������Ϣ�����ӵģ�ͻȻ���ò�̫�ã��Ͱ��ˣ����������հ�  ���� ��æʱ�Լ����������Ĺ��ܶ���Ҫ�ˣ�ֻ�ǿ�������  ���� */