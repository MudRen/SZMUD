//Cracked by Roath
// Room: /d/beijing/zijincheng/nanshufang.c

inherit ROOM;

void create()
{
	set("short", "���鷿");
	set("long", @LONG
��ѧ�����õĴʳ��ڴ�ֵ��,ÿ������,׼���ʵ���ʱ��ѯ,ͬ
ʱҲ�۲���Щ���Ƿ��������.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"nzsfang",
  "east" : __DIR__"jingshifang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
