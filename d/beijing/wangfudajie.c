//Cracked by Roath
// Room: /d/beijing/wangfudajie.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
���Ƿ������ֵ�������֣���ֽ����������ˮ������������Ϣ����Ⱥ����
�����������������ֱ���ˣǹ���ա��ٻ�С�ԣ�Ӧ�о��У��۶���ò�ɼ�һ�ߡ�
�ֶ����Ǿ������������ϵ��ھ֡���ʤ�ھ֡�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
                "south" : __DIR__"chongwenmen",
		"north" : __DIR__"chaoyangdajie",
		"east"  : __DIR__"wusheng",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
