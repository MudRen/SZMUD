// Code of ShenZhou
// Room: /d/dali/road8.c

inherit ROOM;

void create()
{
	set("short", "̫�Ͷ���");
	set("long", @LONG
̫�ͽ�������������ϱ��ţ���������ǳ�����Ҫ�ֵ�������������ڴ�
�Ĳ�ɫʯ���̳ɣ��������̣�ɷ�Ǻÿ������ھ������ᷱ�ӣ�ϰ�׸��죬��ʳ��
���޲�������ԭ��������Ѧ�ϳ����̣�������ҩ�̡�
LONG
	);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("cost", 1);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"chengyipu",
  "south" : __DIR__"yaopu",
  "east" : __DIR__"shipu.c",
  "west" : __DIR__"taihejie4",
]));

	setup();
	replace_program(ROOM);
}
