// Code of ShenZhou
// Room: /d/xiangyang/chexiang.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
������Ƨխ�ֵ�С�����Ź������ˮ�ĳ�ζ���������ڱǶ��ˣ���Ը��
�����Ρ������л������ڵ���ץʭ��ɹ̫��������ǽ���ƺ��и�����(dong)��
LONG
	);
        set("coordinates", ([ "x" : 1, "y" : 5 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"beijie3",
]));
	set("no_clean_up", 0);
        set("outdoors", "xiangyang");

	setup();
	replace_program(ROOM);
}
