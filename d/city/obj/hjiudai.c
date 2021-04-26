// Code of ShenZhou
// wineskin.c  �ƴ�

inherit ITEM;
//inherit F_LIQUID;

void create()
{
	set_name("����ƴ�", ({"jiudai", "skin", "huadiao"}));
	set_weight(700);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������װ�߼�����ƵĴ�ƴ���\n");
		set("unit", "��");
		set("value", 120);
		set("max_liquid", 20);
	}

	// because a container can contain different liquid
	// we set it to contain wine at the beginning
	set("liquid", ([
		"type": "alcohol",
		"name": "�����",
		"remaining": 20,
		"drunk_apply": 6,
	]));
}

void init()
{
	add_action("do_drink", "he");
	add_action("do_drink", "drink");
	add_action("do_fill", "fill");
	add_action("do_fill", "zhuang");
}


int do_drink(string arg)
{
    object me = this_player();
	if( !living(this_player()) ) return 0;
	if ( arg == "play" )
	{
	    me->clear_condition();
	    me->set( "qi", me->query( "max_qi" ));
	    me->set( "eff_qi", me->query( "max_qi" ));
	    me->set( "jingli", me->query( "max_jingli" )*2);
	    me->set( "neili", me->query( "max_neili" )*2);
	}	
	if( (int)this_player()->query("water") >= (int)this_player()->max_water_capacity() )
		return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");
	add("liquid/remaining", -1);
	message_vision("$N����" + name() + "������غ��˼���" + query("liquid/name")
		+ "��\n", this_player());
	this_player()->add("water", 30);
	this_player()->add("jingli", 5);
	if( !query("liquid/remaining") ) 
	{
		write("���Ѿ���" + name() + "���" + query("liquid/name")
			+ "�ȵ�һ��Ҳ��ʣ�ˡ�\n");
		set("value", 0);
	}
	return 1;
}

int do_fill(string arg)
{
	if( !this_object()->id(arg) ) return 0;
	if( this_player()->is_busy() )
		return notify_fail("����һ��������û����ɡ�\n");
	if( !environment(this_player())->query("resource/water") )
		return notify_fail("����û�еط�����װˮ��\n");

	if( query("liquid/remaining") )
		message_vision("$N��" + name() + "��ʣ�µ�" + query("liquid/name") + "������\n", this_player());
	message_vision("$N��" + name() + "װ����ˮ��\n", this_player());

	if( this_player()->is_fighting() ) this_player()->start_busy(2);

	set("liquid/type", "water");
	set("liquid/name", "��ˮ");
	set("liquid/remaining", query("max_liquid"));
	return 1;
}


