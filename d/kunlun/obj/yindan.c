inherit ITEM;
#include <ansi.h>
void init()
{
        add_action("do_eat", "eat");
}
void create()
{
        set_name("银冠蛇胆", ({"yin dan", "dan"}));
        set("unit", "颗");
        set("long", "这是一颗红冬冬的银冠蛇胆。\n");
        set("value", 100);
        setup();
}
int do_eat(string arg)
{
    if (!id(arg))
    return notify_fail("你要吃什么？\n");
            this_player()->set("jing", this_player()->query("max_jing"));
          this_player()->set("qi", this_player()->query("max_qi"));
        message_vision(HIG"$N服下一颗银冠蛇胆,顿觉全身上下都充满了活力!\n"NOR, this_player());
    destruct(this_object());
    return 1;
}
