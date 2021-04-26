// Code of ShenZhou
// box.c ����

#include <ansi.h>
inherit ITEM;

void create() {
    set_name("����", ({"box"}));
    set_weight(100);
    if( clonep() )
        set_default_object(__FILE__);
    else {
        set("unit", "ֻ");
        set("long", "�˺и�Լһ�߼�������֪������װ��ʲô������\n");
        set("material", "steel");
        set("value", 100);
        set("no_get", 1);
   }
}

void init() {
    object ob = this_object();

	 //if (!ob->query("flag"))
	 ob->set("flag", 0);
    add_action("do_open", "open");
}

int do_open(string arg) {
    object ob = this_object(), flag, npc, me=this_player();

    if ( !arg || arg != "box" )
        return notify_fail("��Ҫ��ʲô�򿪣�\n");

    if ( me->query_skill("dodge") > 200 && me->query("jingli") > me->query("max_jingli")/2 ) {
        if (ob->query("flag") == 1) {
            message_vision("$N�����䣬����������һ�����ġ�\n", me);
            message_vision(HIR"$N��������һ��չ�������ִ��죡\n"NOR, me);
            me->start_busy(7 + random(5));
            flag = new(__DIR__"flag");
            flag->move(me);
            ob->set("flag", 0);
            return 1;
        }
        else {
            message_vision("$N�����䣬���������ǿյġ�\n", me);
            me->start_busy(7 + random(5));
            return 1;
        }
    }
    else {
        message_vision(HIR"$N�����䣬ͻȻ�����������֧ӲŬ��ȫ��������$N���ϣ�\n"NOR, me);
        me->receive_wound("qi", me->query("max_qi")+ 1);
        return 1;
    }

        return notify_fail("��Ҫ��ʲô��\n");
}
