// Code of ShenZhou
// toutian.c ͷ���� 
// by Fang 8/20/96

inherit ROOM;

void create()
{
	set("short", "ͷ����");
	set("long", @LONG
ֻ����ʯ������ͨ��ɽ�ۣ�һ��ʯ����д�š�ͷ���š��������֣�������
���䵱�������������㡣
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"north" : __DIR__"huixian",
                "southup" : __DIR__"ertian",
	]));
	set("cost", 3);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

