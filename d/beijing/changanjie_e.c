//Cracked by Roath
// Room: /d/beijing/changanjie_e.c

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
                "east"  : __DIR__"chongwenmen",
		"west"  : __DIR__"changanjie",
		"southwest" : __DIR__"rongbaozhai",
//		"southeast" : __DIR__"huayuan",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
