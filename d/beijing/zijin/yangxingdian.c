//Cracked by Roath
// Room: /d/beijing/zijincheng/yangxingdian.c

inherit ROOM;

void create()
{
	set("short", "���Ե�");
	set("long", @LONG
������Ǭ¡Ԥ�������������֮������ʵ����Ǭ¡��û�ڴ�ס����
ֻ��Ǭ¡��ʮ����ʮ���£��ڴ˵���������󳼡��ɹ����������պ�
���⣬̨���ȡ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"leshoutang",
  "south" : __DIR__"yangxingmen",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
