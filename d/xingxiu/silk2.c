// Code of ShenZhou
// /d/xingxiu/silk2.c
// Ryu 

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
����һ����ԭ������֮����̵���һ����ɳ��չ���������ǰ��ÿ
һ��ɳ���϶�����һ��֦Ҷï���ĺ���������ȥ����һ�����Դ��С����
�����岼춻�ԭ֮�ϡ��������������ɽ��������������º�����һ��
�������������ԭ��������ͨ������
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
        set("outdoors", "xingxiuhai");

        set("exits", ([
                "east" : __DIR__"silk1",
		"northwest" : __DIR__"silk3",
        ]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

