// Code of ShenZhou

inherit ROOM;

void create()
{
        set("short", "故事房");
        set("long", @LONG
养猫专家和其他的人常常在这儿讲故事。
LONG
        );
        set("exits", ([
 "out" : "/d/city/kedian",
       ]));
setup();
}
