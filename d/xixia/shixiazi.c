// Code of ShenZhou
// Room: /d/xixia/shixiazi.c

inherit ROOM;

void create()
{
	set("short", "ʯϿ��");
	set("long", @LONG
ʯϿ������ǰ�Ļƺӹʵ������ڱ���Ǵ��СС�Ķ���ʯ�����������ɸߵ�
���£�ǧ�����֣�������˵�����µĲ�ɣ��Ҫ�������õĻ������������𵽷�
��Ư�����ǳ������껨ʯ��
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "northeast" : __DIR__"bcwan",
  "southwest" : __DIR__"tumenzi",
]));
	set("objects", ([
		"/clone/weapon/stone" : 2,
	]));
	setup();
	replace_program(ROOM);
}
