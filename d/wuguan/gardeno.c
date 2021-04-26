//Created by Zyu on k1-08-13
// gardeno.c 花园外

inherit ROOM;

void create()
{
        set("short", "花园外");
	set("long", @LONG
这里往南去是武馆的花园，面积甚大。东面是武馆的大门，大弟子多
半时候都在那儿解疑。西面是武馆前厅，武馆的大部分都得通过前厅才能
走到。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
            "west" : __DIR__"qianting",
            "east" : __DIR__"damen",
	    "south" : __DIR__"garden",	
        ]));

        set("no_clean_up", 0);
	set("no_steal", 1);
	set("sleep_room", 0);
        set("outdoors", "city" );

	set("cost", 1);
        setup();

}
