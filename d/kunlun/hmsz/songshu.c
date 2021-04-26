// songshu.c (kunlun)

inherit ROOM;

void create()
{
        set("short", "松树");
        set("long", @LONG
这是一棵长在悬崖上的松树，树上枝密叶茂，树干上长满青苔。松树右侧的悬崖有一突台(tai)，下面是深不见底的山谷。
LONG
        );
        set("cost", 2);
        setup();
}
void init()
{
        add_action("do_climb", "climb");
}
int do_climb(string arg)
{
        object me;
        me = this_player();

        if( !arg || arg=="" )
                return 0;
        if( arg=="tai")
        {
        if (me->query_skill("dodge") < 40){
                    write("你试图攀上突台，无奈身法不够敏捷，只好做罢。\n");
                return 1;
                }
                else {
                    write("你一纵身顺着松树爬上了突台。\n");
                    message("vision",
                             me->name() + "一纵身顺着松树攀了上去。\n",
                             environment(me), ({me}) );
//me->move( __DIR__"tutai" ); // where is tutai? mariner
                    message("vision",
                             me->name() + "从下面爬了上来。\n",
                             environment(me), ({me}) );
                return 1;
         }
     }
}
