//Cracked by Roath
// Room: /d/beijing/zijincheng/xiaodao1.c

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
���ǹ���֮��ļе��������ģ�ż���м���������̫���߹���
С��ͣ����֦��ߴߴ�����и���ͣ�����ߵ�̨�׿���ͨ����
�͵�.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"houyoumen.c",
  "south" : __DIR__"zhongyoumen",
  "east" : __DIR__"zhonghedian",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
