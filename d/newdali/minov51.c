// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov51.c

inherit ROOM;

void create()
{
	set("short", "����ɽ����");
	set("long", @LONG
����ɽ�ϵ����ն�����������������������̡��ش���ɽ�ļ��Ժ�����
��������ʱ����û��ֻ���¸ҵ����˲Ÿ�����������������ɽ������ˮ�ȵء�
LONG);
	set("objects", ([
		BEAST_D("laohu") : 1
		]));
	set("exits", ([
		"east" : __DIR__"minov50",
		]));
	set("area", "��ˮ�ذ�");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
