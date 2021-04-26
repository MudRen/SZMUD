// Code of ShenZhou
// wsky 5/7/00

inherit ROOM;
inherit F_CLEAN_UP;

void create()
{
        set("short", "����");
        set("long", @LONG
������һ������һ��ƽ�أ�ǰ��ϡϡ�ĳ���Щ��ݣ����������Ե�����������
�ұ��Ѿ�����·�ľ�ͷ����һ������(cliff)���ƺ������ǳ����ա�
LONG
        );
        
        set("exits", ([
             "westdown" : __DIR__"gudao2",
        ]));

	set("item_desc",([
                "cliff"         :       "һ������ʮ�ֶ��͵����£��ƺ���������ȥ��\n",
        ]));


        set("no_clean_up", 0);

        set("outdoors", "xingxiuhai");

        set("cost", 2);
        setup();
        
}

void init() {add_action("do_climb","climb");add_action("do_climb","pa");}

int do_climb(string arg) {
        if (!arg || arg!="down") {
                tell_object(this_player(),"�������Ķ���������\n");
		return 1;
	} else {
                tell_object(this_player(),"���ֽŲ�����������һ�Σ����ڳ����ˡ�\n");
		this_player()->move(__DIR__"hide_place");
		return 1;
	}
}
