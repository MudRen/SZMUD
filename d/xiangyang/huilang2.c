// Code of ShenZhou
// Room: /d/xiangyang/huilang2.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
��ʯ����Χ�������ȣ���������������Լ�ɼ�԰�о��¡���
��˳�������������죬ͨ��һ�пͷ���
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : 6, "y" : -7 ]) );
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"huilang1",
  "south" : __DIR__"kefang",
]));

	setup();
	replace_program(ROOM);
}
