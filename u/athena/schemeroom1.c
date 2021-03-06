// Code of ShenZhou
#include <ansi.h>  
inherit ROOM;

void create()
{
        set("short",HIC "瀑布" NOR);
        set("long",
"你的眼前突然为之一亮，只见一条象被一刀劈开的峡谷岩石间，高山的雪水
泻落到千丈以下的山涧里去，溅起的密密的飞沫激起一种惊心动魄的震憾。在一
块巨大的石头上可以模糊的看到：要想从此修炼圣地出去请（scheme stop，leave）。\n" 
);

	set("item_desc",([
                "stone" : "石头上刻着：“要想从此修炼圣地出去请scheme stop，leave”\n"
	]));

	set("valid_startroom",1);
	set("canScheme", 1);
	set("cost", 0);
	setup();
}

void reset()//make this room no refresh
{
	::reset();
	set("no_clean_up", 1);
}
void init()
{
	object ob = this_player();

	if (!wizardp(ob)) 
        {
                add_action("do_look","look");
		add_action("block_cmd","",1);
		add_action("leave", "leave" );
	}
}

int do_look(string arg) 
{
    if (!arg) return 0;
        else printf("不要东张西望。\n");  
     return 1;  
} 

int block_cmd()
{
	string cmd;
	object me = this_player();
	cmd = query_verb();
	if ( cmd == "quit" || cmd == "scheme" || cmd == "leave" || cmd == "chat"
	    || cmd == "l" || cmd == "look" || cmd == "cha" || cmd == "hp" ||
	    cmd == "jifa" )
	    return 0;
	
	if ( me->query( "scheming" ) )
	{
            if (  cmd == "dazuo" || cmd == "tuna" || cmd == "lian" || cmd == "du" || cmd == "yun" )
		    return 0;
    }
    write( "好好修练吧.\n" );
	return 1;
}

int leave( string arg )
{
    object me = this_player();
    if ( me->query( "scheming" ) )
        return notify_fail( "你先停止修练吧.\n" );
    me->delete( "scheming" );
    me->move( "/d/city/kedian" );
    return 1;
}
