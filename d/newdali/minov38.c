// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov38.c

inherit ROOM;

void create()
{
	set("short", "ũ��");
	set("long", @LONG
����һС����ͨ��ˮ�������Ϫ�����������ʮ�ַ��㡣Χ��ũ�����һ
ƬƬɣ�֣������˲�ɣ�����ϣ���֯�൱���µ�˿֯Ʒ������������ӡ�
LONG);
	set("objects", ([
		__DIR__"npc/niu.c" : 1,
		__DIR__"npc/bynong.c" : 1,
		]));
	set("exits", ([
		"south" : __DIR__"minov34",
		"west" : __DIR__"minov39",
		]));
	set("area", "���۲�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
