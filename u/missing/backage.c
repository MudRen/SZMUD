//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "还童丹" NOR, ({"back agedan", "agedan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 100000);
                set("backage", 0);
                set("long","这是一颗神奇的" + query("name") + "，服后可以让你返老还童！\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        message_vision("$N服下一颗" + query("name") + "，忽然年轻了好多。\n", ob);
        this_player()->add("mud_age", -(this_object()->query("backage")));
        destruct(this_object());
        return 1;
}


