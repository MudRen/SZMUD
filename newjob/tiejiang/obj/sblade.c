#include <ansi.h>
#include <weapon.h>
inherit BLADE;
void create()
{
        object me = this_player();

        set_name(me->query("tiejiang/wname"), ({ me->query("tiejiang/wnamee"), "blade", "dao" }));
        set_weight(me->query("tiejiang/weight"));
                if (clonep())
                set_default_object(__FILE__);
        else 
                {
                set("unit", "��");
                set("long", "BETA BLADE NO DESCRIPTION\n");
                set("value", 300);
                set("material", "steel");
                set("wtype", "sblade");
                                set("rigidity", me->query("tiejiang/strength"));
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ص��ʡ�\n");
                }
                init_blade(20);
                setup();
}

void init()
{
                set("vsweapon", 1);
                //add_action("do_check", "maxstr");
                write("Mark First\n");
                //set("tiejiang/damage", this_player()->query("tiejiang/damage"));
                call_out("start_detect",1);
}

/*
int do_check(string arg)
{
        object me=this_player();
        if(!me->query_temp("weapon"))
        {
                write("MARK 1\n");
        }
        else
        {
                write("MARK 2\n");
                write(me->query_temp("weapon"));
        }
        return 1;
}
*/

void start_detect()
{
        object me=this_player();
        object ob=this_object();
                object obj=me->query_temp("weapon");
                int obstr, adamage;

                if (!obj)
                {
                        if(me->query_temp("vsweaponon"))
                        {
                                //write("Break 2\n");
                                adamage = me->query_temp("mydamage", adamage);
                                me->delete_temp("mydamage");
                                me->delete_temp("vsweaponon");
                                me->add_temp("apply/damage", -adamage);
                        }
                }

                else
                {
                        if(obj->query("vsweapon"))
                        {
                                if(!me->query_temp("vsweaponon"))
                                {
                                        //write("Break 1\n");
                                        adamage = ob->query("tiejiang/damage");
                                        me->set_temp("mydamage", adamage);
                                        me->add_temp("apply/damage", adamage);
                                        me->set_temp("vsweaponon", 1);
                                }
                        }
                }

                //write("Break 3\n");

        if( !me->is_fighting() || !me->query_temp("weapon") )
        {
                remove_call_out("start_detect");
                call_out("start_detect",1);
        }

        else
        {

                write("Current Strength is " + ob->query("tiejiang/strength") + "\n");

                if( ob->query("tiejiang/strength") < 1 )
                {
                        message_vision("ֻ��$N���е�" + ob->query("name") + "������һ���ϵ���\n", me);
                        destruct(ob);
                        return;
                }

                else
                {
                        ob->add("tiejiang/strength", -1);
                        remove_call_out("start_detect");
                        call_out("start_detect",1);
                }
        }
        return;
}
