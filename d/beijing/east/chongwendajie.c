//Cracked by Roath
// Room: /d/beijing/east/chongwendajie.c

inherit ROOM;

void create()
{
	set("short", "����������");
	set("long", @LONG
���Ƿ������ֵĳ��������֣���ֽ����������ˮ����
��������Ϣ����Ⱥ���������������������ֱ���ˣǹ���ա���
��С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
	"south" : __DIR__"guangqudajie",
	"north" : __DIR__"chongwenmen",
	"east" : __DIR__"wushengbiaoju",
	"southwest" : "/d/beijing/west/xiaohutong1",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
