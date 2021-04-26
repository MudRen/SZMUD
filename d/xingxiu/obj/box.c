#include <ansi.h>

inherit ITEM;

void create()
{
    set_name( HIB"礼品盒"NOR, ({ "box", "lipin he", "he" }) );
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long", "一只礼品盒。\n");
		set("unit", "只" );
	}
	setup();
}

void init()
{
    add_action( "open", "open" );
    add_action( "qing", "qing" );
    add_action( "sender", "sender" );
}

int sender( string arg )
{
    set( "sender", this_player() );
    return 1;
}

int open( string arg )
{
    object me = this_player(), lace, sender;
    if ( arg != "box" )
        return notify_fail( "你要打开什么？\n" );
    lace = new( "/d/xingxiu/obj/nlace" );
    lace->move( me );
    sender = query( "sender" );
    if ( sender )
    {
        tell_object( me, "你打开礼品盒，发现了一条项链，好像是"+sender->query("name")+"送你的。你可以选择自己戴上，当然请心上帮你戴上更好了。\n" );

        lace->add_action( "qing", "qing" );
    }
    else
        tell_object( me, "你打开礼品盒，发现了一条项链。你可以选择自己戴上，当然请心上帮你戴上更好了。\n" );
    destruct( this_object() );
    return 1;
}


