// Code of ShenZhou
// hutouyan.c ��ͷ�� 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "��ͷ��");
	set("long", @LONG
һ��޴����ʯ����ȥ����һ����ͷ���Ŵ���Ѫ������������������
�ڲ�ľ���С�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"wulaofeng",
                "southup" : __DIR__"chaotian",
	]));
        set("objects", ([
                BEAST_D("laohu") : 1]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

