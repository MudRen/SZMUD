// Code of ShenZhou
// room: zoulang6.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵ����߿ɴ���΢
�ã���������΢�á�
LONG );

        set("exits", ([
                "east" : __DIR__"tianweitang",
                "west" : __DIR__"ziweitang",
		"south" : __DIR__"changlang1",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
