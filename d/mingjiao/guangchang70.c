// Code of ShenZhou
// Room: /d/mingjiao/guangchang70.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "�㳡");
	set("long", @LONG
�˴���һС�㳡������һ�Ӷӽ�������ȥȥ�����Ÿ��ַ�ɫ���е�Я
������ǹ�������ȵȱ������������˽ý�����̬ׯ�ء������������Ŵ�����
�Ϸ��ǵ����š�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"di",
  "north" : __DIR__"tian",
  "east" : __DIR__"shmen",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
