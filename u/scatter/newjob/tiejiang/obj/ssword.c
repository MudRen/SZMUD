                  // Code by Scatter
// 12/30/2001
// V 1.0
// s_sword.c

#include <ansi.h>
#include <weapon.h>
inherit SWORD;
void create()
{
        object me = this_player();

        set_name(me->query("tiejiang/wname"), ({ me->query("tiejiang/wnamee"), "jian", "sword" }));
        set_weight(me->query("tiejiang/weight"));
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("long", "����һ�������Ƴɵĸֽ������ֽ��ڽ���֮��ǳ����С�\n");
                set("value", 300);
                set("material", "steel");
                set("wtype", "ssword");
                                set("rigidity", me->query("tiejiang/strength"));
                set("wield_msg", "$N��ৡ���һ�����һ��$n�������С�\n");
                set("unwield_msg", "$N�����е�$n��ؽ��ʡ�\n");
        }
        init_sword(me->query("tiejiang/damage"));
        setup();
}

void init() 
{
        call_out("start_detect",1);
}

void start_detect()
{
        object me=this_player();
        object ob=this_object();
        int obstr;

        if( !me->is_fighting() || !me->query_temp("weapon") )
        {
                remove_call_out("start_detect");
                call_out("start_detect",1);
        }

        else
        {

                write("Current Strength is " + ob->query("tiejiang/strength") + "\n");
                write(me->query_temp("weapon"));

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


//      me->set("tiejiang/weight", intWei);
//      me->set("tiejiang/sharp", intSharp);
//      me->set("tiejiang/strength", intStr);
//      me->set("tiejiang/damage", intdamage);
//      me->set("tiejiang/adamage", intdam);
