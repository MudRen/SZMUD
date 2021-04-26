//this file was stole by me from other wizs:)
//original crystal.c now baobei.c
#include <ansi.h>
#include <weapon.h>
#include <login.h>
inherit STAFF;
inherit F_SAVE;
inherit F_AUTOLOAD;
//inherit F_DAMAGE;

int query_autoload() { return 1; }

void create()
{
        set_name(YEL"木杖"NOR, ({ "quan zhang","staff","zhang"}) );
        set_weight(20);
        if (clonep())
		set_default_object(__FILE__);
	else
	 {
        set("long", "\t这是一根可以定人生死的木仗，它可以定(ding)，
        踢(kickout)，恢复(heal)，找人(whereis)，醒(wakeup)，晕(hun)，
        去别人家(leadme)，劝架(peace)，变（bian），死（si）
        消灭（mie) 设置（she)。\n");
	set("unit","根");
       set("value", 0);
       set("material", "steel");
       set("wield_msg", HIW"$N抽出一根$n"+HIW+"握在手中，顿时身上发出了道道"+HIY+"金光。\n"NOR);
       set("unwield_msg", HIW"$N将手中的$n放了下来。\n"NOR);
       }
       init_staff(350);
        setup();
}

void init()
{
        object me,ob;
        me =this_player();
        ob=this_object();
        if (this_player()->query("id")!="troy")
        	{
        	message_vision(HIW"天上有一声音说到：“这不是你的东西不能用。”\n"NOR,me);
       		message_vision(HIY"木杖突然消失了。\n"NOR,me);
       		destruct(ob);
       		return 0;
       		}
           else
           {
           add_action("do_kickout","kickout");
       	add_action("do_ding","ding");
       	add_action("do_sou","sou");
       	add_action("do_whereis", "whereis");
       	add_action("do_wakeup", "wakeup");
        add_action("do_bian","bian");
       	add_action("do_hun","hun");
       	add_action("do_peace","peace");
       	add_action("do_heal","heal");
	add_action("do_she","she");
	add_action("do_leadme","leadme");
	add_action("do_si","si");
	add_action("do_huo","huo");
	add_action("do_mie","mie");
	}
       		
}




int do_she(string arg)
{
	if (!arg)
		return notify_fail("你要设置什么？/n");
	if (arg=="hidden")
		{
		message_vision(HIM"$N拿木杖在自己的头上转了一圈，$N突然隐去了身形，消失的无影无踪！\n"NOR,this_player());
		this_player()->set("env/invisibility",1);
		return 1;
		}
	if (arg=="nodie")
		{
		message_vision(HIM"$N拿木杖在自己的头上转了一圈，顿时$N成了不死之身！\n"NOR,this_player());              
		this_player()->set("env/immortal",1);
		return 1;
	}
	return 0;
	}


int do_mie (string item)
{
	object obj;
	object me;
	me=this_player();
	if (!item)
		return notify_fail("你要把谁消灭了？");
	 if(!objectp(obj = present(item, environment(this_player()))))
					 return notify_fail("这里没有这个人。\n");
		  if (!obj) obj = present(item, me);
		  if (!obj) obj = find_object( resolve_path(me->query("cwd"), item) );
		  if (!obj) return notify_fail("没有这样物件....。\n");
	
	message_vision(RED"$N用木杖点了一下"+obj->query("name")+",一股清烟过后什么都没了！\n"NOR,this_player());
	destruct(obj);
	return 1;
	}

