// Code of ShenZhou
// room: zoulang8.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵ��ϱ߿ɴ���΢
�ã������ǽ���������
LONG );

        set("exits", ([
                "north" : __DIR__"dating",
                "south" : __DIR__"tianweitang",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
