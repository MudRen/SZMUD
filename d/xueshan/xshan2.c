// Code of ShenZhou
// Summer 9/25/96
#include "room.h"
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "��ѩɽ");
        set("long", @LONG
Ⱥɽ���ƣ����ܻ�ѩ���겻�����ϱ߲�Զ����һ��ɽ�ȡ�
LONG
        );
	set("exits", ([
		"eastdown" : __DIR__"xshan1",
        "northwest"  : "/u/athena/schemeroom3", 
		"southup" : __DIR__"shangu",
        ]));

	set("objects", ([
                "/d/qilian/npc/caiyaoren": 1,
        ]));



	set("cost", 4);
	set("bing_can", 2);
        setup();
        set("outdoors","qilian-shan");
}

int valid_leave(object me, string dir)
{
		object *ob;
		object *inv;
        int i;

        if( dir == "southup" && random((int)me->query_skill("dodge")) <= 10)
		{
        
			message_vision(HIW"ͻȻ��¡һ�����죬$N����̤�˸��գ�... ��...ѩ���ˣ�\n"NOR, me );
			ob = all_inventory(environment(me));

			for(i=0; i<sizeof(ob); i++)
			{
                if( !userp(ob[i]) ) continue;

				if (random(15) == 1)
				    me->move(__DIR__"shangu3");
	
				else
					ob[i]->move(__DIR__"shankou");

				ob[i]->receive_damage("qi", 100, "��ѩ��������");
				ob[i]->receive_wound("qi", 70, "��ѩ��������");
				message("vision", HIW"ֻ��" + ob[i]->query("name") + "��Ҳ�Ƶش�ɽ���ϱ����������Ǳ�һ����ѩ��ͷ��ס����������ǰ��ѩ���ˣ�\n"NOR, environment(me), me);
			}
                return notify_fail(HIW"ֻ����Ƭ�Ļ�ѩ��ɽ���ϱ��ڶ��£���������ǵص��˹�������;���д��˲�����ʯ���Ͻ������ɣ�\n"NOR);
		}

	    inv = all_inventory(me); 
        if ( dir == "northwest")
		{  
			// can not got to any where if they take players 
            for (i=0; i<sizeof(inv); i++)
			{  
				if (inv[i]->is_character())  
                return notify_fail("�㱳�Ÿ��˻����ȥ��û�ţ�\n"); 
			}
		}

		return ::valid_leave(me, dir);
}

