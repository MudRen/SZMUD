/* renshen-guo.c �˲ι�*/
/* written by Dewey */

#include <ansi.h>

inherit ITEM;

 void create()
{
        set_name(HIG "�˲ι�" NOR, ({"renshen guo", "guo"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "һö��ò����Ĺ��ӡ�\n");
                set("value", 100000);
        }

        setup();
}

void init()
{
    if (!wizardp(this_player())) {
        set("no_get"," �ò���! \n");
        set("no_drop","��ô������˲ι�����������! \n");
       }
        add_action("do_eat", "eat");
       
}

int do_eat(string arg)
{
        object me = this_player();

        if (!id(arg))
           return notify_fail("��Ҫ��ʲô��\n");
        me->set("qi",(int)this_player()->query("max_qi"));
		me->set("jing",(int)this_player()->query("max_jing"));
		me->set("force", (int)this_player()->query("max_force"));
		me->add("max_neili",1+random(2));
         
        message_vision(HIG
        "$N����һö�˲ι���ֻ���þ���������Ѫ��ӯ����������ԴԴ���������Ϲ���������
͸ʮ����¥���鲼��������ȫ������Ȼ��� !\n"NOR,me);
        destruct(this_object());
return 1;


}
