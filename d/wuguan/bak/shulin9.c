//Created by RoomEditer on 01-8-11.
inherit ROOM;

void create()
{
        set("short","树林");
        set("long",@LONG
这是位于武馆后山的一片大树林，生得颇为茂盛．繁茂的枝叶几乎遮
住了所有的光线，地上还铺着一层厚厚的枯枝落叶．林中不时地传来风吹
树叶所发出的＂沙沙＂声．忽然，一群受惊的麻雀＂扑楞楞＂在你身边飞
起，把你惊出了一身冷汗．
LONG
        );
        set("exits",([
		"south" : __DIR__"shulin"+(random(2)),
		"north" : __DIR__"shulin"+(random(9)),
		"east" : __DIR__"houshan",
		"west" : __DIR__"shulin"+(random(5)),
        ]));
        setup();
}



