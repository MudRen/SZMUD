//Cracked by Roath
// Room: /d/beijing/guloudajie_e.c

inherit ROOM;

void create()
{
	set("short", "��¥�����");
	set("long", @LONG
���Ƿ������ֵĹ�¥����֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�������ǹ�¥��
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"gulou",
  "east" : __DIR__"dongzhidajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
