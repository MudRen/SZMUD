// Code of ShenZhou
// Room: /d/xixia/wsling.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
���������������ϵ�һ����Ҫ�ضΣ���ʯɽ���������أ�ʱ����Ұ�޳�û��
һ���ٵ���ɽ�����Ѷ�����
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"dacaigou",
  "northwest" : __DIR__"weiwu",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
