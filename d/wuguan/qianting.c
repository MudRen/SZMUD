//Modified by Zyu on k1-08-13
// qianting.c

inherit ROOM;
#include <ansi.h>

void create()
{
        set("short", "前厅");
        set("long", @LONG
这里是馆主接纳前来投师子弟的地方。摆设甚是不俗。东西两排各摆
着两张檀木坐椅和茶几，正中馆主座位之后摆放一扇玉石雕钻的屏风，上
刻着一龙一虎，威猛之极，墙上几幅风水，小篆标注了武馆的地图(map)。
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
            "west" : __DIR__"zoulang1",
            "east" : __DIR__"gardeno",
            "south" : __DIR__"shufang",
        ]));

        set("no_clean_up", 0);
        set("no_steal", 1);
        set("sleep_room", 0);
        set("valid_startroom",1);

        set("cost", 1);
        setup();

//      "/clone/board/wuguan_b"->foo();
}

void init()
{
        object me = this_player();

        add_action("help_map", "help");
        add_action("look_map", "look");
}

int help_map(string arg)
{
        object me = this_player();

        if ( !arg || arg=="" ) return 0;

        if ( arg!="map" ) return 0;

        tell_object(me,"你可以用 look map 指令来浏览武馆的地图。\n");

        return 1;
}

int look_map(string arg)
{
        object me = this_player();

        if ( !arg || arg=="" ) return 0;

        if ( arg!="map" ) return 0;

        tell_object(me,
                 HIC"\t\t\t武馆地图\n\n"NOR
                +"         密室 \n"   
                +"           %\n"
                +"       练功室 静修室        武馆后山\n"
                +"           | /              /\n"
                +"  厨房---走廊  装备房  后山小路  请教间\n"
                +"           |      |      |       /\n"
                +"休息室---后厅---走廊---正厅---走廊---前厅---花园外---大门\n"
                +"          |       |            /               |\n"
                +"  内厅---走廊  医疗室     请教室             花园---花园深处\n"
                +"          ＼                                           /\n"
                +"       试功房                                      温室\n\n"
        );

        return 1;
}
