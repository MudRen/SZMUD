// ���߸��¥
// jiuer 5/19/2002

#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", "���߸��¥");
        set("long", @LONG
�������߸��¥����ŷ�����ж��伮�ľ��ң����а������Ǽ��ӣ���
����ɾ�������վ��һ���ͣ���������ʰ���ҡ�
LONG
        );
        set("exits", ([ 
			"down" : __DIR__"lingshege",
        ]));

       // set("objects", ([ 
	//		"/d/baituo/npc/puren" : 1,
	//	]));

	set("cost", 1);        
	setup();
}

int valid_leave(object me, string dir)
{   
	if (me->query("family/family_name")!="����ɽ")
	{ 
	   if( present("guaishe", me) && dir == "down")
		   return notify_fail("�ö˶˵���������ߵ�����ȥ����\n");
	   if( present("she jing", me) && dir == "down")
		   return notify_fail("�߾����ô������ң�\n");  
	}
	return ::valid_leave(me,dir);
}


 
