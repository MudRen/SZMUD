// Code of ShenZhou
// Room: /d/xiangyang/huilang1.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʯ����Χ�������ȣ���������������Լ�ɼ�԰�о��¡���
��˳�������������죬�������߸���һ���᷿��
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 5, "y" : -6 ]) );
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"wofang2",
  "east" : __DIR__"wofang1",
  "southeast" : __DIR__"huilang2",
  "west" : __DIR__"huajing2",
]));

	setup();
	replace_program(ROOM);
}
