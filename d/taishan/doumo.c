// Code of ShenZhou
// Room: /d/taishan/.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "��ĸ��");
	set("long", @LONG
����һ��ɽ·������һ�㶼����������Ϊ��Ϣ������ĵ����Ѿ���̩ɽ�ڽ�
������ɽΪ�ߣ��������������߱��Ǿ�ʯ����
LONG
	);

	set("exits", ([
		"eastup" : __DIR__"shijin",
		"southdown" : __DIR__"yitian",
	]));

	set("objects",([
		__DIR__"npc/jian-ke" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 4);
	setup();
	replace_program(ROOM);
}

