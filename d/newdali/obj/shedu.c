// Code of ShenZhou
// Kane 13/8/98

#include <ansi.h>
inherit ITEM;

void create()
{
        set_name("�߶�", ({"she du", "du"}));
        set_weight(180);
        if (clonep())
                set_default_object(__FILE__);
        else {
         set("long", "һƿ���ƺõ��߶���\n");
                set("unit", "ƿ");
                set("poison_type", "snake_poison");
		set("poison_applied", 100);
		set("value", 0);
//		set("no_get", 1);
        }
}

void init()
{
   add_action("do_coat", "coat");
   add_action("do_coat", "tu");
}

int do_coat(string arg)
{
        object me, ob, obj;
        function f;

        if (!arg || !(ob = present(arg, this_player())))
                return notify_fail("��Ҫ��ʲô��\n");

        if ( ob->query("weapon_type") != "arrow" )
                return notify_fail("�߶��ɲ���ϹͿ��\n");

        if ( ob->query("poison_applied") > 0)
                return notify_fail("�����������Ѿ�ι�ж�ҩ�ˡ�\n");

/*
        if (this_player()->query_skill("poison", 1) < 100)
                return notify_fail("�㻹û��������������ι���ļ��ܡ�\n");
*/

	me = this_player();
	obj = this_object();
        message_vision(RED"$NС������ذ�"+ob->query("name")+"��$n�н���һ�����\n"NOR, me, obj);
        
	if( me->query_skill("poison",1) < random(100) ) {
		message_vision(HIR"$Nһ��С�Ľ���һЩ$n�����ϣ�\n"NOR,me,obj);
		me->apply_condition(obj->query("poison_type"),
		obj->query("poison_applied")/2);
	}

	ob->set("poison_applied", obj->query("poison_applied"));
        ob->set("poison_type", obj->query("poison_type"));
	ob->set("no_sell");
        ob->set("long", ob->query("long") + BLU"�����ƺ�ι�о綾��\n"NOR);
        call_out("destroy_it", 1, this_object());
        return 1;
}

void destroy_it(object obj)
{
        destruct(obj);
        return;
}
