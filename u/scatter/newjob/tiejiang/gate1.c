                          //code by cheap
//11/10/01

//Modify by Scatter
//V 1.1

#include <ansi.h>
inherit ROOM; 
void create()
{
        set("short",HIC"�����"NOR);
        set("long",
"�����ǿ󳡵���ڣ�����������ȥ������һƬ�ڰ���������ϸ������᲻ʱ\n"
"�������δ𡱡��δ𡱵ĵ�ˮ��������Ҳ���ֲ�������˵����������͹���Ϊ\n" 
"�þ���ǰ��������������ɱ,���Ժܶ��˶���Ը�ⵥ�˽�ȥ��\n " 
        ); 

        set("outdoors","city");
// ***** NPC ADDED BY SCATTER *****
        set("objects", ([
                __DIR__"npc/manage" : 1,
        ]));



        set("exits", ([ 
        "west":"/newjob/tiejiang/room.c", 
        "east":"/newjob/tiejiang/gate.c",
        "enter":"/newjob/tiejiang/kuangchang.c",
        "northdown":"/d/dali/minov54.c",
                "south" : "/d/xingxiu/silk3.c",

        ])); 
        
        setup();
//       replace_program(ROOM);
}


int valid_leave(object me, string dir)
{
        if( (!me->query_temp("kuangchang/enter")) && (dir == "enter"))
          { 
            return notify_fail("�㻹û�õ�����ͬ���ء�\n");
          }
        return ::valid_leave(me, dir);
}

