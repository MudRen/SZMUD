// Code of ShenZhou
// /d/taihu/yixing.c
// by aln  2 / 98

inherit ROOM;

void create()
{
    int i;
        set("short", "����");
        set("long", @LONG
������������������ն�����ɽ��ˮ֮����ӳ��һ�Ѷ���ɰ��������
��һ����ɫ�����У���Զ������̫���ߡ��Ϸ����Ǻ��ݸ��ˡ�
LONG
        );

        set("exits", ([
                "southeast"  : __DIR__"field1-2",
		"south" : __DIR__"nanxun",
		"north" : "/d/city/wdroad1",
        ]));

	set("outdoors", "taihu");

	set("cost", 2);
        setup();

	replace_program(ROOM);
}

