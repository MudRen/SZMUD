// Code of ShenZhou
// Room: /city/bingyindamen.c
// YZC 1995/12/04 

inherit ROOM;

void create()
{
	set("short", "��Ӫ����");
	set("long", @LONG
����վ�ڱ�Ӫ���ſڣ������һ�ż�ª��Ӫ�������Կ��������Ʒ��Ĺٱ���
�ڲ�������ʱ�ش����ź������ϰ����ǲ������ڴ˹ۿ��ģ�����øϿ��߿���
LONG
	);

	set("exits", ([
		"north" : __DIR__"bingyin",
		"south" : __DIR__"xidajie2",
	]));

	set("objects", ([
		__DIR__"npc/bing" : 4,
	]));

	set("cost", 1);
	setup();
}

int valid_leave(object me, string dir)
{
	if (!wizardp(me) && objectp(present("guan bing", environment(me))) && 
		dir == "north")
		return notify_fail("�ٱ���ס�����ȥ·��\n");
	return ::valid_leave(me, dir);
}

