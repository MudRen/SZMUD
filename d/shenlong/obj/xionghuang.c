// Code of ShenZhou
// xionghuang.c �ۻ�
// ywz 08/31/96

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
	set_name(YEL "�ۻ�" NOR, ({"xionghuang", "huang"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("unit", "��");
		set("long", "����һ���ۻƣ�����ȥ�Ƴγεġ�\n");
		set("value", 500);
        }

        setup();
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
		return notify_fail("��Ҫ��ʲô��\n");

	return notify_fail("�ⶫ��������ô�ԡ�\n");

//	destruct(this_object());
        return 1;
}
