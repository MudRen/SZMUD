//Cracked by Roath
// Room: /d/beijing/west/guloudajie2.c

inherit ROOM;

void create()
{
	set("short", "��¥���");
	set("long", @LONG
���Ƿ������ֵĹ�¥��֣���ֽ����������ˮ��������
����Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�С
�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�������Ǿ��ǵĹ�¥��
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"xizhidajie2",
  "east" : __DIR__"gulou",
  "northwest" : __DIR__"guloudajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
