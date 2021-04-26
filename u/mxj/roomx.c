// Room Of Mxj
// have a good day
// Code of ShenZhou
inherit ROOM;
#include <ansi.h>  
void create()
{
        set("short","修练室");
        set("long","这里是一些江湖侠客自建的修炼室，专门提供给同道中人修炼。
    摆设极其简单，两边有一些桌椅，一些人正在打坐吐纳。偶尔有人进出也是
    小心翼翼，门口写了一个告示。你可以参考"HIG"help guaji"NOR" ,"HIG"help scheme"NOR" 和
    "HIG"help trigger"NOR"来使用离线机器人。\n");
        
        
        
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
