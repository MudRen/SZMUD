// Code of ShenZhou
// room: damen.c

inherit ROOM;

void create()
{
        set("short", "��ӥ�̴���");
        set("long", @LONG
��������ӥ�̴��š�һ�Ⱥ�����ų����ţ�������һ����ң�д
�ż������֡���ӥ�̡�������ӥ���˰�üӥ��������һ���������ڽ�
��һ��������������������վ�����ԣ������Ŵ��š�
LONG );

        set("exits", ([
                "north" : __DIR__"road1",
                "south" : __DIR__"unknown",
        ]));

        set("outdoors", "tianying" );

        setup();
        replace_program(ROOM);
}
