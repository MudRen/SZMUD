// Code of ShenZhou
// Room: /d/xiangyang/liangc2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������ǳ������ε����򣬳��������������������꿹�У�ԭ��������
��������ʣ�޼������ٱ�ʿ���Ͻ�������������Ѳ�ߡ�
LONG
	);
	set("outdoors", "xiangyang");
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -1, "y" : 1 ]) );
	set("exits", ([ /* sizeof() == 1 */
  "north" : __DIR__"jicang",
]));

	setup();
	replace_program(ROOM);
}