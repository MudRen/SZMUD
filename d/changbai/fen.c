//chchong by fen.c
// Room: /d/changbai/fen.c
//chchong 2001/08/31

inherit ROOM;

void create()
{
        set("short", "坟墓");
        set("long", @LONG
    这里是一座坟墓，看起来好长时间没有人来过这里，仔细看才能看到
原来墓碑被长草(cao) 挡住了。这时你听到长草丛中传来嘶嘶沙沙的声音，好
象有什么东西在向你悄悄移来。
LONG
        );
	set("item_desc", ([
		"cao"   : "在杂草的后面好象隐藏着什么东西，看起来草可以用来拔(ba cao)。\n",
		]));
        set("exits", ([
  "northup" : __DIR__"yuzf",
]));
       set("objects", ([
                "/d/xingxiu/npc/jumang" : 1,
        ]) );
      set("no_clean_up", 0);
        set("outdoors", "changbai");
        set("cost", 1);
        setup();
}

void init()
{
        add_action("do_ba","ba");
}
 
int do_ba(string arg)
{
        object ob, me = this_player();
        if( !arg || arg=="" ) return 0;
        if( arg=="cao" ) 
        {
                ob = new("/clone/weapon/lengyue");
        if (!ob)
           return notify_fail("你拨开杂草，发现这里似乎有人来过了。\n");
           

//      ob->move("/d/changbai/fen");
        ob->move(me);

                write("你拨开杂草，发现下面有一把宝刀。\n");
           CHANNEL_D->do_channel(me, "rumor", sprintf("%s弄到了一把冷月刀。", me->query("name")));

// command ("rumor "+me->query("name")+"弄到了一把冷月刀。");
        return 1;        }
}
