// Code of ShenZhou
// tgrass.c ͨ���

#include <ansi.h>

inherit ITEM;

int do_eat(string);
void init();

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
	set_name( GRN "ͨ���" NOR , ({"tongtian cao", "grass"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("material", "grass");
		set("long", "����һ�꿴��������ͨ��С�ݣ�����ʵֻ������������ɽ����������ʹ�ⶾ����Ч��\n");
		set("value", 20000);
	}
	setup();
}

int do_eat(string arg)
{
	object me = this_player();
	if (arg!="grass") return 0;


	message_vision(HIY "$N����һ��ͨ��ݣ����ϵĺ���������һЩ��\n" NOR, me);

	destruct(this_object());
	return 1;
}
