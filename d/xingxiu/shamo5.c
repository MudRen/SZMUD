// Code of ShenZhou
// Room: /d/xingxiu/shamo3.c
#include <localtime.h>
#include <ansi.h>
#include <room.h>
inherit ROOM;

void create()
{
    mixed *local;
    local = localtime(time()*60);

    set("short","大沙漠");
    set("long", @LONG
这是一片一望无际的大沙漠。你一进来就迷失了方向。
看来要走出这块沙漠并非易事。
LONG
    );
	
	set("objects", ([
                    "/d/xingxiu/obj/plant" : 1,
		]) );
    
        if( ( local[LT_MON] > 3 && local[LT_MON] < 9 )
        && ( local[LT_HOUR] > 9 && local[LT_HOUR] < 18 ) )
    {
        set("exits", ([
            "east" : __DIR__"shamo3",
            "west" : __DIR__"shamo4",
            "south" : __DIR__"shamo1",
            "north" : __DIR__"shamo2",
            "up" : "/u/mariner/path",
        ]));
		
		

        call_out( "showRainBow", 1 );
        call_out( "close_up", 15 );        
    }
    else
    {
        set("exits", ([
            "east" : __DIR__"shamo3",
            "west" : __DIR__"shamo4",
            "south" : __DIR__"shamo1",
            "north" : __DIR__"shamo2",
        ]));
    }        
    
    set("cost", 5);
    set("outdoors", "xingxiu-hai");
    setup();
}

void init()
{
    mixed *local;
    local = localtime(time()*60);
    if( ( local[LT_MON] > 3 && local[LT_MON] < 9 )
        && ( local[LT_HOUR] > 10 && local[LT_HOUR] < 17 ) )
    {
        if ( 1 )
        {
            set("exits", ([
                  "east" : __DIR__"shamo3",
                "west" : __DIR__"shamo4",
                "south" : __DIR__"shamo1",
                "north" : __DIR__"shamo2",
                "up" : "/u/mariner/path",
            ]));
            remove_call_out( "showRainBow" );
            remove_call_out( "close_up" );
            call_out( "showRainBow", 1 );
            call_out( "close_up", 15 );     
        }           
    }
}

void showRainBow()
{
    tell_room( this_object(), HIY"\n" );
    tell_room( this_object(), HIY" 白色的蒸汽正腾腾上升，凝聚在半空中，雾气映射着赤白的阳光，太阳\n" );
    tell_room( this_object(), HIY" 慢慢西移，白色的雾气中透出点点的红光，而后是点点的蓝光，突然，\n\n"NOR );
    tell_room( this_object(), HIM" ::>>☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆<<::\n\n"NOR );
    tell_room( this_object(), HIM"     一道七彩光柱拔地而起，似一道彩虹大道从你脚下伸到远方\n\n"NOR );
    tell_room( this_object(), HIM" ::>>☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆☆<<::\n"NOR );
    tell_room( this_object(), "\n\n" );
}

void close_up()
{
    tell_room( this_object(), HIW"慢慢的，彩虹消失在淡淡的薄雾里。::::::....:::::''''>>\n"NOR );
    delete( "exits/up" );
}


int valid_leave(object me, string dir)
{
    object lover;
    string loverid = me->query( "spouse/id" );
    if ( dir == "up" )
    {   
        if ( !stringp( loverid ) )
        {
            if ( me->query( "gender" ) == "女性" )
                lover = me->query_temp( "marriage/accept" );
            else 
                lover = me->query_temp( "marriage/banquet" );
            if ( !lover )
            return notify_fail( "孤独一人不好去情人岛的，快去找个伴侣吧。\n" );
        }
        if ( !lover )
        lover = present( loverid, this_object() );
        if ( !lover )
            return notify_fail( "想墙外开花吗? 想上彩虹大道必须是夫妻两个。\n" );
        message_vision(HIY"$N含情脉脉地拉起$n的手，踏上彩虹路，不一会就消失在七彩虹里。\n"NOR, me, lover);
        lover->move( "/u/mariner/path" );
        lover->set_leader( me );
        //return 1;
    }
    return ::valid_leave( me, dir );
}
