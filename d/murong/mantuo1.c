// Code of ShenZhou
// Room: /d/murong/mantuo1
//arthurgu /1999.9

inherit ROOM;

void create()
{
	set("short", "曼陀山庄");
	set("long", @LONG
    一眼望去，都是红白缤纷的茶花，不见房屋。信步观赏，
只见花林中除山茶外更无别样花卉，连最常见的牵牛花、月
月红、蔷薇之类也是一朵全无。
LONG
	);
	set("cost", 1);
	set("outdoors", "murong");
	set("exits", ([ 
        "south" : __DIR__"mantuo1",
                      ]));
	set("no_clean_up", 0);
        set("objects", ([
		"/d/murong/npc/ychao" : 1,
		]));

	setup();
}

void init()
{
        add_action("do_go", "back");
}

int do_go(string arg)
{
        object me;
        me = this_player () ;

       if ( !arg || ( arg != "zhuang" ) )
                return notify_fail("什么？\n");
        
       if ( (int)me->query_skill("dodge", 1) < 120)
           return notify_fail("\n你功力不够,不能走木桩\n");

     else if ( (int)me->query_skill("dodge", 1) >= 120)
       { me ->move("/d/murong/qing1");
       tell_object(me, "\n你健步如飞，不一会就回到燕子坞...\n\n" ) ;
        return 1 ;
        }
    
     
}