// Room: /d/taishan/.c
// Updated by Piao 2001/10/16
#include <ansi.h>
inherit ROOM;
int bow_statue(object me);
void create()
{
	set("short", "封禅台");
	set("long", @LONG
如今这里是推选天下武林总盟主之处，各路英雄如能技压群雄，
比武夺魁，便能问鼎盟主宝座，成为统领中原武林的领袖。高台上
摆放着汉白玉宝座，盟主便在此坐堂议事。台上高高立着一竿旗，
上书：替天行道 四个大字。 盟主左右各侍立着两位白衣武士，两
边都放着一长排虎皮交椅，时常有武林前辈高手前来参见盟主，最
近，这里树立了一个前代英雄的雕像(statue)。
LONG
	);

	set("exits", ([
		"down" : __DIR__"yuhuang",
		"southwest" : __DIR__"fengchansw",
		"southeast" : __DIR__"fengchanse",
		"northwest" : __DIR__"fengchannw",
		"northeast" : __DIR__"fengchanne",
	]));

	set("objects",([
		"/clone/npc/meng-zhu" : 1,
		__DIR__"npc/wei-shi1" : 4,
	]));

        set("no_clean_up", 1);
	set("outdoors", "taishan");
        set("item_desc", ([
              "statue" : "一座威武的雕像，你可以试着朝它鞠躬(bow)。\n",
             
 ]));
	set("cost", 2);
	setup();
}

void init()
{       
	object ob;	
	add_action("do_bow","bow");
	if( objectp( ob = present("mengzhu 2", this_object()) ) )
	destruct(ob);
}

//add_action("do_bow", "bow");
int do_bow(string arg)
{
	object room;
	object me = this_player();
	if ((int)me->query("combat_exp")<100000) return notify_fail(CYN"你虔诚的向雕像鞠了个躬！\n"NOR);
        if (!arg||arg!="statue") return notify_fail(CYN"你虔诚的向雕像鞠了个躬！\n"NOR);
   
        message_vision(CYN"$N恭恭敬敬的向雕像鞠了个躬。\n\n"
                   "突然有个蒙面人拉住$N向雕像旁边的秘密山洞走去。\n\n"NOR,me); 
        me->move("/d/wulin/shanmen") ;
        tell_object(me,CYN"你在黑暗中转了几个弯，不知不觉到了武林同盟山门。\n"NOR);
   
        return 1;
}
