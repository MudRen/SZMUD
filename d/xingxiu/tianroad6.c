// Code of ShenZhou
// room: /d/xingxiu/tianroad6.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "С��");
        set("long", @LONG
��������ɽ��һ��СС��ɽ�塣����������Χ��ȥ�����׶���ԭ
�ķ�⾡���۵ס�����һ��С·������ɽ��
LONG
        );
        set("exits", ([
            "eastdown" : __DIR__"tianroad5",
	    "southdown" : __DIR__"shangu",
        ]));
        set("objects", ([
               "/d/wudang/npc/snake" : 1, 
        ]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 3);
	set("bing_can", 3);
        setup();
        replace_program(ROOM);
}

