//Cracked by Roath
// Room: /d/beijing/west/shibanlu1.c

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
  "north" : __DIR__"baihuayuan",
  "west" : __DIR__"xitianmen",
  "east" : __DIR__"shibanlu2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
