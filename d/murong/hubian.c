// Code of ShenZhou
// Room: /d/murong/hubian
// Date: arthurgu/ 1999.9.1

#include <room.h>
inherit ROOM;

int do_find(string);
int do_wen(string);

void waittime( object ob ) ;

void create()
{
    set("short", "湖边");
    set("long", @LONG
    你走到湖边,前面豁然一个大湖泊(hu),水面光滑如镜。湖边则杏
花夹径,绿柳倒垂。暖洋洋的春风吹在身上,当真是熏熏欲醉。
LONG
    );

    set("exits", ([
        "east" : __DIR__"road1",
    ]));

         set("item_desc", ([
              "hu" :
"    湖面宽阔无比，一眼无边。远远望去，湖中种满了红菱白藕，
微风吹过，绿叶轻摇，煞是动人。藕菱之间，是一条条曲曲的水路，
不知道通向何处。不远的水路间，有一艘小舟(zhou)正慢慢摇近。
",
               "zhou" :
"   小舟虽小，看起来倒也能容纳三、四人。一个绿衫女子(girl)
手执双浆，缓缓划水而来，口中唱着小曲，歌声娇柔无邪，欢悦动心。
",
               "girl" :
"   只见那少女一双纤手皓肤如玉，映着绿波，便如透明一般。约莫
十六七岁年纪，满脸都是温柔，满身尽是秀气。看来要去燕子坞，非
要问问她不可(wen)。
",

                            ]));

      
    
    set("outdoors", "murong");
    setup();

}

void init()
{
    add_action("do_find", "find");
    add_action("do_wen", "wen");
}


int do_find(string arg)
{
	object me;
	object *inv;
	int i;
	me=this_player();

	if (arg=="boat" && me->query("family/family_name")=="姑苏慕容")
	{
			
		inv=all_inventory(me);
		for(i=0; i<sizeof(inv); i++) {
			if (userp(inv[i]))
				return notify_fail("你负重太大了，小舟恐怕载不动你。\n");
		}
		tell_object(me, "你熟门熟路地找到一条小舟，解开绳子，划了起来。\n");
		tell_object(me, "不一会儿，你来到参合庄。\n");
		me->move("/d/murong/zhuang1.c");
		return 1;
	}
	return 0;
}


int do_wen(string arg)
{
    object ob ;
    ob = this_player () ;

    message_vision("你向绿衫女子打听去参合庄的路 \n",ob);
    message_vision("绿衫女子微微一笑道：你既知道参合庄的名字, 想必是本庄故人，让我送你入庄吧。\n",ob);
    message_vision("\n$N跃上小舟，船就划了起来。\n\n" ,ob );
    ob ->move("/d/murong/dahu") ;
    tell_object(ob, "\n小舟在湖中藕菱之间的水路上穿来穿去，你的眼都花了...\n\n" ) ;
    call_out("waittime", 50 , ob );
    return 1 ;
}
void waittime( object ob )
{
  tell_object(ob, "\n小舟终于划到近岸，眼前是一间华丽的大屋。\n\n" ) ;
  ob->move ("/d/murong/qing1") ;
}