// Code of ShenZhou
inherit ROOM;




void create()
{
        set("short", "拈花寺");
        set("long", @LONG
一座小小的古庙，此庙地处偏僻，无甚香火。一声声叮叮清
响悠悠从后院传出，你只感遍体清凉，意静神闲。
LONG
        );

        set("objects",([
                "/d/dali/npc/xiao-ku" : 2
        ]));

        set("cost", 1);
	 setup();
}
int valid_leave(object me, string dir)
{
        if( !present("xin", me) )
                return 
notify_fail("小沙弥上前一步说道：情勿打扰大师清修！\n");

        return ::valid_leave(me, dir);
}


