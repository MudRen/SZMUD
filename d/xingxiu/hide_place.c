// Code of ShenZhou
// wsky, 5/7/00
inherit ROOM;

void create()
{
        set("short", "�µ�");
        set("long", @LONG
���������µף�������ʯ֮���ƺ�ʲôҲû�С�
LONG
        );

        set("exits", ([
             "up" : __DIR__"gcliff",
        ]));

        set("objects", ([
                __DIR__"npc/sangtu"  : 1,
        ]) );

	set("item_desc",([
                "cliff"         :       "һ������ʮ�ֶ��͵����£��ƺ���������ȥ��\n",
        ]));

        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        

}



void init()
{
        add_action("do_climb", "climb");
	add_action("do_climb", "pa");
}	

int do_climb(string arg) {
	if (arg && arg!="up") {
		say("�������Ķ���������\n");
		return 1;
	} else {
                say("���ֽŲ�����������һ�Σ����ڳ����ˡ�\n");
		this_player()->move(__DIR__"gcliff");
		return 1;
	}
}
