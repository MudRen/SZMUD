// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov28.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
����һ�ô��������������ڴ˽���һ���൱��ĸ������²�������һ��Ȧ��
ʮ��ͷţ���Աߵ�¥���޵��Ŀ����������Ǳ��ص������˼ҡ�
LONG);
	set("objects", ([
		__DIR__"npc/goat.c" : 3,
		__DIR__"npc/niu.c" : 2,
		]));
	set("exits", ([
		"west" : __DIR__"minov27",
		"up" : __DIR__"minov29",
		]));
	set("area", "������");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
