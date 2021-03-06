// Code of ShenZhou
#include <ansi.h> 
inherit ROOM;

void create()
{
        set("short",YEL "山洞" NOR);
        set("long",
"就在这深山野谷的溪流边，却长满了各种各样的花草树木，春天繁花开遍峡
谷秋天果实压满山腰，人迹罕至，是修炼的最佳地方。你很模糊的看到前面的
一棵树干（shugan）上写着几个字。\n" 
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
		add_action("block_cmd","",1);
		add_action("leave", "leave" );
	}
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
