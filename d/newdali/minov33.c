// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov33.c

inherit ROOM;

void create()
{
	set("short", "��ɽ����");
	set("long", @LONG
һ��Ƭï�ܵĳ������������ڰ�ɽ���Ļ����ϡ����ӶԴ��������������˵
�ǣ�������Ҫ�Ľ������ϣ�Ҳ���ճ�������Ʒ��ԭ���ϡ�ɽ�µĴ�ׯ��İ�����
������ɽ���ɷ����ӡ�����ɽ����Ϫ���£�������ˮ���Ѿ��Ĵ�ɽ�񾭳��ѿ�
���µ����Ӷ���Ϫ�У�����˳ˮƮ���������Ӹ�����Ϫˮ������������
LONG);
	set("objects", ([
		__DIR__"npc/byshanren1.c" : 2,
		]));
	set("exits", ([
		"northup" : __DIR__"minov32",
		"eastdown" : __DIR__"minov34",
		]));
	set("area", "���۲�");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
