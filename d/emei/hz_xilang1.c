// Code of ShenZhou
// hz_xilang1.c ����������
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "����������");
	set("long", @LONG
�����Ƕ��һ��������ȡ���������ͨ������������ͨ���㳡��
LONG
	);
	set("exits", ([
		"south" : __DIR__"hz_xilang2",
		"east" : __DIR__"hz_guangchang",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

