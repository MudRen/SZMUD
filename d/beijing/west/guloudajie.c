//Cracked by Roath
// Room: /d/beijing/west/guloudajie.c

inherit ROOM;

void create()
{
	set("short", "��¥���");
	set("long", @LONG
���Ƿ������ֵĹ�¥��ִ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ����������¥��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "southeast" : __DIR__"guloudajie2",
  "west" : __DIR__"yamen",
  "north" : __DIR__"deshengjie",
  "east" : __DIR__"zhonglou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
