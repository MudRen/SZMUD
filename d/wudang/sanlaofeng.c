// Code of ShenZhou
// sanlaofeng.c ���Ϸ� 
// by Fang 8/19/96

inherit ROOM;

void create()
{
	set("short", "���Ϸ�");
	set("long", @LONG
ֻ���������ͻأ�������ޱȣ����˶಻�ҷŵ��ڴ����ͷ羰��
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"northdown" : __DIR__"wuyaling",
                "southup" : __DIR__"wulaofeng",
	]));
	set("cost", 3);
	setup();
	replace_program(ROOM);
}

