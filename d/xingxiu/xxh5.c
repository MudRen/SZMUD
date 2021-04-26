// Code of ShenZhou
// Room: /d/xingxiu/xxh5.c
// Jay 3/18/96

inherit ROOM;

void create()
{
        set("short", "���޺�");
        set("long", @LONG
���������޺��ľ�ͷ����Ϊ������Ұ���û�����������ɵ��ӳ����ڴ˿����⴮
�ԡ����򲻵�Ұ��ʱ�����Ǿ���ɽ�����˵���
LONG
        );

        switch(random(3)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        case 1:
                set("objects", ([ "/d/xingxiu/npc/spider"   : 1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" :1,
                                  __DIR__"npc/boshou"       : 1,
                                 __DIR__"npc/obj/yangrou.c" : 2]));
                break;
        }       

        set("exits", ([
	     "north" : __DIR__"forest1",	
             "southeast" : __DIR__"xxh3",
             "southwest" : __DIR__"xxh4",
        ]));
 
        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        replace_program(ROOM);

}