int do_huo(string target)
{
	         object deadman = present (target,environment(this_player()));
		  mapping skill_status, learned_status;
		  string *sname;
		  int i,new_exp,skill_amount;
		object me=this_player();
		  if( !target )
					 return notify_fail("你想要救谁的命？\n");
		  if( me->is_fighting() || me->is_busy() )
					 return notify_fail("你正忙着呢！\n");
		
		if ( !deadman->is_ghost() )
			return notify_fail(deadman->query("name")+"已经活过来了,用不着你救。\n");
                        		
                message_vision( HIY"$N轻轻一挥木杖，"+deadman->query("name")+"奇迹般的活了过来，武功尽复！\n"NOR, me);
	           
                		deadman->reincarnate();
                		learned_status = deadman->query_learned();
                		if ( mapp(skill_status = deadman->query_skills()) )
                		{
                        		sname = keys(skill_status);
                        		for(i=0; i<sizeof(skill_status); i++) 
                        		{
                                		skill_amount = (skill_status[sname[i]]+1) * (skill_status[sname[i]]+1) / 2;
		                                if( !mapp(learned_status) ) learned_status = ([ sname[i] : skill_amount ]);
                     			           else {
                                        			if( learned_status[sname[i]]  < skill_amount )
                                                			learned_status[sname[i]] += skill_amount;
                                        			else {
                                                			learned_status[sname[i]] -= skill_amount;                                                                    - (skill_status[sname[i]]) * (skill_status[sname[i]]);
                                                			deadman->set_skill(sname[i], skill_status[sname[i]]+1);
                                        				}
                                			}
                        		}
                		}

                		new_exp = (int)deadman->query("combat_exp") / 99;
                		new_exp = new_exp > 5000 ? 5000 : new_exp;
                		deadman->add("combat_exp", new_exp);
                		deadman->set("qi",1000); 
                		deadman->set("eff_qi",1000); 
                		deadman->set("jing",1000); 
                		deadman->set("eff_jing",1000); 
                		deadman->set("jingli",1000); 
                		deadman->add("death_count", -1);
                		deadman->add("death_times",-1);
		           	deadman->move(environment(me));
           			return 1;       
        }
	

int do_si(string arg)
{
	
       object obj = present (arg,environment(this_player()));
       if (!arg)
       	return notify_fail("你想搞死谁");
       if (this_player()->query("id")!="troy")
       return notify_fail(HIW"你没有这个权力!\n"NOR);
	obj->delete("env/invisibility");
	obj->delete("env/immortal"); 
	obj->die();
	write(HIC"肇事者已经被处以极刑了!\n"NOR); 
	tell_object(obj,RED"你去死吧!\n"NOR);
	return 1; 
}

int do_bian(string arg)
{
     	int amount;
     	object gold;
     	if (!arg)
     	 	return notify_fail("你想变什么？\n");
     	if( !arg || sscanf(arg, "%d gold", amount) != 1 )
                return notify_fail("你会变吗？\n");
     	gold=new("/clone/money/gold");
	gold->set_amount(amount);
	gold->move(this_player());
	message_vision(HIY"$N变出了一些黄金~！\n"NOR,this_player());
	return 1;
	}

