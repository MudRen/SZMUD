// unknow.c δ���ɵ�

#include <ansi.h>

inherit ITEM;

void create()
{
	set_name(HIR "δ���ɵ�" NOR, ({ "dan", "xian dan", "xiandan" }) );
	set_weight(200);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("long", "һ��ԲԲ�Ļ���ɵ�����֪����ʲô�ô���\n");
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
        if (me->query("story/unknow") >= 30)
        {
                message_vision("$Nҡҡ�λεģ�ͻȻ��žડ�һ����ˤ�˸���ͷ��\n", me);
                tell_object(me, "����ó����Ժ�ͷ�ؽ���ġ�\n");
        } else
        if (random(3) == 0)
        {
                tell_object(me, "��������ú���ûʲô���á�\n");
        } else
        {
                tell_object(me, HIM "�����ò�͸�Ե�������ˡ�\n" NOR);
                me->add("per", 1);
                me->add("kar", 1);
                me->unconcious();
        }

        me->add("story/unknow", 1);
        destruct(this_object());
	return 1;
}
