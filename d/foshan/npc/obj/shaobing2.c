// Code of ShenZhou
// Jay 5/3/97

inherit ITEM;
inherit F_FOOD;

void create()
{
        set_name("�ձ�", ({"shaobing", "cake"}));
        set_weight(100);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("long", "һ��������Ĵ��ձ��������дл���������֥�顣\n");
                set("unit", "��");
                set("value", 70);
                set("food_remaining", 3);
                set("food_supply", 30);
		set("no_steal", 1);
		set("no_steall", 1);
        }
}

void init()
{
        add_action("do_eat", "chi");
        add_action("do_eat", "eat");
}

int do_eat(string arg)
{
	object ling;
	object me = this_player();

	if (!id(arg))
                return notify_fail("��Ҫ��ʲô��\n");

	if( me->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
        if( !living(me) ) return 0;

        if( !query("food_remaining") )
                return notify_fail( name() + "�Ѿ�ûʲô�óԵ��ˡ�\n");
        if( (int)me->query("food") >= (int)me->max_food_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�������κζ����ˡ�\n");

        me->add("food", query("food_supply"));
        me->add("jingli", query("food_supply")/5);
        if( me->query("jingli") > me->query("max_jingli")) 
        me->set("jingli", me->query("max_jingli"));

        if( me->is_fighting() ) me->start_busy(2);

        // This allows customization of drinking effect.
        if( query("eat_func") ) return 1;

        set("value", 0);
        add("food_remaining", -1);
        if( !query("food_remaining") ) {
                tell_object(me,"ͻȻ����һ�������㿩��һ������ԭ���ձ�����һ����Ƭ��\n");
                ling = new(__DIR__"xtling");
                ling->move(me);
                message_vision("$N��ʣ�µ�" + name() + "�Եø�Ǭ������\n", me);

                if( !this_object()->finish_eat() ) {
                        destruct(this_object());
                }


        } else 
                message_vision("$N����" + name() + "ҧ�˼��ڡ�\n", me);

        me->start_busy(1);
        return 1;
}


