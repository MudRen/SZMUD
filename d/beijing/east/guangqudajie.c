//Cracked by Roath
// Room: /d/beijing/east/guangqudajie.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĹ����Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 5 */
  "northeast" : __DIR__"dongbianmen",
  "west" : "/d/beijing/west/dongtianmen",
  "north" : __DIR__"chongwendajie",
  "south" : __DIR__"zuoanmen",
  "east" : __DIR__"guangqumen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
