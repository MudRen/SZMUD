// Code of ShenZhou
// changle/clwoshi.c
// by aln 2 / 98

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
���ڳ��������ݻ�������Ĵ����������������������������ӣ�
���̽��档��ǰ���ʵʹ�����Լ���������ƺ����ˡ���ǰ����¯����
����������ֻ��������һ�������磬����������ɶ�����
LONG );

        set("exits", ([
		"south" : __DIR__"clxiaoting",
        ]));

        set("cost", 0);

        set("objects",([
                __DIR__"npc/cl_shijian" : 1,
        ]));

        setup();

        replace_program(ROOM);
}
