//Cracked by Roath
// Room: /d/beijing/west/deshengjie.c

inherit ROOM;

void create()
{
	set("short", "��ʤ�Ŵ��");
	set("long", @LONG
���Ƿ������ֵĵ�ʤ�Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�������һ�����ӵ����
������ƣ��Ǿ�������ѧ��֮������ͬ�����������ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"guloudajie",
  "east" : __DIR__"wumiao",
  "northwest" : __DIR__"deshengmen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
