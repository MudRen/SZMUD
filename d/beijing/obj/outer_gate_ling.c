//Cracked by Roath
// /d/beijing/obj/outer_gate_ling.c
// chu: the lingpai that allows npc/player to enter beijing with weapon

#include <ansi.h>

inherit ITEM;

int do_allow(string);

void init()
{
    if (!wizardp(this_player())) {
        set("no_get", "���˰ɣ�������ƶ��������ο��أ�\n");
	set("no_drop", "������Ƹ����ˣ��㲻Ҫ���ˣ�\n");
    }
    add_action("do_allow", "allow");
}

void create()
{
    set_name("�Ƿ�����", ({"lingpai"}));
    set_weight(600);
    if (clonep())
	set_default_object(__FILE__);
    else{
        set("unit", "ֻ");
        set("long", "���Ǳ����ĳǷ����ƣ�����������׼ (allow) ����Я�������\n");
        set("value", 0);
        set("material", "bamboo");
    }
    setup();
}

int do_allow(string name)
{
    object ling=this_object(), me=this_player(), obj;

    if (!name || name=="") {
	return notify_fail("������˭���ţ�\n");
    }
    
    if(!objectp(obj = present(name, environment(me))))
         return notify_fail("����û������ˡ�\n");

    if (!obj->is_character() || obj->is_corpse())
         return notify_fail("������㣬�ⲻ�ǻ��ˡ�\n");

    message_vision("$N����$n������ֵ�˵����"
	"�����ү����ã�������������ǰɡ�\n",	me, obj);
    obj->set_temp("outer_gate_allowed", 1);
    return 1;
}