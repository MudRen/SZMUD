//Cracked by Roath
// Room: /d/beijing/west/baihuayuan.c

inherit ROOM;

void create()
{
	set("short", "�ٻ�԰");
	set("long", @LONG
����������������ݣ������¼�Ϊʢ��һ��δл��һ��
�ֿ���
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"shibanlu1",
  "east" : __DIR__"penshuichi",
  "southwest" : __DIR__"xitianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
