// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov89.c

inherit ROOM;

void create()
{
	set("short", "��Ū��");
	set("long", @LONG
�˴�λ�ڴ���ı����������ɵ�����θ������������ģ��������ڸ�ɽ
�ϡ�����������ɽ֮�������ٲ�����ӿ�Ĵ�ɺӡ���İ����ɽʯ�ݳɣ������࣬
����ȫ�ǡ��˳ǲ�������ɽ�Ϸֲ���Щ������ӣ������˸���ţ���������
LONG);
	set("objects", ([
		__DIR__"npc/wyshang.c" : 1,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov90",
		"southdown" : __DIR__"minov88",
		"eastup" : __DIR__"minov91",
		]));
	set("area", "��Ū��");
	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
