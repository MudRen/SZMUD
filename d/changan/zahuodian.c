//Created by RoomEditer on 02-1-3.
//by bravo
inherit ROOM;

void create()
{
	set("short","杂货店");
	set("long",@LONG
这是一家小小的杂货铺，大箱小箱堆满了一地，都是一些日常用品。掌柜
懒洋洋地躺在一只躺椅上，招呼着过往行人。据说私底下他也卖一些贵重的东
西。摊上立着一块招牌(zhaopai)。
LONG
	);
        set("item_desc", ([
                "zhaopai": "请用 \"list\" 列出货物表，\"buy\" 向小贩购物。\n",
       ]));
	set("exits",([

                "west" : __DIR__"sroad3",
	]));
          set("objects", ([
             __DIR__"npc/xiao-fan": 1,
          ]));

          set("cost", 0);

	setup();
}
