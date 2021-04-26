
// 苏梦馨(Athena) 
// Room：/u/athena/chitang.c 

#include <ansi.h>
inherit ROOM;

void create()
{
        set("short",MAG"池塘"NOR);
	set("long", @LONG
一池池水映入你的眼帘，小蓬莱翼然水中，曲折的石桥上架
着紫藤花棚。池东你可以看到曲溪楼、西楼、清风池等小筑，掩
映于花木山石之间。池西的山腰间，桂树丛生。秋日里，置身于
“闻木樨香轩”，阵阵桂香，沁人心脾。轩下，水涧两岸叠石重
重，你不禁为此景而赞叹不已。
LONG	);
        set("exits", ([ 
	"south" : __DIR__"zhibaixuan",
	]));
        set("objects", ([
                __DIR__"obj/rose" : 1,
]));
	set("outdoors", "Sufu" );
	set("no_clean_up", 0);
	setup();
        replace_program(ROOM);
}
