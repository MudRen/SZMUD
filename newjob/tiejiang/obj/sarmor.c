// sarmor.c
// Code by Scatter
// V. 1.0
// 3/30/2002


#include <ansi.h>
#include <armor.h>

inherit CLOTH;


void create()
{
        object me = this_player();
        set_name(me->query("tiejiang/wname"), ({ me->query("tiejiang/wnamee"), "armor"}));
        set_weight(me->query("tiejiang/weight"));

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                                set("long", "BETA TEST ITEM\n");
                set("material", "iron");
                set("value", 1000);
                set("armor_prop/armor", 30);
        }
        setup();
}

void init() 
{
                set("vsarmor", 1);
                write("Mark Armor\n");
                call_out("start_detect",1);
}


void start_detect()
{
        object me=this_player();
        object ob=this_object();
        object obj=me->query_temp("armor");
                int obstr, adamage;

                if (!obj)
                {
                        if(me->query_temp("vsarmoron"))
                        {
                                //write("Break 2\n");
                                adamage = me->query_temp("myarmor");
                                me->delete_temp("myarmor");
                                me->delete_temp("vsarmoron");
                                me->add_temp("apply/armor", -adamage);
                        }
                }

                else
                {
                        if(obj->query("vsarmor"))
                        {
                                if(!me->query_temp("vsarmoron"))
                                {
                                        //write("Break 1\n");
                                        adamage = ob->query("tiejiang/damage");
                                        me->set_temp("mydamage", adamage);
                                        me->add_temp("apply/armor", adamage);
                                        me->set_temp("vsarmoron", 1);
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
                        message_vision("ֻ��$N���ϵ�" + ob->query("name") + "�ѿ���\n", me);
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

