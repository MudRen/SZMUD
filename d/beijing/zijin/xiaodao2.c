//Cracked by Roath
// Room: /d/beijing/zijincheng/xiaodao2.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���С
��ͣ����֦��ߴߴ�����и���ͣ�����ߵ�̨�׿���ͨ���к͵�.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houzuomen",
  "south" : __DIR__"zhongzuomen",
  "west" : __DIR__"zhonghedian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
