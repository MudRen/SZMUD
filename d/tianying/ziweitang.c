// Code of ShenZhou
// room: ziweitang.c

inherit ROOM;

void create()
{
        set("short", "��΢��");
        set("long", @LONG
��������΢�ã���������������̺�������佣��ʿ�����վ��
���ԡ���ӥ�̽��������������ã���΢��������֮�ڶ��ã������ǽ�
������������Ů�����ء�
LONG );

        set("exits", ([
                "east" : __DIR__"zoulang6",
        ]));

        setup();
        replace_program(ROOM);
}
