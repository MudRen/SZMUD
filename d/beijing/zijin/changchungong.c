//Cracked by Roath
// Room: /d/beijing/zijincheng/changchungong.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��ԭ���Ǻ����Ǿ�ס�ĵط������������������ᣬ��δ���䡣
���ټ��һ��������տյ�����ûʲô������ֻ�м���̫��ż����
��ɨһ�¡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"yiqingshuwu",
  "south" : __DIR__"tiyuandian",
  "east" : __DIR__"yikungong",
]));

	setup();
	replace_program(ROOM);
}
