// Code of ShenZhou
// Room: /d/dali/chhill1.c

inherit ROOM;

void create()
{
	set("short", "茶花山");
	set("long", @LONG
你走在茶花山上，这里遍地是生长茂盛的茶花。当然，大部
分是凡品，但偶尔也会有一两株佳品藏匿其中。北望不远是大理
城的西门，东边不远是城墙。
LONG
	);
	set("objects", ([
		__DIR__"obj/chahua" : 1,

		]));

	set("cost", 2);
	set("no_clean_up", 0);
	set("outdoors", "dali");
	set("exits", ([
		"south" : __DIR__"chhill2.c",
		"westdown" : __DIR__"chhill",
		"east" : __DIR__"chhill3.c",
		"north" : __DIR__"chhill4.c",
		]));

	setup();
}
void init()
{
        add_action("do_get","get");
}

int do_get(string arg)
{
        object me, ob, weapon;
        me=this_player();

        if (arg=="cha" || arg=="all" || arg=="cha hua") {
                if (!objectp(ob=present("cha", environment(me)))) {
                        tell_object(me, 
"这里没什么好品种的茶花值得挖走。\n");
                        return 1;
                }
                if (!objectp(weapon=me->query_temp("weapon"))
                        || weapon->query("id")!="huachu") {
                       tell_object(me, "你没有称手的工具来移植这株茶花！\n");
                        return 1;
                }
                if (random(2)==1) {
                        
message_vision("$N小心翼翼地用花锄掘出茶花的根，把整株茶花移了起来。\n", me);
                        ob->move(me);
                }
                else {
                        
message_vision("$N急急忙忙地挖茶花，一不小心把根挖断了，好好的一株茶花，完了。\n", me);
                        destruct(ob);
                }
                return 1;
        }
        return 0;
}

