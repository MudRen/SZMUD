// Code of ShenZhou
// Room: /d/mingjiao/tneitang.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴�Ϊ���������ã��������Ų�˹��̺����������������ڴ�������
���г������Ǽ򵥣�������һ�Ȱ�ɵ����磬����Ҳ�м������Σ�
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"tdating",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
