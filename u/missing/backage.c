//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL "��ͯ��" NOR, ({"back agedan", "agedan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 100000);
                set("backage", 0);
                set("long","����һ�������" + query("name") + "������������㷵�ϻ�ͯ��\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        message_vision("$N����һ��" + query("name") + "����Ȼ�����˺öࡣ\n", ob);
        this_player()->add("mud_age", -(this_object()->query("backage")));
        destruct(this_object());
        return 1;
}


