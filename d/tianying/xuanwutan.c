// Code of ShenZhou
// room: xuanwutan.c

inherit ROOM;

void create()
{
        set("short", "����̳");
        set("long", @LONG
��������ӥ����̳֮һ������̳�������������һ�����ң�����
�����̽���֡����䡱���ɽ������ᡣ�������һ�����磬�����ϻ�
��һ����ʿͼ���������硣
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang2",
        ]));

        setup();
        replace_program(ROOM);
}
