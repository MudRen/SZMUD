// Сѩ���̣�������Ӯ��Ǯ�Ĵ���ǰ����ģ�������    ��/npc/obj/smsegar.c
// by naihe  2002-04-29
// ������ OK �ˡ�

inherit ITEM;
#include <ansi.h>

int remaining=(5+random(5));

void create()
{
	set_name(YEL"Сѩ��"NOR, ({"smsegar","yan","xiao xuejia"}));
	set_weight(30);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ����������С��������̣��о���˹˹���ĵġ�\n(������ָ�xiyan)\n");
		set("unit", "��");
                set("value", 5000);
	}
	setup();
}

void init()
{
	add_action("do_xiyan", "xiyan");
}

int do_xiyan(string arg)
{
	object me=this_player();

	if (!arg)
	{

		if (me->is_busy())
		return notify_fail("����ô�죬С��Ǻ��~~\n");

		set("value", 0);

		if(me->is_fighting())
		me->start_busy(3);

		me->start_busy(3);
		remaining-=1;

		if (remaining>0)
		{
// ���ϡ���ϡ�����򣰦�������
		switch(random(3))
			{
			case 0 :
			message_vision("
$N����"YEL"Сѩ��"NOR"����һ�ڣ�����˼�����Ȧ��"WHT"���ϡ���ϡ����"NOR"\n",me);
			break;

			case 1 :
			message_vision("
$N����"YEL"Сѩ��"NOR"����һ�ڣ����ؾͰ������˳�����"WHT"~~~~~~~~~"NOR"\n",me);
			break;

			case 2 :
			message_vision("
$N����"YEL"Сѩ��"NOR"����һ�ڣ�����Ǻ�ô�����������\n",me);
			if(me->query("qi") > 22) me->add("qi",-random(5));
			return 1;
			break;
			}
			if(me->query("jing") < me->query("max_jing"))
			me->add("jing",random(5));
		}

		else
		{
			message_vision(""HIC"$N���������һ���̣��ƺ����������š�"NOR"\n",me);
			destruct(this_object());
		}
		return 1;
	}
	return 0;
}
