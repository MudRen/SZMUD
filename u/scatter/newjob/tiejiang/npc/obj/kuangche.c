#include <move.h>
#include <ansi.h>
#include <room.h>
inherit ITEM;
int return_home(object home);

mapping default_dirs = ([
        "north":        "��",
        "south":        "��",
         "east":         "��",
        "west":         "��",
        "northup":      "����",
        "southup":      "�ϱ�",
        "eastup":       "����",
        "westup":       "����",
        "northdown":    "����",
        "southdown":    "�ϱ�",
        "eastdown":     "����",
        "westdown":     "����",
         "northeast":    "����",
         "northwest":    "����",
         "southeast":    "����",
         "southwest":    "����",
         "up":           "��",
         "down":         "��",
         "out":          "��",
          "enter":        "��",
]);
int do_ride(string arg);
int do_unride(string arg);
int do_drive(string arg);

void create()
{
        set_name("��", ({ "kuang che", "car", "che" }));
        set_color("$CYN$");
        set_weight(50000000);
 set_max_encumbrance(700000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("no_get",1);
                set("material","steel"); 
                set("unit", "��");
                set("long", "����һ������װ��ʯ�õĳ���\n");
                               setup();
}
}
int return_home(object home)
{
return 1;
}
void init()
{ 
object ob;
add_action("do_ride", "ride");
add_action("do_drive","push");
add_action("do_drive","shang");
add_action("do_unride","leave"); 
}
int do_ride(string arg)
{
        object me = this_player();
        object cart = this_object();


        if (!arg) return notify_fail("��Ҫ��ʲô��\n");

        if( me->query_temp("riding") )  return notify_fail("���Ѿ��ڿ��ϣ�\n");
        if( cart = present("kuang che",environment()) );

        message_vision(HIR"$N"+HIR"�����������˿�!\n"NOR,me);
        me->set_leader( cart );
        me->set_temp("riding",1);
        return 1;
}

int do_unride(string arg)
{
        object me = this_player();

        if( !me->query_temp("riding") )  return notify_fail("���Ѿ����ڿ��ϣ�\n");

        message_vision(HIR"$N"+HIR"�����˿󳵣�\n"NOR,me);
        me->delete_temp("riding");
        return 1;
}


int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("��Ҫ����ʲô��\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

        if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

        if( !me->query_temp("riding") )  return notify_fail("���ֲ����ڳ��ϣ���ô�ϳ���\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("��Ҫ����ʲô��\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("���ﲢ�޴��ˣ�\n");

        if ( me->is_busy() ) return notify_fail("����æ���أ�\n");

        env = environment(me);
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("�޴˷����ȥ��\n");

        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("�޷��ߣ�\n");
        if( !wizardp(ob) && obj->query("short") == "��ʦ��Ϣ��" )
                return notify_fail("�޷��ߣ�\n");

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"$N"+HIG"��������ӣ������������Ӽ���$n"+HIG"��"+target_dir+"ʻȥ��\n" , me, ob);

        if( robber && ( robber->query("owner") == me->query("id") || robber->query("owner2") == me->query("id")) )
        {
                message_vision( HIR"$N�ȵ������û�ţ�\n"NOR,robber);
                return 1;
        }

/*
        if( ob->query("owner") != me->query("id") && ob->query("owner2") != me->query("id") )
        {
                message_vision( HIW"��������������$N��\n" NOR,me);
                return 1;
        }
*/

        message("vision", HIY "ֻ��"+ob->name()+HIY"��¡¡���ص���"+target_dir+"ʻ��ȥ��\n" NOR, environment(ob), ({ob}));

        if( ob->move(obj) ) {
                        message( "vision", HIY "ֻ��һ��"+ob->name()+HIY"��¡¡���ص�ʻ�˹�����\n" NOR, environment(ob), ({ob}));

                        busy_time = 4 + random(4);

                        if( ob->query("owner") )
                        {
                                if( (me = present( ob->query("owner"),env )) && me->query_temp("riding") )
                                {
                                        message_vision( HIG"$N�����ڳ�����"+target_dir+"ʻ��ȥ��\n" NOR,me);
                                        me->move(obj);
                                        message_vision( HIG"$N�����ڳ���ʻ������\n" NOR,me);
                                        me->start_busy( busy_time );
                                        all_inventory(env)->follow_me(me,dir);
                                }
                                else if ( (me = present( ob->query("owner"),environment(ob) )) )
                                        me->start_busy( busy_time );
                        }

                        if( ob->query("owner2") )
                        {
                                 if( (partner = present( ob->query("owner2"),env )) && partner->query_temp("riding") )
                                 {
                                        message_vision( HIG"$N�����ڳ�����"+target_dir+"ʻ��ȥ��\n" NOR,partner);
                                        partner->move(obj);
                                        message_vision( HIG"$N�����ڳ���ʻ������\n" NOR,partner);
                                        partner->start_busy( busy_time );
                                        all_inventory(env)->follow_me(partner,dir);
                                 }
                                 else if( (partner = present( ob->query("owner2"),environment(ob) )) )
                                {
                                if (ob->query("owner2") && ob->query("race") == "����" )
                                {
                                        partner->start_busy( busy_time );
                                        }
                                }
                        }
 }
        return 1;
}
