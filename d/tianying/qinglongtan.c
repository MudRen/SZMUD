// Code of ShenZhou
// room: qinglongtan.c

inherit ROOM;

void create()
{
        set("short", "����̳");
        set("long", @LONG
��������ӥ����̳֮һ������̳�������������һ�����ң�����
�����̽���֡����������ɽ������ᡣ�������һ�����磬�����ϻ�
��һ������ͼ���������硣
LONG );

        set("exits", ([
                "south" : __DIR__"zoulang2",
        ]));

        setup();
        replace_program(ROOM);
}
