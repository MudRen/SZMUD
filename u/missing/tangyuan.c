//Pwoered By yeer@shenzhou

#include <ansi.h>

inherit ITEM;
void to_full(object ob);

string *eat_msg = ({
        RED"ԭ�����ɿ����ڵģ�ŨŨ�����ζ�������������硣",
        YEL"�������������̵ĺ��ر����Ǽ����ϵȵķ��ۡ�"NOR,
        WHT"����Ĵ�һ˿��ܿɿڣ�ԭ���������ɽ�ز����������ڡ�"NOR,
        MAG"��Ũ����֥�������˱Ƕ�����ԭ������Ǿ�ѡ�����ĺ�֥�����ڡ�"NOR,
        HIW"һ˿ɬɬ�����ζ��͸����Ŀ��У�ԭ��������ɲ��Ժ��ϵ�Ҭ�����ڡ�"NOR,
        CYN"һ������Ծ����ͷ��ζ����������ǡŨ�ֵ�����������˵�������泩��\n���������ӡ����������ҡ�ľ���ѡ��޻����Ƴɵ��ڡ�"NOR,
        });

void create()
{
        set_name(WHT "������Բ" NOR, ({"tang yuan"}));
        set_weight(30);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "��");
                set("value", 270);
                set("left", 6);
                set("long","����һ��ѩ�׵�Բ����������Բ����ζ�˱ǡ��ڱ������е�����������͸����ɫ���ڣ����˴������Ρ�\n");
                set("medicine", 1);
        }

        setup();
}

int feed_ob(object ob)
{
        if (query("left") == 0) return 0;
        if (this_player()->query("food") > this_player()->max_food_capacity())
                return notify_fail("��Ե�̫���ˣ�ʵ���ǳԲ��¸���Ķ����ˡ�\n");
        message_vision("$N����һ����Բ���Ⱥ�������������$N�����\n", this_player());
        tell_object(this_player(), eat_msg[random(sizeof(eat_msg))] + "\n");
        add("left", -1);
        this_player()->add("food", 30 + random(7));
        set("value", query("value") < 90 ? 90 : query("value"));
        if(query("left") == 0) {
                message_vision("$N�������һ����Բ��������������������Ҳȫ���ȹ��ˡ�\n", this_player());
                set_name(WHT"����"NOR, ({"ci wan", "wan"}));
                set_weight(12);
                set("unit", "��");
                set("long", "һ����ͨ�İ׻����룬û��ʲô�á�\n");
                set("medicine", 0);
                call_out("to_full", 4 + random(3), this_player());
                destruct( this_object() );
        }
        return 1;
}

void to_full(object ob)
{
        tell_object(ob, WHT"����������������ֻ�����ж�������ʮ�ֱ��ˡ�\n"NOR);
        ob->apply_condition("full_food", 10);
        ob->apply_condition("full_water", 10);
        destruct(this_object());
}

