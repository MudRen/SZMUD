//Cracked by Roath
// Room: /d/beijing/west/lingjing.c

inherit ROOM;

void create()
{
	set("short", "�龳��ͬ");
	set("long", @LONG
����һ��ʮ�ֿ����ĺ�ͬ����ȴûʲô��ͨ����������ǰ����
һ��������ţ��ſ���һ��ʯʨ�ӣ������൱ɭ�ϣ���Ȼ�ǹٻ���
�ҡ��������Ƿ����������֡�
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/beijing/kangqin/door",
  "east" : __DIR__"fuyoujie",
  "southwest" : __DIR__"xuanwudajie",
  "northwest" : __DIR__"fuchengmenjie2",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
