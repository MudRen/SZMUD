// Code of ShenZhou
// pine_road.c ���ִ��
// by Marz@XKX 11/11/96

inherit ROOM;

void create()
{
	set("short", "���ִ��");
	set("long", @LONG
������ɽ�������е�һ����·�ϣ���ʱ�е�ʿ�����˿��ź�����ľ����
�Ծ�������������ɽ��·��������ï�ܵ������֣����з�ľ��ϣ�����д���
�������������꡹���졣
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"eastdown" : __DIR__"wdroad8",
		"west" : __DIR__"shanmen",
		"north" : __DIR__"pine_road1",
		"south" : __DIR__"pine_road2",
	]));

	set("cost", 2);
	setup();
	replace_program(ROOM);
}

