// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov94.c

inherit ROOM;

void create()
{
	set("short", "�������");
	set("long", @LONG
һ��Ƭɽ�³�����ݣ����Ƿ���ţ��ĺõط�������������ߣ���ճ�����
ɫ������ɽ����ľ�Ѿ����٣������϶��ǵͰ���ľ��ݵء����ٸ����Ĵ����ڴ�
������
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang.c" : 1,
		__DIR__"npc/wymuyren.c" : 1,
		]));
	set("exits", ([
		"westdown" : __DIR__"minov91",
		]));
	set("area", "��Ū��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
