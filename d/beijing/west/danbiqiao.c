//Cracked by Roath
// Room: /d/beijing/west/danbiqiao.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
��������߳���Χƽ�����ߣ���ͬһ���Ž������������
���������������һ��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : __DIR__"huangqiongyu",
  "north" : __DIR__"qiniandian",
  "westdown" : __DIR__"shibanlu2",
  "eastdown" : __DIR__"shibanlu3",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
