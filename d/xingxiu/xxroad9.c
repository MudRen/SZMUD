// Code of ShenZhou
// Room: /d/xingxiu/xxroad9.c

inherit ROOM;

void create()
{
        set("short", "ɽ��ĵ�");
        set("long", @LONG
��վ����ɽ��Ļĵ��ϣ�������ȥ�����ǿ����ܲݣ�˷����ɱ�����ó�����
��������������һƬƽ�أ����߽���ɽ�����
LONG
        );
	switch(random(4)){
        case 0:
                set("objects", ([ "/d/xingxiu/npc/scorpion" : 1]));
                break;
        case 1:
        case 3:
                set("objects", ([ "/d/xingxiu/npc/spider" : 1]));
                break;
        case 2:
                set("objects", ([ "/d/xingxiu/npc/centipede" : 1]));
                break;
	}

        set("exits", ([
  "northdown" : __DIR__"xxroad10",
  "eastup" : __DIR__"xxroad6",
]));

        set("no_clean_up", 0);
        set("outdoors", "xingxiuhai");

	set("cost", 2);
	set("bing_can", 20);
        setup();
        replace_program(ROOM);
}
