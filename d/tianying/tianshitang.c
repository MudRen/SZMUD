// Code of ShenZhou
// room: tianshitang.c

inherit ROOM;

void create()
{
        set("short", "������");
        set("long", @LONG
�����������ã���������������̺�������佣��ʿ�����վ��
���ԡ���ӥ�̽��������������ã���΢��������֮ĩ�������ǽ�����
������ʦ������ԫ��
LONG );

        set("exits", ([
		"west" : __DIR__"zoulang7",
        ]));

        setup();
        replace_program(ROOM);
}
