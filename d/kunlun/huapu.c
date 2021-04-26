//huapu.c (kunlun) 
inherit ROOM;
int do_pull(string arg);
void create()
{
        set("short", "花圃");
        set("long", @LONG
这里是一个美丽而幽静的花园，园子里面种满了鲜艳且古怪的鲜花，白雪
红花、绿叶，构成一幅鲜艳且鬼魅的图画。
LONG
        );
        set("outdoors", "huapu");
        set("exits", ([
           "north" : __DIR__"tieqinju",
        ]));
        set("item_desc", ([
    "鲜花" : "    这花开放时有檀香之气，花朵的颜色又极娇艳。其茎如球，颜色火红。极
象是从西域传来的灵脂兰。\n",
    "flower" : "    这花开放时有檀香之气，花朵的颜色又极娇艳。其茎如球，颜色火红。极
象是从西域传来的灵脂兰。\n",
        ]));
        setup();
        set("flower",1);
}
void init()
{
        add_action("do_pull", "pull");
}
int do_pull(string arg)
{
        object me,ob;
        me = this_player();
        if (!arg )
                return notify_fail("你要拔什么？\n");
          if ( arg != "灵脂兰" && arg != "flower" )
                return notify_fail("你要拔什么？\n");
        if( (int)query("flower") ){
                ob=new(__DIR__"obj/lingzhiflower");
                  message_vision("$N拔出一"+ob->query("unit")+ob->query("name")+"。\n",me);
                if (!ob->move(me))
                        ob->move(environment(me));
                delete("flower");
                delete("item_desc");
                return 1;
        }
          return notify_fail("这里的灵脂兰被拔光了。\n");
}
