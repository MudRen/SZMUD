//Cracked by Roath
// Room: /d/beijing/west/baozhu.c

inherit ROOM;

void create()
{
	set("short", "�����ͬ");
	set("long", @LONG
����һ����������ʮ��Ѱ����Ƨ��С��ͬ��·�����ż�������
����Ҳ��̫�࣬���Ͽ��������ǻ����˵ġ�������һ��С�Ƶ꣬��
������һ��ҩ�꣬������д�š��ش��á��������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"xizhidajie",
  "west" : __DIR__"jiudian",
  "south" : __DIR__"fuchengmenjie2",
  "east" : __DIR__"huichuntang",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
