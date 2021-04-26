// Code of ShenZhou
// Room: /d/xixia/hsxia.c

inherit ROOM;

void create()
{
	set("short", "��ɽϿ");
	set("long", @LONG
��ɽϿ�Ǹ��ǳ��վ���Ͽ�ȣ���������ʮ�ɵĻ����£����Ƕ��ͣ���
��ֻ��һ������ͨ��һ��һ���խ�����׳ơ�һ���족������û��ʲô��
�ȴ�����ó�������ʧ�١�
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"jingyuan",
  "north" : __DIR__"shimen",
]));
	set("objects", ([
		__DIR__"npc/mazei" : 1,
	]));
       set("fjing", 1);
	setup();
	replace_program(ROOM);
}
