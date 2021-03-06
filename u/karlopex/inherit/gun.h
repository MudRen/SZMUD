//Cracked by lisser
//gun.h

#include <ansi.h>
#include <weapon.h>

#ifdef AS_FEATURE
#include <dbase.h>
#else
inherit EQUIP;
#endif

private int shoot_result(object me, object target, string limbs, int str);
mapping limbs = ([
	"zs1":({"头部", "颈部", "胸口", "后心"}),
	"zs2":({"两肋", "左脸", "右脸", "小腹", "腰间"}),
	"qs":({"左肩", "右肩", "左臂", "右臂", "左手", "右手", "左腿", "右腿", "左脚", "右脚", "左耳", "右耳"}),
]);	
mapping default_dirs = ([
        "north":(["z":"北","f":"南"]),
        "south":(["z":"南","f":"北"]),
        "east":(["z":"东","f":"西"]),
        "west":(["z":"西","f":"东"]),
        "northup":(["z":"北","f":"南"]),
        "southup":(["z":"南","f":"北"]),
        "eastup":(["z":"东","f":"西"]),
        "westup":(["z":"西","f":"东"]),
        "northdown":(["z":"北","f":"南"]),
        "southdown":(["z":"南","f":"北"]),
        "eastdown":(["z":"东","f":"西"]),
        "westdown":(["z":"西","f":"东"]),
        "northeast":(["z":"东北","f":"西南"]),
        "northwest":(["z":"西北","f":"东南"]),
        "southeast":(["z":"东南","f":"东南"]),
        "southwest":(["z":"西南","f":"东北"]),
        "up":(["z":"上","f":"下"]),
        "down":(["z":"下","f":"上"]),
        "out":(["z":"外","f":"里"]),
        "enter":(["z":"里","f":"外"]),
]);
private string ffx;
void init()
{
	add_action("do_reload", "reload");
}

varargs void init_gun(int damage, int flag)
{
	if( clonep(this_object()) ) return;

	set("weapon_prop/damage", damage);
	set("flag", flag );
	set("skill_type", "archery");
	if( !query("actions") ) {
		set("actions", (: call_other, WEAPON_D, "query_action" :) );
		set("verbs", ({ "bash", "crush", "slam" }) );
	}
}

int do_reload(string arg)
{
	object me, ob, arrow, load_arrow;
	string str;	

	me = this_player();
	ob = this_object();

	if (!arg || !objectp(arrow = present(arg, me)) ) 
		return notify_fail("你不往枪里装子弹，那你装什么？\n");
	
	if ( arrow->query("weapon_type") != "bullet" )
		return notify_fail("并不是每样物品都可以当子弹用的。\n");
	
	if ( ob->query_temp("arrow_load") == "loaded")
		return notify_fail("你已经装上子弹了。\n");

	load_arrow = new(base_name(arrow));

        if( arrow->query("poison_type") ) {
                ob->set("poison_applied", arrow->query("poison_applied"));
                ob->set("poison_type", arrow->query("poison_type"));
        }

	message_vision("$N将步枪上的空弹匣卸下，将新的$n装上。\n",me, load_arrow);
	
	str = ob->query("org_long")+"上面已经装了一个新的子弹匣，里面有"+chinese_number(load_arrow->query("shu"))+load_arrow->query("unit")+load_arrow->name()+"。\n";
	ob->set("long", str);

	ob->set_temp("arrow_load", "loaded" );
	ob->set_temp("arrow_amount", 10 );        
	if (arrow->query_amount() > 1)
                arrow->add_amount(-1);
        else destruct(arrow);
        add_action("do_pull","miao");
	return 1;
}
	
