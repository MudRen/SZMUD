// Code of ShenZhou
// lake.c


inherit ROOM;

void create()
{
        set("short", "��ɽ����");
        set("long", @LONG
��������Դͷ�ڵ��Ƹ߾��Ŀ��۰��ڸ����������и�ɽ��������
������ʱ���ߵ�ѩˮ���������ڲ�Զ���ֿ�����������ˮ���ˡ�վ��
ɽͷ�����ع�����������ؾͿ���ӳ�������ˡ�
LONG
        );

	switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
        }

        set("exits", ([
                "eastup" : __DIR__"gudao1",
                "southdown" : __DIR__"alagou2",
        ]));
        set("resource/water",1);
     set("fjing", 1);
        set("outdoors","tianshan");
        set("cost", 2);
        setup();
        replace_program(ROOM);
}

