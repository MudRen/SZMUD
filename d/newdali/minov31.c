// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov31.c

inherit ROOM;

void create()
{
	set("short", "����");
	set("long", @LONG
�˴�ɽ����խ����ľ�ر�ï�ܣ�ɽ��̤������С�����ݺύ�����ľ�ڵ���
���ţ���·�߲�ͣ���õ�������·������˳��ǰ����������ɽ������������ʱ��
�����޾��ߣ�ż�����ܿ��������Ŀ�ȸ�ɹ���
LONG);
	set("objects", ([
		"/d/foshan/npc/zsnake.c" : 1,
		]));
	set("exits", ([
		"northeast" : __DIR__"minov26",
		"southup" : __DIR__"minov32",
		]));
	set("area", "������");
	set("cost", 3);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
