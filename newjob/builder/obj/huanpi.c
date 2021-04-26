// Coded by jiuer
// huanpi.c
// 听说它的毛可制笔，毛皮可制裘

#include <ansi.h>
#include <armor.h>

inherit CLOTH;

void create()
{
    set_name(YEL"獾皮"NOR, ({ "huan pi", "pi" }) );
    set_weight(5000);
    if( clonep() )
            set_default_object(__FILE__);
    else 
    {
        set("unit", "块");
        set("material", "fur");
        set("value", 2000);
        set("armor_prop/armor", 1);
        set("mao", 1 );
    }
    setup();
}

void init()
{
    add_action( "do_ba", "ba" );
}

int do_ba( string arg )
{
    object bi, me = this_player();
	if( !arg || arg != "mao" )
		return notify_fail("你要干什么\n");
	if( this_object()->query( "mao" ))
	{
    	message_vision("$N小心翼翼地把獾毛一根根拔下来。\n",me);
        message_vision("然后仔细地把毛套进笔管，不一会儿做好一只上乘的毛笔。\n", me);
        bi = new ( __DIR__"huanbi" );
        bi->move( this_player() );
    	destruct( this_object() );
       
    	return 1;
	}
	destruct( this_object() );
	return 1;
}
