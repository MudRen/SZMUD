// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov70.c

inherit ROOM;

void create()
{
	set("short", "������");
	set("long", @LONG
һ��Ƭï�ܵ�������������ɽ�����ӳ�ȥ���˼��������ۣ������أ�����
¬¹���̨�ĸ�Ů��ǰ����ժ����Ϊʳ������Ҳ����Щ��������������Ͳ�ͱ�֯
��������¨��
LONG);
	set("objects", ([
		__DIR__"npc/tycaisun" : 1,
		]));
	set("exits", ([
		"north" : __DIR__"minov66",
		]));
	set("area", "�䶨��");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
