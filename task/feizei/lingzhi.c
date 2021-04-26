// lingzhi.c 千年灵芝
//星星(lywin)2000/4/22

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
        set_name(CYN"千年灵芝"NOR, ({"ling zhi", "zhi", "lingzhi"}));
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("unit", "棵");
		set("value", 0);
                set("long", "这是一棵武林人士梦寐以求的千年灵芝，其作用妙不可言。\n"); 
	}
	setup();
}

int do_eat(string arg)
{
    string benificial;
	if (!id(arg))
	    return notify_fail("你要吃什么？\n");
    benificial = this_object()->query( "benificial" );
	if ( !stringp( benificial ) || benificial != this_player()->query( "id" ) )
	{
	    message_vision( "$N吃下一棵千年灵芝。", this_player());
        destruct(this_object());
	    return 1;     
	}	
              this_player()->add("combat_exp", 1000+random(500)); 
        this_player()->add("potential",150+random(100));
        this_player()->add("max_neili",random(3));
        this_player()->add("eff_jingli",random(3));
message_vision("$N细细地服下一枚千年灵芝，顿时感到自己功力大进！\n", this_player());  
log_file("job/feizei", sprintf("%s(%s)于%s吃下(%s)复制的一枚灵芝(%O)。\n", 
                      this_player()->query("name"), getuid(this_player()), ctime(time()), 
                              this_object()->query("cloner"), this_object())); 
destruct(this_object()); 
	return 1;
}


