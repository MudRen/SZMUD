// Code of ShenZhou

inherit ITEM;

void init();
void do_eat(string);

void create()
{
	set_name("��",({"nang"}));
	set_weight(1500);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һֻ������С���Σ��ǳ�;���бر��ĸ�����\n");
		set("unit", "ֻ");
		set("value", 80);
        set("remaining", 9);
	set("food_supply", 20);
    }
	
	setup();
}

void init()
{
	add_action("do_eat", "eat");
}


int do_eat(string arg)
{

    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("food")
       >= (int)this_player()->max_food_capacity() )
     return notify_fail("���Ѿ��Ե�̫���ˡ�\n");

	set("value", 0);
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N�����γ��˼��ڡ�\n", this_player());
	} else 
	{ 
   		 message_vision("$N��ʣ�µ��γԵøɸɾ�����\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
