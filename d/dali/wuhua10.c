// Code of ShenZhou
//cyz /12/13/96
inherit ROOM;

void create()
{
        set("short", "小亭");
        set("long", @LONG
这是一个七角小亭，亭子前面就是临方池。临方池方圆十二
里，白石砌成，水深五丈四尺，鱼鳖悉有，是给五华楼里的贵宾
们垂钓享乐所修。
LONG
        );

        setup();
        replace_program(ROOM);
}

