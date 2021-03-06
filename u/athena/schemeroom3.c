// Code of ShenZhou
#include <ansi.h>  
inherit ROOM;

void create()
{
        set("short",MAG "山峦" NOR);
        set("long",
"这里因终年覆盖白雪，一片百茫茫的景色，寒风呼啸，凛冽刺骨，你不禁打
了个寒颤。不为是一个锻炼人的好地方。在不远处一快被雪覆盖的石块上面
写了几个字：要想从此修炼圣地出去请（scheme stop,leave）。\n" 
);

              set("item_desc",([ 
                      "stone" : "你把雪扫开，看到石头上刻着：“要想从次修炼圣地出去请scheme stop，leave”\n" 
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
