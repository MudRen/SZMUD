// Code of ShenZhou
// Room: /d/dali/sangong1.c

inherit ROOM;

void create()
{
	set("short", "˾����");
	set("long", @LONG
����һ������ûʵĹ��ã��Ǵ����˾�հ���ʯƽ���������˾����˾��
��Ͻ����������˰�񡢵�·�����޽��ȡ���˾��Ҫ������æ���İ��ϸ߸߶�
��һ�����ġ�
LONG);
	set("objects", ([
		__DIR__"npc/ba-tianshi" : 1,
		]));
	set("exits", ([
		"east" : __DIR__"sangong",
		]));
	set("cost", 1);
	set("wangfu", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
