/*-------------------------------------------------------------
** �ļ���: qianceng-xue.c
** Copyright (c) 2000-2001
** ������: Ҷ��
** ��  ��: 2001/08/13
** ��  ��: ǧ��ѩ
**-----------------------------------------------------------*/
#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ǧ��ѩ"NOR, ({"qianceng xue", "xue", "bingqiling"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("s_name","ǧ��ѩ");
		set("long", "����һ�к�·ѩ��Ʒ��ǧ��ѩ��\n");
		set("unit", "��");
		set("value", 100);
		set("remaining", 20);
		set("food_supply", 10);
		set("drink_supply", 10);
	}

	setup();
}

void init()
{
	add_action("do_drink", "eat");
}

int do_drink(string arg)
{
	if (arg!="qianceng xue" && arg!="xue" && arg!="bingqiling") return 0;
	if (this_player()->is_busy())
		return notify_fail("����һ��������û����ɡ�\n");

	if ((int)this_player()->query("water")
		>= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
	if ((int)this_player()->query("food")
		>= (int)this_player()->max_food_capacity() )
		return notify_fail("���Ѿ��Ե�̫���ˣ���Ҳ�Ų����κζ����ˡ�\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));
	this_player()->add("food", (int)query("food_supply"));

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	add("remaining", -1);
	if (query("remaining")) {
		message_vision("$N��С��Ҩ��һ�ױ���ܣ�����һ�ڣ�ֻ�������ɿڡ�\n",this_player());
	}
	else {
		message_vision("$N��С��Ҩ�����һ�����ܣ�������ȥ��\n",this_player());
		destruct(this_object());
	}
	return 1;
}

