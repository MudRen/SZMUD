//Cracked by Roath
// Room: /d/beijing/zijincheng/gzxd1.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���С
��ͣ����֦��ߴߴ�����и���ͣ��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zaobanchu",
  "south" : __DIR__"gzxd2",
  "east" : __DIR__"youyimen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
