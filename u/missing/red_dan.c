//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "红色丹药" NOR, ({"hongse danyao", "red drug", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 10000);
                set("jiangli_exp", 20);
                set("jiangli_pot", 100);
                set("jiangli_shen", 4);
                set("long","这是一颗普通的" + query("name") + "，服后可以一天多不挨饿。\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        ob->apply_condition("full_food", 72);
        message_vision("$N服下一颗" + query("name") + "，忽然觉得丝毫没有饿意。\n", ob);
        destruct(this_object());
        return 1;
}

