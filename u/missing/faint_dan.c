//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "混乱丹" NOR, ({"faint dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("value", 10000);
                set("long","这是一颗神奇的" + query("name") + "，服后可以让人混乱不堪。\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        ob->apply_condition("faint_dan", ob->query("faint_time"));
        message_vision("$N服下一颗" + query("name") + "，大脑开始有点不清醒。\n", ob);
        destruct(this_object());
        return 1;
}
