//Cracked by Roath
// Room: /d/beijing/east/zhaoyangdajie2.c

inherit ROOM;

void create()
{
	set("short", "�����Ŵ��");
	set("long", @LONG
���Ƿ������ֵĳ����Ŵ�֣���ֽ����������ˮ������
������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա��ٻ�
С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"wangfudajie",
	"east" : __DIR__"zhaoyangdajie",
	"northwest" : __DIR__"dianmen",
	"north" : __DIR__"xingbu",
	]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
