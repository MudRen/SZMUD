//Cracked by Roath
// Room: /d/beijing/east/dongzhidajie.c

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
	set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"dongzhidajie2",
  "east" : __DIR__"dongzhimen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
