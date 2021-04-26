//room:/u/piao/workroom.c
//piao 2001/09/15
#include <ansi.h>
#include <room.h>
inherit ROOM;

int do_kill(string arg);
int do_zhengli(string arg);
int do_job(int stage);
void do_end();
void create()
{
	set("short","黑白工作室");
	set("long",@LONG
这是飘的工作室，屋子当中摆着一张檀木办公桌、一条大滕椅，办公
桌上放着一台电脑。东面靠墙正中是一个玻璃柜子，里面陈列着飘曾经获
得的各种荣誉证书；柜子两边是书架，架上放着笔记、小说、诗文集之类
的古书。
LONG
	);
	set("no_fight",1);
	set("no_steal",1);
	set("valid_startroom",1);
/*
	set("objects",([
		__DIR__"xiaoyue":1,
		__DIR__"xianger":1,
	]));
*/
        
         set("exits",([
                "gm":"/d/gumu/dating",
                "down":"/d/wizard/wizard_room",
       		"quest":"/d/wizard/quest_r",
		"guide":"/d/wizard/guide_r",
	 ]));
        set("valid_startroom", 1);
        set("no_clean_up",0);
        setup();
        call_other("/clone/board/piao_b","???");
}


void init()
{	
	add_action("do_kill","kill");
	add_action("do_zhengli","zhengli");
	
}
int do_kill(string arg)
{	
	object me = this_player();
	tell_object(me,"别捣乱，这忙着哪。\n");
	return 1;

}


int do_zhengli(string arg)
{
	object me,ob;
	me = this_player();
	
	if (!me->query_temp("job"))
		return notify_fail("怎么好意思劳驾您来整理房间呢。\n");
	if(!arg||arg!="room")
		return notify_fail("你要整理什么呀？\n");
	if(!(ob = present("laji dai", this_player())))
		return notify_fail("你用什么整理房间呀？\n");

	if((int)me->query("jingli")<20)
		return notify_fail("你太累了，休息一下吧。\n");
	if (me->query_busy()>0)
		return notify_fail("你还忙着呢。\n");	
		message_vision(CYN"$N认真聆听书僮分配今天要完成的工作任务。\n"NOR,me);
		me->start_busy(2);
		remove_call_out("do_job");
		call_out("do_job",2,0,me);
		return 1;
}
int do_job(int stage)
{
	int bug;
	object me,gd,ob;
	me = this_player();
	
  	if (stage<0||!objectp(me)) return 1;
	bug = 0;
	switch (stage)
	{
		case 0: bug=1;
			message_vision(CYN"$N拿起扫帚，开始打扫工作室的地板。\n"NOR,me);
			break;
		case 1: bug=1;
			message_vision(CYN"$N从水桶里拿出抹布，拧了几下，开始抹擦桌子和电脑上的灰尘。\n"NOR,me);
			break;
		case 2: bug=1;
			message_vision(CYN"$N开始整理书架上的书籍。\n"NOR,me);
			break;
		case 3: if(!random(2))  
			{
				bug = 1;
				message_vision(HIY"金子！$N连忙把它捡了起来。\n"NOR,me);
				gd=new("clone/money/gold");
				gd->move(me);
			}
			else
			{
				bug = 0;
				message_vision(HIY"哇，蟑螂！$N连忙用必扑一喷,消灭了一只蟑螂！\n"NOR,me);
			}
			break;		
		case 4: bug =1;
			message_vision(CYN"$N把地上的脏东西都装进垃圾袋，终于把房间整理好了。\n"NOR,me);
			ob = present("laji dai",me);
			ob->set_name("垃圾袋",({"lajidai"}));
			ob->set("long","一只黑色的垃圾袋，里面装了不少垃圾。\n");
			break;
	}
	if (stage == 4)
	{
		me->start_busy(2);
		remove_call_out("do_end");
		call_out("do_end",2,0,me);
		return 1;
	}
	if (bug == 1) 
		stage++;
		call_out("do_job",10,stage,me);
		me->start_busy(10);
		return 1;
	
}
void do_end()
{
	object me;
	me = this_player();
	message_vision(CYN"$N伸了伸懒腰，看来可以把垃圾袋交给了香儿交差了。\n"NOR,me);
 	me->set_temp("zljob",4);
 	return;
}
