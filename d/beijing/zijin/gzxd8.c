//Cracked by Roath
// Room: /d/beijing/zijincheng/gzxd8.c

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
  "north" : __DIR__"gzxd9",
  "west" : __DIR__"jingrengong",
  "east" : __DIR__"yanxigong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
