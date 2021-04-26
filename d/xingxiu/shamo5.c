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

    set("short","��ɳĮ");
    set("long", @LONG
����һƬһ���޼ʵĴ�ɳĮ����һ��������ʧ�˷���
����Ҫ�߳����ɳĮ�������¡�
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
    tell_room( this_object(), HIY" ��ɫ�����������������������ڰ���У�����ӳ���ų�׵����⣬̫��\n" );
    tell_room( this_object(), HIY" �������ƣ���ɫ��������͸�����ĺ�⣬�����ǵ������⣬ͻȻ��\n\n"NOR );
    tell_room( this_object(), HIM" ::>>����������������������������<<::\n\n"NOR );
    tell_room( this_object(), HIM"     һ���߲ʹ����εض�����һ���ʺ�����������쵽Զ��\n\n"NOR );
    tell_room( this_object(), HIM" ::>>����������������������������<<::\n"NOR );
    tell_room( this_object(), "\n\n" );
}

void close_up()
{
    tell_room( this_object(), HIW"�����ģ��ʺ���ʧ�ڵ����ı����::::::....:::::''''>>\n"NOR );
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
            if ( me->query( "gender" ) == "Ů��" )
                lover = me->query_temp( "marriage/accept" );
            else 
                lover = me->query_temp( "marriage/banquet" );
            if ( !lover )
            return notify_fail( "�¶�һ�˲���ȥ���˵��ģ���ȥ�Ҹ����°ɡ�\n" );
        }
        if ( !lover )
        lover = present( loverid, this_object() );
        if ( !lover )
            return notify_fail( "��ǽ�⿪����? ���ϲʺ��������Ƿ���������\n" );
        message_vision(HIY"$N��������������$n���֣�̤�ϲʺ�·����һ�����ʧ���߲ʺ��\n"NOR, me, lover);
        lover->move( "/u/mariner/path" );
        lover->set_leader( me );
        //return 1;
    }
    return ::valid_leave( me, dir );
}
