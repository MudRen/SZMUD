//Cracked by Roath
// Room: /d/beijing/west/youandajie.c

inherit ROOM;

void create()
{
	set("short", "�Ұ��Ŵ��");
	set("long", @LONG
���Ƿ������ֵ��Ұ��Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"guangandajie",
  "south" : __DIR__"youanmen",
  "east" : __DIR__"tianshuijing",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
