// room /d/wulin/dianmen.c
//updated by Lara 2001/10/14
inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @LONG
����������������ͬ������ĵ��ţ�����Ĵ����ϵ���ŷ������ޣ�
����˶��Ľ��������⡣�ڴ��ŵ����߸�����һ��������׳��ʯʨ����
�˸е�һ��ׯ������֮�����ſڵ�����ͬ����ʿ����ͣ�Ĵ������㡣����
���߾�������ͬ�˵������ˡ�

LONG
        );

        set("exits", ([
                "south" : __DIR__"shangwu",
                "north" : __DIR__"zoulang",
                "east" : __DIR__"xiaolu5",
                "west" : __DIR__"xiaolu1",
        ]));

        set("objects",([
                __DIR__"npc/yishi" : 2,
        ]));

        set("no_clean_up", 0);
        set("cost", 3);
        setup();
        replace_program(ROOM);
}
