// Room: /d/hengshan/cuiping2.c
// Date: CSWORD 96/03/25

inherit ROOM;

void create()
{
	set("short", "����ɽ��");
	set("long", @LONG
�����ڴ���ɽ���ϣ���ľ���죬�Ѽ����ա�ɽ�־��ף�������
�����ã�һ�г��׾���ϴ����ɽ���о�������ɽ��ɫ��
LONG
	);
	set("exits", ([
		"southup"   : __DIR__"zhandao",
		"eastdown" : __DIR__"cuiping1",
	]));
	set("cost", 1);
	set("outdoors", "hengshan");
	setup();
        replace_program(ROOM);
}

