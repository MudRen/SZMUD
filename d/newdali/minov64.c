// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov64.c

inherit ROOM;

void create()
{
	set("short", "ϲ�ݳ�");
	set("long", @LONG
ϲ���������ǣ��Ǵ����ϲ���ǣ����ƴ��Ѽ�Ϊ���٣��ؾ��˻����ڣ���
ó�����٣��д��������������˽��ף��ɹ�������Ľ�����˿֯Ʒ��������Ƥë
�ȣ�������������ӡ�ȵĿ�����࣬ǰ����˿������˹������Զ��������
LONG);
	set("objects", ([
		__DIR__"npc/indiman" : 1,
		]));
	set("exits", ([
		"southwest" : __DIR__"minov65",
		"north" : __DIR__"minov63",
		"south" : __DIR__"minov71",
		"east" : __DIR__"dlkd1",
		]));
	set("area", "ϲ�ݳ�");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
