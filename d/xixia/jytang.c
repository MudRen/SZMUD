// Code of ShenZhou
// Room: /d/xixia/jytang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������̴ľ�㰸������ȼ�ż����㣬������̴��������Ҫ����һƷ
�õ����ھ����������Բ�ͨ������ڴ������ģ��Ӵ˳�ΪһƷ����ʽһ
Ա�������������á�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"dayuan",
]));
	set("objects", ([
		__DIR__"npc/ypshi" : 3,
		__DIR__"npc/yun" : 1,
	]));
	setup();
	replace_program(ROOM);
}
