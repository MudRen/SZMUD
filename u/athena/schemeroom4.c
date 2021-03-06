// Code of ShenZhou
#include <ansi.h>  
inherit ROOM;

void create()
{
        set("short",CYN "小木屋" NOR);
        set("long",
"在这间小木屋外，两旁是一片茂密的柳树林，头上小喜鹊唧唧喳喳的叫个不
停。一阵微风吹过，使你感觉到一股潮湿的空气扑面而来，让你觉得身心清爽。
你很模糊的看到前面的一棵树干上写着几个字：要想从此修炼圣地出去请（scheme stop,leave）。\n" 
);

              set("item_desc",([ 
                      "shugan" : "树干上刻着：“要想从次修炼圣地出去请scheme stop，leave”\n" 
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
