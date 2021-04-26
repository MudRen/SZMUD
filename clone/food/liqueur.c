// Code of ShenZhou
// liqueur.c

inherit ITEM;

void init();

void create()
{
	set_name("��",({"liqueur", "jiu"}));
	set_weight(200);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ɫ�ĳ¾ƣ�������֬������Ϯ�ˡ�\n");
		set("unit", "��");
		set("value", 300);
	set("remaining", 2);
	set("drink_supply", 50);
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

	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
	this_player()->add("water", (int)query("drink_supply"));
	this_player()->apply_condition("drunk", 5 + (int)this_player()->query_condition("drunk") );

	if( this_player()->is_fighting() )
		this_player()->start_busy(2);

	add("remaining", -1);
	if ( query("remaining") )
	{
		 message_vision("$N����Ʊ����˿ھƣ���������˱ǣ����Ǵ�����\n", this_player());
	} else 
	{ 
		 message_vision("$N����Ʊ�����ʣ�µľ�һ��������\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
