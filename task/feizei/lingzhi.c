// lingzhi.c ǧ����֥
//����(lywin)2000/4/22

#include <ansi.h>
inherit ITEM;

void setup()
{}

void init()
{
	add_action("do_eat", "eat");
}

void create()
{
        set_name(CYN"ǧ����֥"NOR, ({"ling zhi", "zhi", "lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "��");
		set("value", 0);
                set("long", "����һ��������ʿ���������ǧ����֥������������ԡ�\n"); 
	}
	setup();
}

int do_eat(string arg)
{
    string benificial;
	if (!id(arg))
	    return notify_fail("��Ҫ��ʲô��\n");
    benificial = this_object()->query( "benificial" );
	if ( !stringp( benificial ) || benificial != this_player()->query( "id" ) )
	{
	    message_vision( "$N����һ��ǧ����֥��", this_player());
        destruct(this_object());
	    return 1;     
	}	
              this_player()->add("combat_exp", 1000+random(500)); 
        this_player()->add("potential",150+random(100));
        this_player()->add("max_neili",random(3));
        this_player()->add("eff_jingli",random(3));
message_vision("$Nϸϸ�ط���һöǧ����֥����ʱ�е��Լ����������\n", this_player());  
log_file("job/feizei", sprintf("%s(%s)��%s����(%s)���Ƶ�һö��֥(%O)��\n", 
                      this_player()->query("name"), getuid(this_player()), ctime(time()), 
                              this_object()->query("cloner"), this_object())); 
destruct(this_object()); 
	return 1;
}


