//Cracked by Roath
// Room: /d/beijing/changanjie_w.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
���Ƿ������ֵĳ����֣���ֱ����������ɭ�ϵ��Ͻ��������찲���ˡ���
��ʱ����Ѳ�ߵ������̲��·�����ˡ���������Ǹ��ֵ��̣��㿴���۶����ˡ�
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
                  "east"  : __DIR__"changanjie",
		  "west"  : __DIR__"xuanwumen",
//		  "southwest":__DIR__"yuefang",
//		  "southeast":__DIR__"qitang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
