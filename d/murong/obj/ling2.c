// Code of ShenZhou
// d/murong/obj/ling2.c

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(MAG"����"NOR, ({"hong ling", "ling" }));
        set_weight(180);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "����̫���ز��İ���,���ܽ�����ܳ伢��\n");
                set("unit", "ֻ");
                set("value", 120);
                set("remaining", 3);
                set("drink_supply", 20);
                set("food_supply", 20);
        }
}

void init()
{
        add_action("do_drink", "drink");
}

int do_drink(string arg)
{
        if (arg!="hong ling" && arg!="ling") return 0;
        if (this_player()->is_busy())
                return notify_fail("����һ��������û����ɡ�\n");

        if ((int)this_player()->query("water")
                >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ��ȵ�̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
        if ((int)this_player()->query("food")
                >= (int)this_player()->max_food_capacity() )
                return notify_fail("���Ѿ��Ե�̫���ˣ���Ҳ�Ų����κζ����ˡ�\n");

        set("value", 0);
        this_player()->add("water", (int)query("drink_supply"));
        this_player()->add("food", (int)query("food_supply"));

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        add("remaining", -1);
        if (query("remaining")) {
                message_vision("$N����ֻ����,��ڴ�ڳ���������\n",this_player());
        }
        else {
                message_vision("$Nһ�ھͽ�ʣ�µİ������¶ǡ�\n",this_player());
                destruct(this_object());
        }
        return 1;
}
