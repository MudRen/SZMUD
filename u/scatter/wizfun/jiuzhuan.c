// Code of ShenZhou
// jiuzhuan-huanhundan.c 九转还魂丹 (fake)

#include <ansi.h>

inherit ITEM;

void setup()
{}

void init()
{
        add_action("do_eat", "eat");       
}

void create()
{
        set_name("九转还魂丹", ({"jiuzhuan dan", "jiuzhuan", "dan"}));
        set_weight(10);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "颗");
                set("long", "这是一颗金光闪闪的九转还魂丹，功能起生回死，妙用无穷。\n");
                set("value", 0);
        }
        set_color(HIY);
        set("qfy",1);

        setup();
}

int do_eat(string arg)
{
        object me=this_player();

        if (!id(arg))
        return notify_fail("你要吃什么？\n");

        message_vision(HIG "$N吃下一颗九转还魂丹，发现魂魄一丝丝的离开身体，武功尽失！\n" NOR, me);
                write(HIY"愚人节快乐\n愚人节快乐\n愚人节快乐\n愚人节快乐\n");
        return 1;
}

