//Cracked by Roath
// Room: /d/beijing/guloudajie_w.c

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
  "south" : __DIR__"bingbuyamen",
  "west" : __DIR__"xizhidajie",
  "east" : __DIR__"gulou",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