int do_hun(string arg)
{
        object me, obj;
        int flag=0;
        if( !arg )
                return notify_fail("你想弄昏谁？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        message_vision(HIR"$N拿出一根木杖，把$n打得昏了过去。\n"NOR,this_player(),obj);
        if (obj->query("env/immortal"))  
            flag=1; 
        obj->delete("env/immortal"); 
        obj->unconcious();    
        if (flag) obj->set("env/immortal",1); 
        return 1;
}

int do_whereis(string arg)
{
  object where, me;
  object *ob;
  string msg;
  int i;

  me = this_player();
  if (arg) {
        if (find_player(arg))
    where = environment(find_player(arg));
    if (!where) return notify_fail ("他在虚无飘藐间。\n");
        "/cmds/std/look"->look_room(me, where);
        return 1;
  }
  else {
    ob = users();
    msg = "";
    for(i=0; i<sizeof(ob); i++) {
      where = environment(ob[i]);
      if (!where)
        msg = sprintf("%s%14s(%-10s) %s\n",
                       msg, ob[i]->name(1), ob[i]->query("id"),
                       "??????????");
      else
        msg = sprintf("%s%14s(%-10s) %s\n",
                       msg, ob[i]->name(1), ob[i]->query("id"),
                       file_name(where));
      }
  }
  write (msg);
  return 1;
}


int do_wakeup(string arg)
{
        object me, obj;

        me = this_player();

        if( !arg )
                return notify_fail("你想弄醒谁？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        message_vision(HIR"$N一巴掌向$n煽过去，$n啊呀一声醒了。\n"
NOR,this_player(),obj);
	obj->revive();   
	return 1;
}

int do_kickout(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("你想把谁踢走？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
        if(obj == this_player())
                return notify_fail("踢自己？有病！\n");
        message_vision(CYN"$N飞起一脚，正好踢中$n的屁股。\n"
NOR,this_player(),obj);
        obj->move("/d/death/block");    
        return 1;
}

int do_ding(string arg)
{
        object me, obj;


        if( !arg )
                return notify_fail("你想定谁？\n");
        if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
        if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");

        if(obj == this_player())
                return notify_fail("用 suicide 指令会比较快:P。\n");
        message_vision(HIY"$N手一指，正好点中$n的膻中穴，$n顿时动弹不得。\n"
NOR,this_player(),obj);
        obj->start_busy(200);    
        return 1;
}

int do_sou(string arg)
{
        object me, obj,env;
        string from,item;

        me=this_player();

        if( !arg ) return notify_fail("你要什么东西？\n");

        if( !sscanf(arg, "%s from %s", item, from)==2 )
               return notify_fail("这偷来的东西不是这样用的！\n");

        if(!objectp(env = present(from, environment(me))))
              return notify_fail("这里没有这个人。\n");

        if(!objectp(obj = present(item,env)))
           return notify_fail(env->query("name")+"没有这样东西。\n");
        obj->move(me);
        message_vision(HIY"\n$N一伸手，〖唰〗的一声把$n从袖里拿出了"+obj->query("name")
                       +"。\n"NOR,this_player(),env);
        return 1;
}


int do_leadme(string arg)
{
        object me, obj;

        if( !arg )
                return notify_fail("去哪里？\n");
        
        if( file_size("/u/"+arg + "/workroom.c") <= 0 )
                return notify_fail("此人homeless!\n");

         if (this_player()->move("/u/"+arg+"/workroom") )
             
            message_vision(HIC"\n$N大叫一声，朋友，我来了！\n"NOR,
                       this_player());

            else tell_object(this_player(),"此人homeless!\n");
         
       return 1;
}



int do_peace(string arg) {
       object me,obj;
       me=this_player();
       if (!arg) return notify_fail("谁？\n");
       if(!objectp(obj = present(arg, environment(this_player()))))
                return notify_fail("这里没有这个人。\n");
       if(!me->is_fighting(obj))
                return notify_fail("你们没在打架！\n");

       me->remove_killer(obj);
       me->remove_enemy(obj);
       obj->remove_killer(me);
       obj->remove_enemy(me);
       message_vision(HIG"$N连连摆手，对$n说：“别打了嘛。。”\n"NOR,
                       me,obj);

       return 1;
}

int do_heal(string arg) {
      object obj;
      
      if (!arg) obj=this_player();
         else if (!objectp(obj = present(arg, environment(this_player()))))
                     return notify_fail("这里没有这个人。\n");  
      if( !obj->is_character() || obj->is_corpse() )
                return notify_fail("看清楚一点，那并不是活物。\n");
     message_vision(HIM"$N运起回阳神功，只见一道红光，罩在$N身上。\n"NOR,obj);
     if( obj->is_ghost() )
     {
         obj->reincarnate();
         message_vision(HIB"三魂六魄重新回到$N体内。\n",obj);
     }
      
      if (obj->query("id")=="dca") obj->set("max_qi",99999);
        obj->set("qi",(int)obj->query("max_qi"));
        obj->set("eff_qi",(int)obj->query("max_qi"));
        obj->set("jing",(int)obj->query("max_jing"));
        obj->set("eff_jing",(int)obj->query("max_jing"));
	obj->set("jingli",(int)obj->query("max_jing"));
        obj->set("eff_jingli",(int)obj->query("max_jing"));
        obj->set("neili", (int)obj->query("max_neili"));
        obj->clear_condition();
               
     message_vision(HIM"$N马上浑身充满了力量！\n"NOR,obj);              
     return 1;
}
