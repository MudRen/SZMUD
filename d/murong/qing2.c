// Code of ShenZhou
// Room: /d/murong/qing2
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "����С��");
	set("long", @LONG
    С���Ҷ���д��"����"����,������Ϊ���������ڷ������������Σ�
���䲢���Ǻܴ󣬵��ܱ��£�����͸������ˮ�����ζ��һ����������
���Ų�������Ͳ衣
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing1",
        "north" : __DIR__"qing3",
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/abi" : 1,
		]));

	setup();
	replace_program(ROOM);
}
