// Code of ShenZhou
// Room: /d/mingjiao/songlin1.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴����ּ�Ϊï�ܣ����ⱻ��֦��ס�����ǻ谵��������û�е�·�ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "northwest" : __DIR__"shanjiao1",
]));
	set("no_clean_up", 0);
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
