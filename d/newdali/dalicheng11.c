// Code of ShenZhou
// Room: /d/dali/dalicheng11.c

inherit ROOM;

void create()
{
	set("short", "̫�;Ӷ�¥");
	set("long", @LONG
������̫�;ӵĶ�¥��¥�ݱ�������Щ�ֳ��ư壬���ٵĸ�Ů������������
����߳Ժ����֣�Ҳ������ī���ڴ�������̸�������洰�����������Կ�������
�廪¥ǰ��һ����ˮ��
LONG);
	set("objects", ([ 
		__DIR__"npc/song" : 1,
		__DIR__"npc/genu" : 3,       
		]));
	set("exits", ([
		"down" : __DIR__"dalicheng10",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("no_sleep_room",1);
	setup();
	replace_program(ROOM);
}
