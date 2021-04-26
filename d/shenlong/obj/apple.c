// Code of ShenZhou
// apple.c ƻ��
// by aln 4 / 98

inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("ƻ��", ({"ping guo", "apple", "guo"}));
        set_weight(40);
        if (clonep())
                set_default_object(__FILE__);
        else {
		set("long", "һ���ִ��ֺ��ƻ��\n");
		set("unit", "��");
                set("value", 80);
		set("food_remaining", 5);
		set("food_supply", 5);
        }
}

void init()
{
        add_action("do_yao", "yao");
        add_action("do_yao", "eat");
        add_action("do_yao", "chi");
}

int do_yao(string arg)
{
        if( !this_object()->id(arg) ) 
                return 0;

        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");

        if( !living(this_player()) ) 
                return 0;

        if( !query("food_remaining") )
                return notify_fail( name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");

        if( (int)this_player()->query("food") >= (int)this_player()->max_food_capacity() )
                return notify_fail("���Ѿ��Ե�̫���ˡ�\n");

        this_player()->add("food", (int)query("food_supply"));
        this_player()->receive_curing("jing", this_player()->query("con"));

        if( this_player()->query_condition("sl_poison") )
        this_player()->apply_condition("sl_poison",
                this_player()->query_condition("sl_poison") - 1);

        if( this_player()->is_fighting() ) this_player()->start_busy(2);

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
                message_vision("$N��ʣ�µ�" + name() + "�Եø�Ǭ������\n", this_player());
                if( !this_object()->finish_eat() )
                        destruct(this_object());
        } else 
                message_vision("$N����" + name() + "ҧ�˼��ڡ�\n", this_player());

        this_player()->start_busy(1);
        return 1;
}

