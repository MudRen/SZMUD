// Code of ShenZhou
// room: zoulang5.c

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����һ���ǳ����������ȣ����Ӻ��������û������̴ľ�Ƴɣ�
���������������ͼ�����������ɣ�����ʤ�ա����ȵ��ϱ���һ����
�����ͨ������̳��
LONG );

        set("exits", ([
                "north" : __DIR__"shenshetan",
                "south" : __DIR__"dadian",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
