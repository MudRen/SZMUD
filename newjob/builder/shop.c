//newjob/builder/
//jiuer 11/2001  ʯ��

inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
����һ�����治���ʯ�̣�������̩ɽ����һ�����ɽ·�Ľ��紦��
�������ͨ������ר�ų��۲�ʯ���ߺ�һЩҽ�˵ĸ�ҩ�������������ǵ�
��������ʯ����ľ���Ϸ������������䣬�󴸣�ըҩ��һЩ��ҩ��
LONG);
        set("objects", ([
                __DIR__"npc/baiquan" : 1,
                ]));
        set("exits", ([
                "east" : __DIR__"hill2",
                ]));
        set("cost", 1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}