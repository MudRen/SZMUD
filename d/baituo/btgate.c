// Code of ShenZhou
// room: /d/baituo/btgate
// Jay 3/27/96
// maco 2/17/2000
#include <ansi.h>
inherit ROOM;

void create()
{
	set("short", HIW"����ɽɽ��"NOR);
	set("long",
"���Ǿ��Ǵ�˵�����صġ�"+HIW"����ɽׯ"NOR+"����ԶԶ��ȥ������
��ɳ�ѻ��γɵ�ɽ�����һֻ���յļ�����һ��ɽ�����������ǰ��ɽ�ź�
һ�����ͨ��һ��ɽ���ϵ�ɽׯ�������ǡ�������ŷ����İ���ɽׯ������
һ��С·����ͨ��������\n"
	);
	set("exits", ([ 
		"east" : __DIR__"xiaolu",
		"south" : __DIR__"tuopeng",
		"northwest" : "/d/baituo/road3",
		"westup" : __DIR__"btyard",
		]));
	
	set("objects", ([ 
                        CLASS_D("baituo")+"/yin" : 1,
		"/d/baituo/npc/jiading" : 2,
		]) );
	
	set("outdoors","baituo");
	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (dir =="westup" && me->query("family/family_name")!="����ɽ" ) 
	{
		if (objectp(present("jiading", environment(me))))
			return notify_fail("�Ҷ���ס�����ȥ·����ү���������������������\n");
	}      
	return ::valid_leave(me, dir);
}