int do_pull(string arg)
{
        object me, ob, env, env2, *inv;
        string enemy, dir, dest, target, disp, targets = "";
        mapping exit;
        int num, i, j;

        me = this_player();
        ob = this_object();
        env = environment(me);
        
        if( (string)ob->query("equipped")!="wielded" )
                return notify_fail("枪还背在你背上呢。\n");
                
        if (!arg || arg == "" ){
       	        if( objectp(ob->query_temp("pulled")) )
	                return notify_fail("你已经瞄定了"+(ob->query_temp("pulled"))->name()+"。\n");
                return notify_fail("你想往哪里打？\n");
        }else if( sscanf(arg, "%s to %d", dir, num) == 2 ){
		if (dir == "enter" || dir == "out" || dir == "up" || dir == "down" || !default_dirs[dir])
			num = 1;
		else if(num > 5) return notify_fail("距离太远，狙击步枪没有办法看到。\n");;
		env2 = env;
        	for(j=0;j<num;j++)
        	{
			disp = "";
		        if( !mapp(exit = env2->query("exits")) || undefinedp(exit[dir]) ){
				message_vision(HIG "\n只见$N举起$n"+HIG+"向"+target+"方向瞄去！！！\n" NOR,me,ob);
				tell_object(me,HIG"你瞄一下"+target+"方向，发现"+chinese_number(j)+"个房间里有生物。\n"+targets+"\n"NOR);
				return 1;
			}
		        dest = exit[dir];
		        if( !(env2 = find_object(dest)) ){
        			call_other(dest, "???");
				message_vision(HIG "\n只见$N举起$n"+HIG+"向"+target+"方向瞄去！！！\n" NOR,me,ob);
				tell_object(me,HIG"你瞄一下"+target+"方向，发现"+chinese_number(j)+"个房间里有生物。\n"+targets+"\n"NOR);
				return 1;
			}
			if( !default_dirs[dir] )
				 target = env2->query("short");
			else
				 target = default_dirs[dir]["z"];
			inv = all_inventory(env2);
			for(i=0; i<sizeof(inv); i++) {
				if( !inv[i]->is_character() ) continue;
				disp += inv[i]->short(1)+"\n";
			}
			if (sizeof(disp) > 0)
				targets += HIG"第"+chinese_number(j+1)+"个房间："+env2->query("short")+HIG"房间里有以下生物：\n"NOR + disp;
			else targets += HIG"第"+chinese_number(j+1)+"个房间："+env2->query("short")+HIG"房间里没有生物！\n"NOR;
		}        	
		message_vision(HIG "\n只见$N举起$n"+HIG+"向"+target+"方向瞄去！！！\n" NOR,me,ob);
		tell_object(me,HIG"你瞄了一下"+target+"方向，发现"+chinese_number(j)+"个房间里有生物。\n"+targets+"\n"NOR);
		return 1;
        }else{
                if( sscanf(arg, "%s at %s", enemy, dir) != 2 )
	                if( sscanf(arg, "%s", dir) != 1 )
        	        return notify_fail("命令格式: miao <方向> <某人>。\n");

	        if( dir && !enemy ) return notify_fail("你定好姿势，将目标锁定在"+default_dirs[dir]["z"]+"方向。\n");
	        else if( !dir ) return notify_fail("距离太近，发挥不了狙击步枪的威力。");
	        else{
			if (dir == "enter" || dir == "out" || dir == "up" || dir == "down" || !default_dirs[dir])
				num = 1;
			else num = 5;
			env2 = env;
	        	for(j=0;j<num;j++)
	        	{
			        if( !mapp(exit = env2->query("exits")) || undefinedp(exit[dir]) ) {
			                if( query_verb() == "miao")
			                        return notify_fail(env2->query("short")+"没有"+default_dirs[dir]["z"]+"方向的路了，瞄了也没有用。\n");
			                else
			                        return 0;
			        }
			        dest = exit[dir];
			        if( !(env2 = find_object(dest)) ){
                			call_other(dest, "???");
                			return notify_fail("没有这个地方，没办法瞄准。\n");	        		
				}
				if( !default_dirs[dir] )
					 target = env2->query("short");
				else
					 target = default_dirs[dir]["z"];
				inv = all_inventory(env2);
				for(i=0; i<sizeof(inv); i++) {
					if( !inv[i]->is_character() ) continue;
					if( inv[i]->query("id") != enemy ) continue;		
					else{
						ob->set_temp("pulled", inv[i]);
						ob->set_temp("pull-r", env2);
						ob->set_temp("miao-dir", env);
						if (!default_dirs[dir]) ffx = env->query("short");
						else ffx = default_dirs[dir]["f"];
						message_vision(HIG "\n只见$N举起$n"+HIG+"向着"+target+"的方向瞄去！！！\n" NOR,me,ob);
						tell_object(me,HIG"你瞄的是"+inv[i]->name()+"，"+(inv[i]->query("gender")=="女性"?"她":"他")+"目前在"+chinese_number(j + 1)+"步外的"+env2->query("short")+HIG"房间内。\n"NOR);
					        add_action("do_shoot","shoot");
	        				return 1;
					}					
				}
			}
			return notify_fail("你瞄的人不在这几个房间里。\n");
		}
	}
}

