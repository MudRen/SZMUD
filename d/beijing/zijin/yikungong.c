//Cracked by Roath
// Room: /d/beijing/zijincheng/yikungong.c

inherit ROOM;

void create()
{
	set("short", "�����");
	set("long", @LONG
�����������������Ǿ�ס�ĵط�.�������̫��ס���㹬ʱ,ÿ
���ش���ն�Ҫ��������������ǵĳ���.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"changchungong",
  "north" : __DIR__"tihedian",
  "east" : __DIR__"tongdao2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
