// Code of ShenZhou
// �̲�

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("�̲�",({"tea", "cha", "nai cha"}));
	set_weight(100);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "һ������ŨŨ���̲裬����Ư�ŻƲӲӵ����ͻ���\n");
		set("unit", "��");
		set("value", 300);
	set("remaining", 3);
	set("drink_supply", 60);
	set("food_supply", 20);
    }
	
	setup();
}

void init()
{
	add_action("do_drink", "drink");
}


int do_drink(string arg)
{
	int heal, jing, e_jing, m_jing;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
	return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    this_player()->add("food", (int)query("food_supply"));

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
		 message_vision("$N������룬���๾��غ��˼����̲衣\n", this_player());
	} else 
	{ 
		 message_vision("$N������룬��ʣ�µ��̲�һ��������˫������һ����ڡ�\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}
