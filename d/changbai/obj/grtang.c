// Code of ShenZhou
// grtang

inherit ITEM;

void init();

void create()
{
	set_name("������",({"gourou tang", "tang"}));
	set_weight(50);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ���������ڵĹ����������滹Ư�ż�Ƭ�л���\n");
		set("unit", "��");
		set("value", 150);
                set("remaining", 5);
                set("drink_supply", 30);
                set("food_supply", 10);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{	
	
        if( !this_object()->id(arg) ) return 0;
        if( this_player()->is_busy() )
                return notify_fail("����һ��������û����ɡ�\n");
    if((int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
                return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	
        add("remaining", -1);
        this_player()->add("water", (int)query("drink_supply"));
/*
        this_player()->receive_heal("jing", 30);
        this_player()->receive_curing("jing", 15);
        this_player()->receive_heal("jingli", 30);
*/

	if ( query("remaining") ) {
   		 message_vision("$N������룬���˹��˵ĺ��˼�������\n", this_player());
	} else { 
   		 message_vision("$N������룬��ʣ�µ����ȵøɸɾ�����\n", this_player());
		
		 destruct(this_object());
	}

	return 1;
}


