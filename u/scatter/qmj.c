#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
        object me = this_player();
        set_name(HIB"��ڤ��"NOR, ({ "qingming jian", "qingming", "jian" }) );
        set_weight(1000);
                if( clonep() )
                        set_default_object(__FILE__);
        else {
                        set("unit", "��");
                        set("long", "��ڤ�ӵı�����\n");
                        set("value", 24000);
                        set("material", "steel");
                        set("rigidity", 5000);
                        set("wield_msg",HIW"$N�ν����ʣ������ʧ���Ѿõķ�ڤ�ӵı���"+HIB"   ������   "+HIW"\n��ѱ����������࣬�����ϵȵı���Ҳ��һ���⡣\n"NOR);
                        set("unwield_msg", HIB"$N�����е�$n��������Ľ��ʡ�\n"NOR);
                        set("unequip_msg", HIB"$N�����е�$n��������Ľ��ʡ�\n"NOR);
                }

        init_sword(1000);
        setup();
//        ::create();

}

void init()
{
        add_action("do_wield", "wield");
}



int do_wield(string arg)
{
        object me = this_player();

        /*
        if (me->query("id") != "scatter")
        {
         me->set_temp("poison", 1);
         call_out("poison", 20, me);
         return 1;
        }
        */


        if (me->query("id") == "scatter")
        {
        setup();
        ::create();
        }

        else if (me->query("id") == "hopeful")
        {
        setup();
        ::create();
        }

        else
        {
         me->set_temp("poison", 1);
         call_out("poison", 20, me);
         return 1;
        }
        

//        return 1;
//        init_sword(120);
        setup();
        ::create();
}

int poison(object me)
{
        me->delete_temp("poison");
        tell_object(me, HIR"��ͻȻ�е�һ��������ԭ���ǽ��Ͼ綾�����ˣ�\n"NOR);
        message("vision", me->name()+"���¼������ģ�˫��һ�ű㲻���ˣ��ۡ������ǡ����ж�������Ѫ����\n", environment(me), ({me}) );
        me->receive_wound("qi", me->query("max_qi")+100, "�綾��������");

        return 1;
}

