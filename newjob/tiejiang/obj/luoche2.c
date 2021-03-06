void set_owner(object owner);
// Code of ShenZhou
// /newjob/tiejiang/obj/luoche2.c 骡车

#include <move.h>
#include <ansi.h>
#include <room.h>
inherit ITEM;

string *address=({"南门"});

mapping default_dirs = ([
		  "north":        "北",
		  "south":        "南",
		  "east":         "东",
		  "west":         "西",
		  "northup":      "北边",
		  "southup":      "南边",
		  "eastup":       "东边",
		  "westup":       "西边",
		  "northdown":    "北边",
		  "southdown":    "南边",
		  "eastdown":     "东边",
		  "westdown":     "西边",
		  "northeast":    "东北",
		  "northwest":    "西北",
		  "southeast":    "东南",
		  "southwest":    "西南",
		  "up":           "上",
		  "down":         "下",
		  "out":          "外",
		  "enter":        "里",
]);



int do_drive(string arg);
int do_open();
int do_check();
int do_unride(string arg);
int do_ride(string arg);
int do_yao();
//int do_attack(string arg);
//int do_rob();
void host_appear();
void destroy_cart(object cart);
void greeting(object ob);
void destroy_it(object ob);
//void do_leave(object ob);
//void robber_rob(object me);
void do_buxuzu(object ppl);
int do_get();

void create()
{
	seteuid(getuid());
	set_name(HIW"骡车"NOR, ({"luo che", "che"}));
	set_weight(50000);
	set_max_encumbrance(700000000);
	if (clonep())
		set_default_object(__FILE__);
	else {
		set("long",
			"这是一辆非常结实的骡车，由两匹大骡子拉着，骡车上竖着一面大旗，上书“神州车行”四个大字。\n");
		set("unit", "辆");
		set("value", 1000000);
	     }
	     
	set("material", "steel");

	set("no_get",1);

	set("no_refresh", 1);
//	remove_call_out("auto_check");
//	call_out("auto_check", 30+random(30) );
    	
}
	int is_container() { return 1; }

void init()
{
	object ob;
	add_action("do_yao", "yao");
	add_action("do_drive", "gan");
	add_action("do_drive", "g");
	add_action("do_ride", "ride");
	add_action("do_ride", "shang");
	add_action("do_unride", "leave");
	add_action("do_get","get");
	
	if( interactive(ob = this_player()) ) {
		 call_out("greeting", 1, ob);
	}
}

int do_get()
{
  if( query("owner") != this_player()->query("id")) return;
  write("OK\n");
  return 1;
}


int do_yao()
{
	if( query("owner") != this_player()->query("id"))return notify_fail("不是你的车。\n"); //判定是否是自己的车。 调试阶段先去除 Troy 2001.12.7
	if (query("yao"))
	{
	switch (MONEY_D->player_pay(this_player(), 200)) 
	{
	case 0:
			write("穷光蛋，一边呆着去！\n");
		break;
	case 2:
		write("您的零钱不够了，银票又没人找得开。\n");
		break;
	default:
	message_vision("$N掏出二两银子给车夫。车夫拿在手里掂了掂，高兴地收了起来。\n", this_player());
	message_vision( HIW"车夫说道：好！我们继续上路吧。\n"NOR,this_player());
	set ("xuzu",1);
	break;
	}
	delete ("yao");
	call_out("buxuzu",0);
	return 1;
}
return 0;
	}



void set_owner(object owner)
{
	object ob = this_object();
	set("owner",owner->query("id"));
	call_out("destroy_it",10,ob);
	delete("xuzu");
// mud time 一天1440
}



int do_ride(string arg)
{
	object me = this_player();
	object cart = this_object();
	if (!arg) return notify_fail("你要上什么？\n");
	if( me->query_temp("rided_luo") )  return notify_fail("你已经在骡车上！\n");
	if( cart = present("luo che",environment()) );
	if( query("owner") != me->query("id"))return notify_fail("不是你的车。\n"); //判定是否是自己的车。
	message_vision(HIY"$N"+HIY"地乘上了骡车，对车夫说道：“我们上路把！”\n"NOR,me);
	me->set_leader(cart ); //跟随玩家。
	me->set_temp("rided_luo",1);  //在车上。
	return 1;
}

int do_unride(string arg)
{
	object me = this_player();
	if( !me->query_temp("rided_luo") )  return notify_fail("你已经不在骡车上！\n");
	message_vision(HIY"$N"+HIY"跳下了骡车，对车夫说道：“请稍等一会！”\n"NOR,me);
	me->delete_temp("rided_luo");
	return 1;
}

