//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(RED "���ҵ�" NOR, ({"faint dan", "dan"}));
        set_weight(20);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 10000);
                set("long","����һ�������" + query("name") + "������������˻��Ҳ�����\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        ob->apply_condition("faint_dan", ob->query("faint_time"));
        message_vision("$N����һ��" + query("name") + "�����Կ�ʼ�е㲻���ѡ�\n", ob);
        destruct(this_object());
        return 1;
}
