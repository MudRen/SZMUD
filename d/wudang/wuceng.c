// Code of ShenZhou
// wuceng.c ���¥
// by Fang 8/26/96

inherit ROOM;

void create()
{
	set("short", "��������¥");
	set("long", @LONG
��������¥�������أ������ʮ�������ʽ����ص����������
һ��֧�ţ��������ġ�һ��ʮ�������������︩�Ⱥɽ���������룬
Ϊ�۾�ʤ�ء�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
		"west" : __DIR__"taizipo",
	]));
	set("cost", 2);
        set("fjing", 1);
	setup();
	replace_program(ROOM);
}

