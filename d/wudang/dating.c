// Code of ShenZhou
// dating.c ����
// xQin 11/00

inherit ROOM;

void create()
{
	set("short", "����" );
	set("long", @LONG
������ˮ�����������ϣ�ֻ����ǰ��ȻһƬ��������������������ʯש
Ƭ��ʮ������ľ�������ſ������ڲ�����������أ�ȴ˿����ʧׯ��֮�硣
����Ҳ���䵱�ɽӼ����͵Ŀ�����
LONG
	);
	set("exits", ([
		"south" : __DIR__"sanqingdian",
		"north" : __DIR__"dishuiyan",
	]));
	
	setup();
	replace_program(ROOM);
}

	
	
		