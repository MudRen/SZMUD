// Code of ShenZhou
// Ryu 5/10/97
inherit ROOM;

void create()
{
        set("short", "ɽ��");
        set("long", @LONG
��ɽ������ɽ������ɽ����ɽ֮��ʼ�����������ʱ��ɽ������
ɽ����Ϊһ̸����ū�˺����������硱�����������������硱֮��ת��
ֱ���ƴ�����ɽ������ɽ�ű����ֿ�������ɽ�ķ�Χ�ű���ȷ������
���Ź��⣬ֱ�������˺�������������������·��ɽ�����������ɽ
���ɵ����޺�������İ������������ɽ��ء�
LONG
        );
        set("exits", ([
            "northup" : __DIR__"alagou1",
            "eastdown" : __DIR__"tianroad1",
            "westup" : __DIR__"yinshan",
]));

	set("objects", ([
                __DIR__"npc/wu"  : 1,
        ]) );

        set("cost", 3);
        set("resource/grass", 1);
        setup();
        replace_program(ROOM);
        set("outdoors", "xingxiuhai");

}
