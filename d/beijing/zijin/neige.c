//Cracked by Roath
// Room: /d/beijing/zijincheng/neige.c

inherit ROOM;

void create()
{
	set("short", "�ڸ�");
	set("long", @LONG
�ڸ��ѧʿ��ѧʿ���ڴ˰��¡���������������������˱ʣ�ī��
ֽ���⡣��������������������ī֭�ϣ�������г�����ī������㡣
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"wenhuadian",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
