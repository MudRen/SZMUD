// Code of ShenZhou
// room: shenshetan.c

inherit ROOM;

void create()
{
        set("short", "����̳");
        set("long", @LONG
��������ӥ����̳֮һ������̳�������������һ�����ң�����
�����̽���֡����ߡ����ɽ������ᡣ�������һ�����磬�����ϻ�
��һ������ͼ���������硣
LONG );

        set("exits", ([
                "south" : __DIR__"zoulang5",
        ]));

        setup();
        replace_program(ROOM);
}
