
inherit ROOM;

void create()
{
	set("short", "密道");
	set("long", @LONG
你走着走着，突然发现你迷失了方向，你往回走的时候却发现那已不
是你来的道路了，你不禁心中一阵发麻。突然你在昏黄的灯光下，隐约发
现两边的汉白玉墙壁上刻着一些奇形怪状的符号(fuhao)。
LONG
	);
        set("item_desc",([
                        "fuhao" : "
这石室璧上所刻怪异符号的尽是灵鹫宫武功心得。
\n"]));
	set("exits", ([
		"south" : __FILE__,
		"north" : __DIR__"midao6",
		"east" : __DIR__"midao13",
		"west" : __DIR__"midao14",
	]));
	setup();
}
#include "/d/lingjiu/midao.h"