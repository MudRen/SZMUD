// xisuidan.c �ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIW "���͵�" NOR, ({ "dan", "kaolao dan", "kaolaodan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "������ö��ҩ�������õĻ����������30�㹱�׶ȡ�\n");
                set("value", 10000);
		set("unit", "��");
	}
}

void init()
{
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object me;

        if (! id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

        me = this_player();
        message_vision("$Nһ������������һ��" + this_object()->name() +
                       "��\n", me);
        if (me->query("stroy/kaolao") >= 1000000)
        {
                message_vision("$NͻȻ����һ������ޱȵ���ƨ��\n", me);
                tell_object(me, "����ô���ǳԻ��˶��ӡ�\n");
        } else
        if (random(10) == 0)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIY "��е��Լ������ݹ��׶������ˡ�\n" NOR);
                me->add("shenzhou/pts", 50);
        }

        me->add("story/kaolao", 1);
        destruct(this_object());
	return 1;
}
