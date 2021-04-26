// Code of ShenZhou
// Room: /d/newdali/chongs.c

inherit ROOM;

void create()
{
	set("short", "ǧѰ��");
	set("long", @LONG
���ǳ�ʥ������������������ǧѰ��������ʷ��Σ��ܴ�ʽ��
��ʮ���㣬��Լ��ʮ���ɡ�����������������ʫ���ʣ������Ľ�
����һֻͭ���Ľ����񣬴�˵������ѹ�����е�����ˮ�֡�
LONG
	);
	set("objects", ([ /* sizeof() == 1 */
  "/d/dali/npc/sengren" : 2,
]));
	set("cost", 3);
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"wanrenzhong",
  "enter" : __DIR__"chongs1.c",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