int do_shoot()
{
        object me, victim, ob, env, obj, arrow, dest, where;
        string enemy, dir, target, limb, str;
        mapping exit;

        me = this_player();
        ob = this_object();
	victim = ob->query_temp("pulled");
	
        env = environment(me);
	dest = ob->query_temp("pull-r");
         if(!env) return notify_fail("你哪里也射不了。\n");

 	if ( ob->query_temp("arrow_load") != "loaded" )
		return notify_fail("你没有子弹了怎么打？\n");
		
        if( !ob->query_temp("pulled") )
                return notify_fail("你没瞄准怎么打？\n");		

	if(environment(victim) != dest)
		return notify_fail("你的目标已经离开了。\n");
		
	if(env != ob->query_temp("miao-dir"))
		return notify_fail("你的角度已经变了，需要重新瞄准！\n");

	if( ob->query("shoot_msg") )
		message_vision(ob->query("shoot_msg"), me);
	else
		message_vision(HIY"\n$N食指一用力，「嘭」的一声！！！\n" NOR, me);

	ob->delete_temp("miao-dir");
	ob->delete_temp("pull-r");
	tell_object(ob->query_temp("pulled"),HIR "\n你只听见「嘭」的一声，一个小物体激射直奔你而来！！！\n" NOR);
	if ( me->query("qiangfa") > 100 && random(me->query("qiangfa")) > me->query("qiangfa") / 2 ){
		limb = limbs["zs1"][random(sizeof(limbs["zs1"]))];
		shoot_result(me, ob->query_temp("pulled"), limb, 1);
	}else if ( me->query("qiangfa") > 75 && random(me->query("qiangfa")) > me->query("qiangfa") / 4 ){
		limb = limbs["zs2"][random(sizeof(limbs["zs2"]))];
		shoot_result(me, ob->query_temp("pulled"), limb, 2);
	}else limb = limbs["qs"][random(sizeof(limbs["qs"]))];
	ob->delete_temp("pulled");
	ob->add_temp("arrow_amount",-1);
	if (ob->query_temp("arrow_amount") > 0){
		str = ob->query("org_long")+"上面已经装了一个子弹匣，里面还有"+chinese_number(ob->query_temp("arrow_amount"))+"颗步枪子弹。\n";
		ob->set("long", str);
        	remove_action("do_shoot","shoot");
        	add_action("do_pull","miao");
        }else if (present("bullet", me) && me->query("auto_reload_gun") == "auto"){
		str = ob->query("org_long");
		ob->set("long", str);
		ob->delete_temp("arrow_amount");
		ob->set_temp("arrow_load","empty");
        	remove_action("do_shoot","shoot");
        	remove_action("do_pull","miao");        	
        	return do_reload("gun-x");
        }else{
		str = ob->query("org_long")+"上面已经装了一个子弹匣。但是子弹已经打完了。\n";
		ob->set("long", str);
		ob->delete_temp("arrow_amount");
		ob->set_temp("arrow_load","empty");
        	remove_action("do_shoot","shoot");
        	remove_action("do_pull","miao");
	}
	return 1;
}

private int shoot_result(object me, object target, string limbs, int str)
{
	tell_object(target, HIR "\n你已经无法躲闪，只觉得"+limbs+"部位很痛，溅出很多血！\n" NOR);
        message("vision", HIR "\n只听见「嘭」的一声，一颗子弹从"+ffx+"的方向飞来，"+target->name()+"的"+limbs+"被子弹打穿，溅出了很多血！！！\n" NOR,  environment(target), ({target}) );
	tell_object(me, HIR "\n你远远地看见"+target->name()+"的"+limbs+"部位被你打中了！\n" NOR);
	if ( str == 1 ){
		if (getuid(me) == "lisser") tell_object(me,HIR"一枪命中！！！\n"NOR);
		target->receive_damage("qi", target->query("max_qi")*2, "被"+me->name()+"用狙击步枪命中"+limbs+"死亡");
		target->receive_wound("qi", target->query("max_qi")*2, "被"+me->name()+"用狙击步枪命中"+limbs+"死亡");
	}else if ( str == 2  ){
		if (getuid(me) == "lisser") tell_object(me,HIR"命中高伤害部位！！！\n"NOR);
		target->receive_damage("qi", target->query("max_qi")/2, "被"+me->name()+"用狙击步枪杀死了");
		target->receive_wound("qi", target->query("max_qi")/2, "被"+me->name()+"用狙击步枪杀死了");
		if ( me->query("qiangfa") < 500 && random(10) == 5){
			tell_object(me,BLK"你的枪法进步了，但是还有待提高。\n"NOR);
			me->add("qiangfa",random(10));
		}
	}else{
		if (getuid(me) == "lisser") tell_object(me,HIR"未命中要害部位！！！\n"NOR);
		target->receive_damage("qi", target->query("max_qi")/4, "被"+me->name()+"用狙击步枪杀死了");
		target->receive_wound("qi", target->query("max_qi")/4, "被"+me->name()+"用狙击步枪杀死了");
		if ( me->query("qiangfa") < 200 && random(5) == 3){
			tell_object(me,BLK"你的枪法进步了，但是还要继续努力。\n"NOR);
			me->add("qiangfa",random(5));
		}
	}
        return 1;
}

