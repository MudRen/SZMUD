// Code of ShenZhou
// /d/xueshan/obj/lamp.c
//su you deng


#include <ansi.h>

inherit ITEM;
inherit "/d/xueshan/inherit/liquid_container.c";


void create()
{
		object suyou;

        set_name(HIY "���͵�" NOR, ({"lamp"}));
        set_max_encumbrance(200);
        set_weight(600);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "յ");
                set("long", "һյ������Ƶ����͵ƣ�����ʮ�־��ɱ��£�����ȥ��ֵ���ơ�\n");
                set("value", 100000);
				set("no_get",1);
        }

		// mark it as a liquid container
		set("liquid/container",1);
		set_max_liquid(5);
		set_current_liquid(0);
		set("liquid/unique",1);
	    set("liquid/uniqueid","su you"); 

		setup();

}

void init()
{
	add_action("do_light", "light");
	::init();
}


int do_light(string arg)
{
        object  me = this_player();
		object  ob = this_object();

        if (!present("fire", me))
                return notify_fail("��Ҫ��ʲô���\n");
        if (!arg)
                return notify_fail("��Ҫ��ȼʲô��\n");
        if (arg != "lamp")
                return notify_fail("��Ҫ��ȼʲô��\n");
		if (ob->query_current_liquid() < 5)
				return notify_fail("��������Ͳ�������\n");
		if (ob->query("burning"))
				return notify_fail("���͵��Ѿ���������\n");
        message_vision(HIR"$N��ȼ�˵��е����ͣ���ͷð��СС��һ�ɻ��棬ɢ���������������㡣\n"NOR, me);
        set("long", query("long") + HIR"����ȼ��СС��һ�ɻ��档\n"NOR);
        me->set_temp("marks/��", 1);
        set("burning", 1);
        remove_call_out("finish_burn");
        call_out("finish_burn",80+random(80), me);
        return 1;
}

void finish_burn(object me)
{
        int point,i;
		object  ob = this_object();
		object  *inv;

    	inv = all_inventory(ob);

		// destory all liquid inside of the lamp
     	for( i=0; i<sizeof(inv); i++ ) {
		  	destruct(inv[i]);
		}
		ob->set_current_liquid(0);
		set("burning", 0);
        message_vision(HIR"$N�еĻ������������£�����Ϩ���ˣ�ð��һ�����̡�\n"NOR, ob);
        set("long", "һյ������Ƶ����͵ƣ�����ʮ�־��ɱ��£�����ȥ��ֵ���ơ�\n");

}
