#include <ansi.h>
#include <weapon.h>
inherit F_UNIQUE;
inherit SWORD;

void create()
{
        object me = this_player();
        set_name(HIB"清冥剑"NOR, ({ "qingming jian", "qingming", "jian" }) );
        set_weight(1000);
                if( clonep() )
                        set_default_object(__FILE__);
        else {
                        set("unit", "柄");
                        set("long", "分冥子的宝剑。\n");
                        set("value", 24000);
                        set("material", "steel");
                        set("rigidity", 5000);
                        set("wield_msg",HIW"$N拔剑出鞘，这就是失传已久的分冥子的宝剑"+HIB"   清明剑   "+HIW"\n这把宝剑销铁如泥，就连上等的宝剑也无一幸免。\n"NOR);
                        set("unwield_msg", HIB"$N将手中的$n插入腰间的剑鞘。\n"NOR);
                        set("unequip_msg", HIB"$N将手中的$n插入腰间的剑鞘。\n"NOR);
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
        tell_object(me, HIR"你突然感到一阵晕旋，原来是剑上剧毒发作了！\n"NOR);
        message("vision", me->name()+"脚下几个踉跄，双脚一蹬便不动了，眼、耳、鼻、口中都流出黑血来！\n", environment(me), ({me}) );
        me->receive_wound("qi", me->query("max_qi")+100, "剧毒发作死了");

        return 1;
}

