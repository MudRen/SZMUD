//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;
void to_full(object ob);

string *eat_msg = ({
        RED"原来是巧克力馅的，浓浓甜甜的味道在你的嘴里充溢。",
        YEL"是甜滋滋蜜滋滋的很特别，似是加了上等的蜂蜜。"NOR,
        WHT"酸酸的带一丝甜很可口，原来这个是天山特产白玉梨做馅。"NOR,
        MAG"极浓郁的芝麻香气扑鼻而来，原来这个是精选东北的黑芝麻做馅。"NOR,
        HIW"一丝涩涩香香的味道透入你的口中，原来这个是由产自海南的椰茸做馅。"NOR,
        CYN"一股奇香跃上舌头这味道似香似甜恰浓又淡，吃在嘴里说不出的舒畅，\n这是由莲子、花生、核桃、木蔓籽、无花果制成的馅。"NOR,
        });

void create()
{
        set_name(WHT "翡玉汤圆" NOR, ({"tang yuan"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "碗");
                set("value", 270);
                set("left", 6);
                set("long","这是一碗雪白的圆滚滚的热汤圆，香味扑鼻。在薄厚适中的面下面隐隐透出深色的馅，让人垂涎欲滴。\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        if (query("left") == 0) return 0;
        if (this_player()->query("food") > this_player()->max_food_capacity())
                return notify_fail("你吃的太饱了，实在是吃不下更多的东西了。\n");
        message_vision("$N吃了一个汤圆，热呼呼的馅流进了$N的嘴里。\n", this_player());
        tell_object(this_player(), eat_msg[random(sizeof(eat_msg))] + "\n");
        add("left", -1);
        this_player()->add("food", 30 + random(7));
        set("value", query("value") < 90 ? 90 : query("value"));
        if(query("left") == 0) {
                message_vision("$N吃下最后一个汤圆，还不解馋，连碗里的汤也全部喝光了。\n", this_player());
                set_name(WHT"瓷碗"NOR, ({"ci wan", "wan"}));
                set_weight(12);
                set("unit", "个");
                set("long", "一个普通的白花瓷碗，没有什么用。\n");
                set("medicine", 0);
                call_out("to_full", 4 + random(3), this_player());
                destruct( this_object() );
        }
        return 1;
}

void to_full(object ob)
{
        tell_object(ob, WHT"经过半天消化，你只觉得有肚子已是十分饱了。\n"NOR);
        ob->apply_condition("full_food", 10);
        ob->apply_condition("full_water", 10);
        destruct(this_object());
}

