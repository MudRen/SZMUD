// Code of ShenZhou
// wuyaling.c ��ѻ�� 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "��ѻ��");
	set("long", @LONG
����һ�����ļ��룬����������һ���������������ƶ�䣬ȽȽ������ɽ
�����������Ϯ��������ֻ��ѻ�������Ƽʣ��ڰ׷�����ε����ۡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"langmei",
                "southup" : __DIR__"sanlaofeng",
	]));
        set("objects", ([
                __DIR__"npc/wuya" : 5,
        ]));
	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

