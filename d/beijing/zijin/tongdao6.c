//Cracked by Roath
// Room: /d/beijing/zijincheng/tongdao6.c

inherit ROOM;

void create()
{
	set("short", "ͨ��");
	set("long", @LONG
����һ������ʯ�̳ɵĿ�ͨ��,�ɹ����г���ͨ��,��������
�ɸߵ�Χǽ,���˸е�ׯ������.
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"kunningmen",
  "south" : __DIR__"tongdao5",
  "west" : __DIR__"zhongcuigong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
