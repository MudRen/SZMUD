// Code of ShenZhou
// /d/city/wdroad1.c
// by xiang
// modified by aln  2 / 98

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ����������ǳ���æ����ʱ������������ҴҶ�����
���������һЩС��̯���ƺ���һ�����С��ϱ߾��ǽ���һ��������̫��������
�ǳ�ɽ���룬����ͨ�����ݳǡ�
LONG
	);
        set("outdoors", "wudang");

	set("exits", ([
                "south" : "/d/taihu/yixing",
		"north" : __DIR__"nanmen",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

