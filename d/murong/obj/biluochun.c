// Code of ShenZhou
// biluochun.c ���

inherit ITEM;

void init();
void do_eat();

void create()
{
	set_name("���ݴ�",({"biluochun", "tea", "cha"}));
	set_weight(80);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "����һ����ɫ���̡���ζŨ���ϵȺò衣�����˳�����ɷ���㡣\n");
		set("unit", "��");
		set("value", 1000);
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

	int heal, recover, jing, e_jing, m_jing;
	
	recover = 5;
	
    if( !this_object()->id(arg) ) return 0;
    if( this_player()->is_busy() )
        return notify_fail("����һ��������û����ɡ�\n");
    if(   (int)this_player()->query("water")
       >= (int)this_player()->max_water_capacity() )
     return notify_fail("���Ѿ���̫���ˣ���Ҳ�಻��һ��ˮ�ˡ�\n");

	set("value", 0);
    this_player()->add("water", (int)query("drink_supply"));
    jing = (int)this_player()->query("jing");
    e_jing = (int)this_player()->query("eff_jing");
    m_jing = (int)this_player()->query("max_jing");

    if ( e_jing < m_jing )
	{ 	
		if ( (e_jing + heal) >= m_jing )
		{
			this_player()->set("eff_jing", m_jing);
		} else
		{	
			this_player()->set("eff_jing", e_jing+heal);
		}	
	} 

	if (jing < e_jing )
	{
        if ( (jing + recover) >= e_jing )
        {
            this_player()->set("jing", e_jing);
        } else
        {   
            this_player()->set("jing", jing+recover);
        }   
	}

    if( this_player()->is_fighting() ) this_player()->start_busy(2);

    add("remaining", -1);
	if ( query("remaining") )
	{
   		 message_vision("$N���𱭱��ݴ���������ζ��Ʒ�˼��ڡ�\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
	} else 
	{ 
   		 message_vision("$N�����С������ʣ�µı��ݴ�һ��������\n"+
      		"һ������ֱ����Ƣ��$N���þ���ö��ˡ�\n", this_player());
		
		destruct(this_object());
	}

	return 1;
}