// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov54.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�������������ľ۾����ģ�������������Ĵ󲿣������ģ����а͵ĵ顢��
�ۡ��͸���������������һ��ʯ��С�ǣ��˿ڲ��࣬����ɢ�������Ӹ���������
����Ҫ��һЩ���̺ͼ�������
LONG);
	set("objects", ([
		__DIR__"npc/wymuyang" : 1,
		__DIR__"npc/wyshang" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov58",
		"south" : __DIR__"minov53",
		"west" : __DIR__"minov55",
		"east" : __DIR__"minov57",
		]));
	set("area", "��³��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
