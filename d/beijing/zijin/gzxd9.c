//Cracked by Roath
// Room: /d/beijing/zijincheng/gzxd9.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���
С��ͣ����֦��ߴߴ�����и���ͣ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"gzxd8",
  "north" : __DIR__"gzxd10",
  "west" : __DIR__"chengqiangong",
  "east" : __DIR__"yonghegong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
