// Code of ShenZhou
// room: tianweitang.c

inherit ROOM;

void create()
{
        set("short", "��΢��");
        set("long", @LONG
��������΢�ã���������������̺�������佣��ʿ�����վ��
���ԡ���ӥ�̽��������������ã���΢��������֮���ã������ǽ���
�������Ķ�����Ұ����
LONG );

        set("exits", ([
                "east" : __DIR__"zoulang7",
		"west" : __DIR__"zoulang6",
		"north" : __DIR__"zoulang8",
        ]));

        setup();
        replace_program(ROOM);
}
