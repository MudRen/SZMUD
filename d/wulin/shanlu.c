// room /d/wulin/shanlu.c
//updated by Lara 2001/10/17
inherit ROOM;

void create()
{
        set("short", "ɽ·");
        set("long", @LONG
��������һ�����۵�ɽ·��·�߳����˻��ݣ������г��������˵���
�㣬��ʱ���к������۷�������ǰ����ɹ���������ʱ�����˵�ɽ��ƣ
�͡������ǽ���Ȫ�������������͵��������ˡ�
LONG
        );

        set("exits", ([
                "southdown" : __DIR__"longyin",
                "northup" : __DIR__"shangwu",
                "east" : __DIR__"jianquan",
        ]));     

        set("no_clean_up", 0);        
        set("cost", 1);
        setup();
}








