// Code of ShenZhou
// wdroad2.c
// by Xiang

inherit ROOM;

void create()
{
	set("short", "��ʯ���");
	set("long", @LONG
������һ����ʯ����ϣ��ϱ���Լ�ɼ������ݳǵĳ�ǽ��
������һ�����ͨ�򺺽��ߡ�
LONG
	);
        set("outdoors", "huashan");

	set("exits", ([
                "south" : __DIR__"road1",
		"northwest" : "/d/shaolin/yidao",
	]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

