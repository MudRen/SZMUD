// Code of ShenZhou
// room: baihutan.c

inherit ROOM;

void create()
{
        set("short", "�׻�̳");
        set("long", @LONG
��������ӥ����̳֮һ�İ׻�̳�������������һ�����ң�����
�����̽���֡��׻������ɽ������ᡣ�������һ�����磬�����ϻ�
��һ���׻�ͼ���������硣
LONG );

        set("exits", ([
                "south" : __DIR__"zoulang4",
        ]));

        setup();
        replace_program(ROOM);
}
