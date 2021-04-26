// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov32.c

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�������Ȼ���ʣ�һ�����������Ϸɽ�������ɽ����������̸�����
���˾���ͽ��ͨ������ˮ�����ɾ���·������ͣ��������Ͳװˮ��ʡ��������
�����֣���Ҷ��ɽ��ɳɳ���졣��Щ���Ĵ���Զ������ɽ������������Ϊʳ��
LONG);
	set("objects", ([
		__DIR__"npc/byshanren.c" : 1,
		]));
	set("exits", ([
		"northdown" : __DIR__"minov31",
		"southdown" : __DIR__"minov33",
		]));
	set("area", "������");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("resource/water",1);
	setup();
	replace_program(ROOM);
}
