//Cracked by Roath
// Room: /d/beijing/west/guangandajie.c

inherit ROOM;

void create()
{
	set("short", "�㰲�Ŵ��");
	set("long", @LONG
���Ƿ������ֵĹ㰲�Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ������ǲ��пڡ�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "southeast" : __DIR__"yizhan",
  "west" : __DIR__"guanganmen",
  "south" : __DIR__"youandajie",
  "east" : __DIR__"caishikou",
  "northwest" : __DIR__"xibianmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
