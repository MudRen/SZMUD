// Code of ShenZhou
// /d/huanghe/clxiaowu.c
// by aln  2 / 98

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
���ǰ�������ƶ�Ǯ��С�ݣ����еķ����ϱ����Ǽ���������
����һ�ԣ��������¡����Ⱥ�������һ�Ŷ�����������������ߺ���
���ض�Ǯ���������ҡҷ���ƺ�û����ע���������
LONG );

        set("exits", ([
		"east" : __DIR__"clzoulang2",
        ]));

        set("resource/water", 1);

        set("cost", 0);

        set("objects",([
                __DIR__"npc/cl_bangzhong3" : 1,
        ]));

        setup();

        replace_program(ROOM);
}
