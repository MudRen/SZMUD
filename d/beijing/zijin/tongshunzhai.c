//Cracked by Roath
// Room: /d/beijing/zijincheng/tongshun.c

inherit ROOM;

void create()
{
	set("short", "ͬ˳ի");
	set("long", @LONG
���������͹��ϱߵ�һ��Сƫ��ط����󣬵����õ�ʮ�����£�
��ɨ��Ҳ�൱���࣮һ�ɳ���֮���������������޵��������ƣ�����
�����˯��
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"yonghegong",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
