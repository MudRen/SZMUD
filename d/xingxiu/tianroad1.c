// Code of ShenZhou
// room: /d/xingxiu/tianroad1.c
// Jay 3/18/96
// Ryu 5/10/97

inherit ROOM;

void create()
{
        set("short", "����");
        set("long", @long
������ɳĮ�е�һ�����ޣ��Ӵ����ϾͿ��Ե������޺���        	
�˴�����������ƽ�ͣ�ʵ�������޵��ӳ����ڴ����ط��ߣ�����
���ò�����  	
long);
        set("exits", ([
            "westup" : __DIR__"shankou",
            "east" : __DIR__"shanjiao",
	]));
        set("objects", ([
                __DIR__"npc/boshou" : 1,
        ]));
        set("resource/grass", 1);
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 3);
        setup();
        replace_program(ROOM);
}
