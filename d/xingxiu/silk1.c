// Code of ShenZhou
// /d/xingxiu/silk1.c
// Ryu  

inherit ROOM;

void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
�����Ƿ�ɳ������˿��֮·��һƬ�������󡣿������м��˺ϱ�֮
�ֵĹ��Ϻ����ȻЦӭ��ɳ��ͦ���ڻ�ԭ�ϣ�Ϊ����ָ�����򡣶���
һ����ɫ�ĸ�ɽ��ɽ����·�򶫿��������أ�������ͨ������
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
                "east" : "/d/qilian/danshan",
		"west" : __DIR__"silk2",
        ]));

	set("cost", 2);
        setup();
        replace_program(ROOM);
}

