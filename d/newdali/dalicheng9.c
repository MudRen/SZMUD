// Code of ShenZhou
// Room: /d/dali/dalicheng9.c

inherit ROOM;

void create()
{
	set("short", "���Ĺ㳡");
	set("long", @LONG
�������������ǵ����ģ���ɫʯ���̳ɵĴ�����ķ����ӡ��㳡�����Σ�
һȦΧ�Ķ���С�������ˣ��Ϳ����ֵġ�������������Ⱥ��Ҳ�ٲ��˼����ܽ���
֮�ˣ�һЩ����ԭ����δ�ŵ�������һЩ���뽭��֮���˷ܲ��ѡ�
LONG);
	set("objects", ([
		__DIR__"npc/yiren" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"dalicheng12",
		"north" : __DIR__"dalicheng2",
		"east" : __DIR__"dalicheng10",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