void destroy_it( object obj)  
//set_owner 时计算租车时间，到时间再付费or不租了。如果在途中不租了。车内东西就会一起丢失。
{
	object ppl;
	remove_call_out("distroy_it");
	if(!objectp(obj))return;
	if( !obj->query("owner")) return;
	if( obj->query("owner") ) 
	{
		ppl = find_player( obj->query("owner") );
		}

	if( userp(ppl)) //&& ppl->query_temp("rided_luo") )
		{
			message_vision( HIR"车夫停下了车，对$n"+"说：“你租车的时间到了！是否要续租（yao)？\n"NOR,obj,ppl);
		        set("yao",1);
		        //remove_call_out("do_buxuzu");
  		        call_out("do_buxuzu", 15,ppl );  
		}
	
}

void do_buxuzu (object ppl)
	{
		
		object ob = this_object();   
		if (query("xuzu"))
		{
			ob->set_owner(ppl);
			remove_call_out("do_buxuzu");
			delete("xuzu");
		}
		else
		{
		message_vision( HIW"车夫赶着$N"+HIW+"走了，转眼就跑没影了！\n"NOR,ob );
		ppl->delete_temp("rided_luo"); 
		destruct(ob);
		delete("yao");
		}
	}       
                
int do_drive(string arg)
{
        object env, obj, ob, me = this_player(), partner;
        string target_dir, dir, dest, victim;
        mapping exit;
        object here = environment(me),robber = present("robber",here);
        int busy_time;

        if (!arg) return notify_fail("你要驱赶什么？\n");

        if( sscanf(arg, "%s %s", victim, dir) != 2 ) return notify_fail("指令错误！\n");

        if ( victim == me->query("id") ) return notify_fail("何必多此一举？\n");

        if( !me->query_temp("rided_luo") )  return notify_fail("车夫说道：“你又在骡车上！我怎么能赶车？\n");

        if ( victim != "che" && victim != "da che" ) return notify_fail("你要驱赶什么？\n");

        ob = present(victim, environment(me));

        if (!ob) return notify_fail("这里并无此人！\n");

        if ( me->is_busy() ) return notify_fail("你在忙着呢！\n");

        env = environment(me);
        
        
        if( !mapp(exit = env->query("exits")) || undefinedp(exit[dir]) )
                return notify_fail("无此方向可去！\n");
	        dest = exit[dir];

        if( !(obj = find_object(dest)) )
                                         call_other(dest, "???");
                  if( !(obj = find_object(dest)) )
                                         return notify_fail("无法走！\n");
        
        if( !wizardp(ob) && obj->query("short") == "黄金大殿" )
                return notify_fail("无法走！\n");

        if( !undefinedp(default_dirs[dir]) )
                                         target_dir = default_dirs[dir];
                  else
                                         target_dir = dir;

        message_vision( HIG"车夫"+HIG"扬了扬鞭子，高声驱赶骡子驾着$n"+HIG"朝"+target_dir+"驶去。\n" , me, ob);
/*
以下设置列表，随机收费
*/
	if( here->query("short") == "西门" )
	{
		switch(random(2))
		{
		case 1:
			if (query_temp("rided_luo"))
			{
				message_vision( HIG"一名衙役跑了上来，拦住了$n，说道：“快交车马税！”\n" , me, ob);
				return 1;
			}
			else
				message_vision( HIG"一名衙役跑了上来说道：“首长辛苦了！”\n" , me, ob);
				break;
		default:
			break;
		}
	}                                            
/*
以上设置列表，随机收费
Troy 2001.12.21
*/
	switch(random(100))
	{
	case 0:
		me->delete_temp("rided_luo"); 
		message_vision(HIG"对面一匹快马与$N擦肩而过，骡子受了惊吓，挣脱了束缚！\n"NOR,me);
		//if (me->qurey()  是否要测试轻功？
		message_vision(HIW"$N施展轻功飞身一跃拉住缰绳，硬生生的将骡子拽了回来和车夫一起将骡车套好。\n"NOR,me);
		busy_time=10;
		me->start_busy(busy_time);
		break;
	case 1:
		message_vision(HIG"车里的东西都掉了出来。\n"NOR,me);
		break;
	default:  
		message("vision", HIY "只见"+ob->name()+HIY"轰隆隆沉重的向"+target_dir+"驶过去。\n" NOR, environment(ob), ({ob}));
		if( ob->move(obj) )
		{
			message( "vision", HIY "只见一辆"+ob->name()+HIY"轰隆隆沉重的驶了过来。\n" NOR, environment(ob), ({ob}));
			//busy_time = 2 + random(2);
			busy_time=0;
			message_vision( HIG"$N坐在骡车上向"+target_dir+"驶过去。\n" NOR,me);
			me->move(obj);
			message_vision( HIG"$N坐在骡车上驶过来。\n" NOR,me);
			me->start_busy( busy_time );
			all_inventory(env)->follow_me(me,dir);
		}
	break;
	}

        return 1;
}
