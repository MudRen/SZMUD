// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov9.c

inherit ROOM;

void create()
{
	set("short", "����Ȫ");
	set("long", @LONG
����Ȫ���Եø�������ʪ�󣬴����ĺ�����������˷����㼯�������£���
���У��������裬��ǧ����ֻ�ʵ�������һ����ʹ�����û��Ž��ء��ر�����
����Ȫ�ϣ�˳���ǵ���������������������һֻҧ��һֻ��β�����γ�ǧ�ٸ���
��������������Ͷʯ��ɢ���������˾�̾����ۡ�
LONG);
	set("exits", ([
		"southeast" : __DIR__"minov8",
		"north" : __DIR__"yuxuguan1",
		]));
	set("area", "������");
	set("cost", 1);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	setup();
	replace_program(ROOM);
}
