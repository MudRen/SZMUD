// Code of ShenZhou
// room: zhuquetan.c

inherit ROOM;

void create()
{
        set("short", "��ȸ̳");
        set("long", @LONG
��������ӥ����̳֮һ����ȸ̳�������������һ�����ң�����
�����̽���֡���ȸ�����ɽ������ᡣ�������һ�����磬�����ϻ�
��һ����ȸͼ���������硣
LONG );

        set("exits", ([
                "north" : __DIR__"zoulang4",
        ]));

        setup();
        replace_program(ROOM);
}
