// Code of ShenZhou
// /d/zhongnan/chanshen.c
//������
// sdong 08/04/98

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
		  set("short", HIM"������"NOR);
		  set("long", @LONG
�������������ĳ�������м��Ǹ�����Ĵ��㰸�����Ϸ��ż������š�
������������ڶ���������ڽ��㣬���������ϡ�����ͨ�����ϱ�ͨ
�������
LONG
		  );
		  set("valid_startroom", 1);

		  set("exits", ([
					 "northdown" : __DIR__"taijie",
					 "southdown" : __DIR__"taijie2",
		  ]));

		set("cost",1);

		set("objects", ([
				 CLASS_D("quanzhen") + "/liu" : 1,
			 ]));

		setup();
}

