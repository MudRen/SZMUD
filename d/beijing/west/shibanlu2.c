//Cracked by Roath
// Room: /d/beijing/west/shibanlu2.c

inherit ROOM;

void create()
{
	set("short", "ʯ��·");
	set("long", @LONG
����һ����ʯ��·���������˲��ٰ������Ե�ׯ�����¡�
�������������ţ������Ǹ���԰��һ����Ũ���Ļ����˱Ƕ�����
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"penshuichi",
  "west" : __DIR__"shibanlu1",
  "eastup" : __DIR__"danbiqiao",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
