//code by cheap
//С�Ƴ�
#include <ansi.h>
#include <room.h>
inherit ITEM;
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
int do_drive(string arg);
void set_owner(object owner);
void create()
{
        set_name("С�Ƴ�", ({ "xiao tuiche","che" }));
        set_color("$HIW$");
        set_weight(50000000);
       set_max_encumbrance(700000000);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ������װ��ʯ�õĳ���\n");
set("value",1000000);
set("no_get",1);
set("checkcar","/newjob/tiejiang/obj/xiao_tc.c");
                   }
}
int is_container() { return 1; }

int reject(object ob)
{
int value;
        if (ob && ob->query("ore") ) return 0;
        notify_fail("��ֻ�ܷſ����복�\n");
        return 1;
}
void init()
{
object ob;
add_action("do_drive","cun");
add_action("do_drive","push");
}
void set_owner(object owner)
{
object ob = this_object();
set("owner", ob);
}

int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("��Ҫ��ʲô��\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("ָ�����\n");

        if ( victim == me->query("id") ) return notify_fail("�αض��һ�٣�\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("��Ҫ��ʲô��\n");

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
if( query("owner") != me->query("id"))
               return notify_fail("�ⲻ����ĳ�! \n");
        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"$N"+HIG"������$n"+HIG"��"+target_dir+"��ȥ��\n" NOR, me, ob);
         me->move(obj);
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
                                        message_vision( HIG"$N�ƶ�"+target_dir+"ʻ��ȥ��\n" NOR,me);
                                        me->move(obj);
                                        message_vision( HIG"$N�ƶ�С�Ƴ�ʻ������\n" NOR,me);
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
