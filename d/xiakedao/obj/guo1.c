//Cracked by Roath
//fixed by sage 5/08/2001
// guo1.c Ұ��
// ssy
#include <ansi.h>

inherit ITEM;

int do_eat(string);

void create()
{
        set_name(RED "Ұ��" NOR, ({"ye guo", "guo"}));
        set_weight(90);
        if (clonep())
                set_default_object(__FILE__);
        else {
                set("unit", "ö");
                set("long", "����һö�����޵�Ұ����\n");
                set("value", 20000);
        }
        setup();
}

void init()
{
	set("no_get","�ⶫ�����������! \n");
	set("no_drop","��ô�����Ұ������������! \n");
	add_action("do_eat", "eat");
}

int do_eat(string arg)
{	object it = this_object(), me = this_player();
	
	if( !arg )
                return notify_fail("��ʲô��\n");
        if ( arg != "guo" )
                return notify_fail("ʲ�᣿\n");

	if( me->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( (int)me->query("food") 
	    >= (int)me->max_food_capacity() )
	  {
	    message("vision","���Ѿ��Ա��ˡ�\n", me);
	    return 1;
	  }
	  if ((int)me->query("combat_exp") > 250)

        return notify_fail("���͵��Ķ����ǲ������Եġ�\n");

	me->add("food", 50);
        me->add("water", 50);

	me->set("jing", (int)me->query("max_jing"));
        me->set("jingli", (int)me->query("max_jingli"));


	message_vision(RED "$N����һöҰ������ʱ���þ�����ʢ���������³����˾�����\n" NOR, me);
	destruct(it);
	return 1;
}
