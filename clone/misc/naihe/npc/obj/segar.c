// ѩ���̣�������Ӯ��Ǯ�Ĵ���ǰ����ģ�������    ��/npc/obj/segar.c
// by naihe  2002-04-29
// ������ OK �ˡ�

inherit ITEM;
#include <ansi.h>

int remaining=(10+random(6));


void create()
{
        set_name(YEL"ѩ����"NOR, ({"segar","xuejia","yan","xuejia yan"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else
	{
		set("long", "����һ������ľ��̣��ִֵ�ģ����Ϊ���ɡ�\n(������ָ�xiyan)\n");
		set("unit", "��");
                set("value", 10000);
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

// ���ϡ���ϡ�����򣰦�������

		if (remaining>0)
		{
		switch(random(7))
			{
			case 0 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ�����Ǻ�ô�����������\n",me);
			if(me->query("qi") > 22) me->add("qi",-random(10));
			return 1;
			break;

			case 1 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ�Ư��������˼�����Ȧ��"WHT"���� �� �� �� ��"NOR"\n",me);
			break;

			case 2 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ�����˼���˫�ص���Ȧ��"WHT"�������"NOR"\n",me);
			break;

			case 3 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ��������Ȧ�����֪�������Щʲô��"WHT"~~~~~~~~~~~~~"NOR"\n",me);
			break;

			case 4 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ����ҵ�����˼�����Ȧ��"WHT"���ϡ���ϡ����"NOR"\n",me);
			break;

			case 5 :
			message_vision("
$N����"YEL"ѩ����"NOR"����һ�ڣ����������˼�����Ȧ��"WHT"�� �� �� �� �� ��"NOR"\n",me);
			break;

			case 6 :
			message_vision("
$N����"YEL"ѩ����"NOR"���������һ�ڣ����һ�һཱུ�����ü�����Ȧ��"WHT" ���য��������"NOR"\n",me);
			break;
			}
			if(me->query("jing") < me->query("max_jing"))
				me->add("jing",10+random(6));
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
