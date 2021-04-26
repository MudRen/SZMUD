// Code of ShenZhou

// d/emei/obj/flower.c
// xbc 1997/02/03

#include "ansi.h"
inherit ITEM;

string* titles = ({
        "������",
        "������",
        "������",
        "������",
        "������",
        "������",
        "������",
        "������",
});

void create()
{
        int i;
        i = random(sizeof(titles));
        if (i<2)
        set_name(HIW+titles[i]+NOR, ({ "tulip", "flower", "hua" }));
        else if (i<4)
        set_name(HIM+titles[i]+NOR, ({ "tulip", "flower", "hua" }));
        else if (i<6)
        set_name(HIR+titles[i]+NOR, ({ "tulip", "flower", "hua" }));
        else
        set_name(HIY+titles[i]+NOR, ({ "tulip", "flower", "hua" }));

        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ��ո�ʢ���������㣬�������з���������������\n");
                set("value", 0);
        }
}


void init()
{
        add_action("do_smell","smell");
        add_action("do_dai","dai");
}

int do_smell(string arg)
{
        object me = this_player();
        object flower = present("flower", me);

        if ( !arg|| arg != "flower" ) 
           return notify_fail("��Ҫ��ʲô��\n");

        message_vision("$N����" + (string)flower->query("name") +"�����ڱǶ������һ�š�\n", me);
        return 1;
}

int do_dai(string arg)
{
        object weapon, flower, target, me = this_player();
        string arg1, arg2;
        int argc;

        if ( !arg ) return notify_fail("��Ҫ��ʲô��\n");

        if ( (argc = sscanf(arg, "%s %s", arg1, arg2)) != 2) {
                argc = 1;
                arg1 = arg;
        }

        if ((argc == 1 && arg1 != "flower"))
                return notify_fail("��Ҫ��ʲô��\n");

        if (argc == 1) {
                if ( arg1 != "flower" )
                        return notify_fail("��Ҫ��ʲô��\n");

                if ( !(weapon = present( "flower", me)) ) 
                        return notify_fail("��û�л����Դ���\n");

                if ( me->query("gender") == "Ů��" ) {
                        message_vision("$N��" + (string)weapon->query("name") +"���ڷ��ʣ��ø���ò���\n", me);
                }
                else {
                        message_vision("$N��" + (string)weapon->query("name") +"������ǰ���ø��������ɡ�\n", me);
                }
                target = me;
        }
        else if (argc == 2) {
                if ( !(target = present(arg1, environment(me)))
                     || !target->is_character() )
                        return notify_fail("����û������ˡ�\n");

                if ( !userp(target) || target==me) 
                        return notify_fail("�Ҹ���������ڰɡ�\n");

                if ( arg2 != "flower" ) 
                        return notify_fail("�����" + target->name() + "��ʲô��\n");

                if ( !(weapon = present( "flower", me)) ) 
                        return notify_fail("��û��" + (string)weapon->query("name") +"���Դ���\n");

                if ( target->query("gender") == "Ů��" ) {
                        printf("�㽫" + (string)weapon->query("name") +"����%s�ķ��ʣ��ø���ò���\n", 
                                target->name());
                        message("vision", 
                             sprintf("%s��" + (string)weapon->query("name") +"������ķ��ʣ��ø���ò���\n",
                                  me->name()), target);
                        message("vision", 
                             sprintf("%s��" + (string)weapon->query("name") +"����%s�ķ��ʣ��ø���ò���\n",  
                                  me->name(), target->name()), environment(me), ({me, target}) );
                }
                else {
                        printf("�㽫" + (string)weapon->query("name") +"����%s����ǰ����������\n", 
                                target->name());
                        message("vision",
                             sprintf("%s��" + (string)weapon->query("name") +"���������ǰ���ø��������ɡ�\n",
                                me->name()), target);
                        message("vision", sprintf("%s��" + (string)weapon->query("name") +"������%s��ǰ���ø��������ɡ�\n", 
                                me->name(), target->name()), environment(me), ({me, target}) );
                }
        }

        weapon->move(target);
        
        return 1;
}        

