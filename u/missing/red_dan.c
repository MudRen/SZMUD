//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "��ɫ��ҩ" NOR, ({"hongse danyao", "red drug", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("jiangli_exp", 20);
                set("jiangli_pot", 100);
                set("jiangli_shen", 4);
                set("long","����һ����ͨ��" + query("name") + "���������һ��಻������\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        ob->apply_condition("full_food", 72);
        message_vision("$N����һ��" + query("name") + "����Ȼ����˿��û�ж��⡣\n", ob);
        destruct(this_object());
        return 1;
}

