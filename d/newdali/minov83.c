// Code of ShenZhou
// minority or tribe village and suburban
// Room: /d/dali/minov83.c

inherit ROOM;

void create()
{
	set("short", "��������");
	set("long", @LONG
����һƬʪ������֣�����ˮ��������·���У�ʮ���ɸߵľ޴������̸���
�ڣ����ɴֵü����˺ϱ�ҲΧ��ס����������֦�´�����ˮ�з�������������Ϊ
����ľ��¡�������Ȼ�������ޣ�ȴ�Ƿ��ݾ۾ӵ���������������̨��������
Խ�ڴ�������¶�ĸ�֦�ϣ��ö������Է���
LONG);
	set("objects", ([
		__DIR__"npc/tylieren" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"minov78",
		]));
	set("area", "³����");
	set("cost", 5);
	set("no_clean_up", 0);
	set("outdoors","dali");
	setup();
	replace_program(ROOM);
}
