//Cracked by Roath
// Room: /d/beijing/east/dongzhidajie2.c

inherit ROOM;

void create()
{
	set("short", "��ֱ�Ŵ��");
	set("long", @LONG
���Ƿ������ֵĶ�ֱ�Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"zhongtianlou",
  "west" : "/d/beijing/west/gulou",
  "east" : __DIR__"dongzhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
