//Cracked by Roath
// Room: /d/beijing/zijincheng/huayuan.c

inherit ROOM;

void create()
{
	set("short", "���ٹ���԰");
	set("long", @LONG
������Ǭ¡�ʵ�׼����λ����Ϊ����԰��Ϊ�Լ����ġ� 
԰�ڲ���ͤ��̨��¥���󣬲��ɴ�أ�����ͨ�ġ�
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"gzxd5",
  "east" : __DIR__"leshoutang",
]));
	set("no_clean_up", 0);
	set("outdoors", "beijing");

	setup();
	replace_program(ROOM);
}
