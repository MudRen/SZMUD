// Code of ShenZhou
// room: zoulang7.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵ����߿ɴ���΢
�ã������������á�
LONG );

        set("exits", ([
                "east" : __DIR__"tianshitang",
                "west" : __DIR__"tianweitang",
		"south" : __DIR__"changlang2",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
