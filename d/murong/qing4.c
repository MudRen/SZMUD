// Code of ShenZhou
// Room: /d/murong/qing4
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "内厅");
	set("long", @LONG
    这间客厅是慕容门下弟子专用的会客厅。慕容氏先辈为大燕国的
国君，故门下不乏高人。大燕亡国后，慕容氏虽混迹江湖，但复国之梦
未灭。门下弟子也频频出现于江湖。
LONG
	);
	set("cost", 1);
	set("exits", ([ 
        "south" : __DIR__"qing3",
        "north" : __DIR__"qing5",
                      ]));
	set("no_clean_up", 0);
        set("valid_startroom",1);
       
        set("objects", ([
		"/kungfu/class/murong/baichuan" : 1,
		]));

	setup();

        "/clone/board/murong_b"->foo();
}
